#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define DELTA_TIME 20

#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 80

void gotoxy(int &x, int &y) {
  COORD c = { (SHORT)x, (SHORT)y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int &x, int &y) {
  gotoxy(x, y);
  printf("<-0->");
}

void erase_ship(int &x, int &y) {
  gotoxy(x, y);
  printf("     ");
}

void move_ship(int &x, int &y, int dx, int dy) {
  erase_ship(x, y);

  if (x + dx >= 0 && x + dx <= SCREEN_WIDTH)
    x += dx;
  if (y + dy >= 0 && y + dy <= SCREEN_HEIGHT)
    y += dy;

  draw_ship(x, y);
}

int main() {
  char ch = ' ';
  int x = 38, y = 20;
  draw_ship(x, y);

  do {
    if (_kbhit()) {
      ch = _getch();

      if (ch == 'w')
        move_ship(x, y, 0, -1);
      else if (ch == 's')
        move_ship(x, y, 0, 1);
      else if (ch == 'a')
        move_ship(x, y, -1, 0);
      else if (ch == 'd')
        move_ship(x, y, 1, 0);

      fflush(stdin);
    }

    Sleep(DELTA_TIME);
  } while (ch != 'x');

  return 0;
}