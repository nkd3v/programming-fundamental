#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define DELTA_TIME 100
#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 80

void gotoxy(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

void erase_ship(int x, int y) {
    gotoxy(x, y);
    printf("       ");
}

int main() {
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);

    do {
        if (_kbhit()) {
            ch = _getch();

            erase_ship(x, y);

            if (ch == 'w' && y - 1 > 0) --y;
            else if (ch == 's' && y + 1 < SCREEN_HEIGHT) ++y;
            else if (ch == 'a' && x - 1 > 0) --x;
            else if (ch == 'd' && x + 1 < SCREEN_WIDTH) ++x;    

            draw_ship(x, y);

            fflush(stdin);
        }
        Sleep(DELTA_TIME);
    } while (ch != 'x');

    return 0;
}