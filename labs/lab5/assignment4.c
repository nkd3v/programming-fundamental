#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define DELTA_TIME 100
#define SHIP_HEIGHT 1
#define SHIP_WIDTH 5
#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 80

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
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

            if (ch == 'w' && y - 1 >= 0) --y;
            else if (ch == 's' && y + SHIP_HEIGHT < SCREEN_HEIGHT) ++y;
            else if (ch == 'a' && x - 1 >= 0) --x;
            else if (ch == 'd' && x + SHIP_WIDTH < SCREEN_WIDTH) ++x;

            draw_ship(x, y);

            fflush(stdin);
        }
        Sleep(DELTA_TIME);
    } while (ch != 'x');

    return 0;
}