#include <windows.h>
#include <stdio.h>
#include <conio.h>

void gotoxy(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

int main() {
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);

    do {
        if (_kbhit()) {
            ch = _getch();

            if (ch == 'a' && x - 1 > 0)
                draw_ship(--x, y);
            else if (ch == 'd' && x + 1 < 80)
                draw_ship(++x, y);

            fflush(stdin);
        }
        Sleep(100);
    } while (ch != 'x');

    return 0;
}