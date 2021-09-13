#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define SHIP_WIDTH 7
#define SCREEN_WIDTH 80

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
int delayedTime = 0;

void setcursor(bool visible) {
    CONSOLE_CURSOR_INFO lpCursor{ 20, visible };
    SetConsoleCursorInfo(hStdout, &lpCursor);
}

void setcolor(int fg, int bg) {
    SetConsoleTextAttribute(hStdout, bg * 16 + fg);
}

void gotoxy(SHORT x, SHORT y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(hStdout, c);
}

char cursor(SHORT x, SHORT y) {
    char buf[2];
    DWORD num_read;

    if (!ReadConsoleOutputCharacter(
        hStdout, (LPTSTR)buf, 1, { x, y }, (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}

void draw_ship(int x, int y) {
    setcolor(1, 9);
    gotoxy(x, y);
    printf(" <-0-> ");
    setcolor(7, 0);
}

void erase_ship(int x, int y) {
    gotoxy(x, y);
    printf("       ");
}

void draw_bullet(int x, int y) {
    setcolor(5, 0);
    gotoxy(x, y);
    printf("^");
    Beep(700, 50);
    delayedTime += 50;
    setcolor(7, 0);
}

void clear_bullet(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

void draw_star() {
    setcolor(6, 0);
    int x, y;
    do {
        x = rand() % 61 + 10;
        y = rand() % 4 + 2;
    } while (cursor(x, y) == '*');
    gotoxy(x, y);
    printf("*");
    setcolor(7, 0);
}

void clear_star(int x, int y) {
    gotoxy(x, y);
    printf(" ");
    Beep(1000, 50);
    delayedTime += 50;
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
    setcursor(0);

    char ch = '.';
    int x = 38, y = 20;
    int d = 0;

    int bx, by;
    int bullet = 0;

    draw_ship(x, y);
    draw_stars(20);

    int score = 0;
    render_score(score);

    do {
        delayedTime = 0;

        if (_kbhit()) {
            ch = _getch();

            if (ch == 'a') d = -1;
            if (ch == 's') d = 0;
            if (ch == 'd') d = 1;

            if (bullet != 1 && ch == ' ') {
                bullet = 1;
                bx = x + 3;
                by = y - 1;
            }

            fflush(stdin);
        }

        erase_ship(x, y);
        if (x + d >= 0 && (x + SHIP_WIDTH - 1) + d < SCREEN_WIDTH)
            x += d;
        draw_ship(x, y);

        if (bullet == 1) {
            clear_bullet(bx, by);
            if (by == 2) {
                bullet = 0;
            }
            else {
                if (cursor(bx, by - 1) == '*') {
                    clear_star(bx, by - 1);
                    bullet = 0;
                    render_score(++score);
                    draw_star();
                }
                else {
                    draw_bullet(bx, --by);
                }
            }
        }

        Sleep(100 - delayedTime);
    } while (ch != 'x');

    return 0;
}