#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define DTIME 20

#define MIN_X 0
#define MAX_X 80
#define MIN_Y 0
#define MAX_Y 25

void gotoxy(int &x, int &y);
void draw_ship(int &x, int &y);
void erase_ship(int &x, int &y);
void move_ship(int &x, int &y, int dx, int dy);
void bnd_change(int &x, int &y, int dx, int dy);

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
  bnd_change(x, y, dx, dy);
  draw_ship(x, y);
}

void bnd_change(int &x, int &y, int dx, int dy) {
  int nx = x + dx;
  int ny = y + dy;

  if (nx >= MIN_X && nx <= MAX_X) {
    x = nx;
  }

  if (ny >= MIN_Y && ny <= MAX_Y) {
    y = ny;
  }
}

int main() {
  char ch = ' ';
  int x = 38, y = 20;
  draw_ship(x, y);

  do {
    if (_kbhit()) {
      ch = _getch();

      if (ch == 'w') {
        move_ship(x, y, 0, -1);
      } else if (ch == 's') {
        move_ship(x, y, 0, 1);
      } else if (ch == 'a') {
        move_ship(x, y, -1, 0);
      } else if (ch == 'd') {
        move_ship(x, y, 1, 0);
      }

      fflush(stdin);
    }

    Sleep(DTIME);
  } while (ch != 'x');

  return 0;
}