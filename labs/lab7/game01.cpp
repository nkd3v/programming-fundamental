#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define DTIME 20

#define MIN_X 0
#define MAX_X 80

#define MIN_Y 0
#define MAX_Y 100

void gotoxy();
void draw_ship();

void gotoxy(int x, int y)
{
  COORD c = { x, y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
  gotoxy(x, y);
  printf(" <-0-> ");
}

void bnd_change(int &val, int delta) {
  int nval = val + delta;
  if (nval < MIN_X || nval > MAX_X
      || nval < MIN_Y || nval > MAX_Y) {
    return;
  }
  val = nval;
}

int main()
{
  char ch = ' ';
  int x = 38, y = 20;
  draw_ship(x, y);

  do {
    if (_kbhit()) {
      ch = _getch();
      if (ch == 'a') {
        bnd_change(x, -1);
        draw_ship(x, y);
      } else if (ch == 'd') {
        bnd_change(x, 1);
        draw_ship(x, y);
      }
    }
    Sleep(DTIME);
  } while (ch != 'x');

  return 0;
}