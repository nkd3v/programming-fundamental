#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

char cursor(SHORT x, SHORT y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    DWORD num_read;

    if (!ReadConsoleOutputCharacter(
        hStdout, (LPTSTR)buf, 1, { x, y }, (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

void draw_bullet(int x, int y) {
    gotoxy(x, y);
    printf("^");
    Beep(700, 100);
}

void clear_bullet(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

void draw_star() {
    int x, y;
    do {
        x = rand() % 61 + 10;
        y = rand() % 4 + 2;
    } while (cursor(x, y) == '*');
    gotoxy(x, y);
    printf("*");
}

void clear_star(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

void draw_stars(int n) {
    srand(time(nullptr));
    for (int i = 0; i < 20; i++) {
        draw_star();
    }
}

void render_score(int score) {
    gotoxy(67, 1);
    printf("Score : %d", score);
}

int main() {
    char ch = '.';
    int x = 38, y = 20;

    int bx, by;
    int bullet = 0;

    draw_ship(x, y);
    draw_stars(20);

    int score = 0;
    render_score(score);

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
                if (cursor(bx, by - 1) == '*') {
                    clear_star(bx, by - 1);
                    bullet = 0;
                    render_score(++score);
                    draw_star();
                    Beep(900, 100);
                } else {
                    draw_bullet(bx, --by);
                }
            }
        }

        Sleep(100);
    } while (ch != 'x');

    return 0;
}