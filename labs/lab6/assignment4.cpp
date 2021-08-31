#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define SHIP_HEIGHT 1
#define SHIP_WIDTH 7
#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 80
#define BULLET_COUNT 5

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

void gotoxy(SHORT x, SHORT y) {
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

struct Bullet {
    bool active = false;
    int x, y;
};

void draw_bullet(int x, int y) {
    gotoxy(x, y);
    printf("|");
}

void erase_bullet(int x, int y) {
    gotoxy(x, y);
    printf(" ");
}

int main() {
    setcursor(0);
    char ch = '.';
    int d = 0;
    int x = 38, y = 20;
    draw_ship(x, y);

    Bullet bullets[BULLET_COUNT];

    do {
        if (kbhit()) {
            ch = getch();
            if (ch == 'a') d = -1;
            if (ch == 's') d = 0;
            if (ch == 'd') d = 1;
            
            if (ch == ' ') {
                for (int i = 0; i < BULLET_COUNT; i++) {
                    if (!bullets[i].active) {
                        bullets[i].active = true;
                        bullets[i].x = x + SHIP_WIDTH / 2;
                        bullets[i].y = y - 1;
                        draw_bullet(bullets[i].x, bullets[i].y);
                        break;
                    }
                }
            }

            fflush(stdin);
        }
        
        for (int i = 0; i < BULLET_COUNT; i++) {
            if (!bullets[i].active) continue;
            erase_bullet(bullets[i].x, bullets[i].y);
            if (bullets[i].y - 1 >= 0)
                draw_bullet(bullets[i].x, --bullets[i].y);
            else
                bullets[i].active = false;
        }

        if (d != 0) {
            erase_ship(x, y);
            if (x + d >= 0 && (x + SHIP_WIDTH - 1) + d < SCREEN_WIDTH)
                x += d;
            draw_ship(x, y);
        }

        Sleep(100);

    } while (ch != 'x');

    return 0;
}