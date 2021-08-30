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
    int x = 10, y = 5;
    draw_ship(x, y);

    return 0;
}