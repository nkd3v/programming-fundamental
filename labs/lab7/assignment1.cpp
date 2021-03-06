#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

void draw_bullet(int x, int y) {
    gotoxy(x, y);
    printf("^");
}

void clear_bullet(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

void draw_star() {
    srand(time(nullptr));
    gotoxy(rand() % 61 + 10, rand() % 4 + 2);
    printf("*");
}

void draw_stars(int n) {
    srand(time(nullptr));
    for (int i = 0; i < 20; i++) {
        draw_star();
    }
}

int main() {
    char ch = '.';
    int x = 38, y = 20;
    int bx, by;
    int bullet = 0;
    
    draw_ship(x, y);
    draw_stars(20);

    do {
        if (_kbhit()) {
            ch = _getch();

            if (ch == 'a') { draw_ship(--x, y); }
            if (ch == 's') { draw_ship(++x, y); }

            if (bullet != 1 && ch == ' ') {
                bullet = 1;
                bx = x + 3;
                by = y - 1;
            }

            fflush(stdin);
        }

        if (bullet == 1) {
            clear_bullet(bx, by);
            if (by == 2) {
                bullet = 0;
            } else {
                draw_bullet(bx, --by);
            }
        }

        Sleep(100);

    } while (ch != 'x');

    return 0;
}