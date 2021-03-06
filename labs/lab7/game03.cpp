#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(int x, int y) {
  COORD c = { (SHORT)x, (SHORT)y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_star(int x, int y) {
  gotoxy(x, y);
  printf("*");
}

void draw_ship(int x, int y) {
  gotoxy(x, y);
  printf(" <-0-> ");
}

void draw_bullet(int x, int y) {
  gotoxy(x, y);
  printf("^");
}

void clear_bullet(int x, int y) {
  gotoxy(x, y);
  printf(" ");
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 20; i++) {
    int sx = rand() % 60 + 10;
    int sy = rand() % 4 + 1;
    draw_star(sx, sy);
  }

  char ch = '.';
  int x = 38, y = 20;
  int bx, by, i;
  int bullet = 0;
  draw_ship(x, y);

  do {
    if (_kbhit()) {
      ch = _getch();
      if (ch == 'a') {
        draw_ship(--x, y);
      }
      if (ch == 's') {
        draw_ship(++x, y);
      }
      if (bullet != 1 && ch == ' ') {
        bullet = 1;
        bx = x + 3;
        by = y - 1;
      }
      fflush(stdin);
    }

    if (bullet == 1) {
      clear_bullet(bx, by);
      if (by == 2) {
        bullet = 0;
      } else {
        draw_bullet(bx, --by);
      }
    }

    Sleep(10);

  } while (ch != 'x');

  return 0;
}