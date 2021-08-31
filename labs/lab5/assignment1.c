#include <windows.h>
#include <stdio.h>
#include <conio.h>

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
    gotoxy(x, y);
    printf(" <-0-> ");
}

int main() {
    int x = 10, y = 5;
    draw_ship(x, y);

    return 0;
}