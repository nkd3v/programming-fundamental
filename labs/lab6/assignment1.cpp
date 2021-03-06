#include <stdio.h>
#include <windows.h>
#include <conio.h>

void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, & lpCursor);
}

void setcolor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    setcolor(2, 4);
    gotoxy(x, y);
    printf(" <-0-> ");
    setcolor(7, 0);
}

void erase_ship(int x, int y) {
    gotoxy(x, y);
    printf("       ");
}

int main() {
    setcursor(0);
    char ch = '.';
    int x = 38, y = 20;
    draw_ship(x, y);

    do {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a') {
                erase_ship(x, y);
                draw_ship(--x, y);
            }
            if (ch == 's') {
                erase_ship(x, y);
                draw_ship(++x, y);
            }
            fflush(stdin);
        }
        Sleep(100);

    } while (ch != 'x');

    return 0;
}