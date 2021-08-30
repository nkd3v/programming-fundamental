/* GitHub URL:  */

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
    for (int x = 1; x < 80; x++) {
        draw_ship(x, 20);
        Sleep(500);
    }

    return 0;
}