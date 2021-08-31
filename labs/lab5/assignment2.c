#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define SHIP_HEIGHT 1
#define SHIP_WIDTH 7

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

int main() {
    for (int x = 1; x + SHIP_WIDTH < 80; x++) {
        draw_ship(x, 20);
        Sleep(500);
    }

    return 0;
}