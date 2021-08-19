#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define DTIME 20

#define MIN_X 0
#define MAX_X 80
#define MIN_Y 0
#define MAX_Y 25

#define BULLET_COUNT 5

void setcursor(bool visible) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO lpCursor;
  lpCursor.bVisible = visible;
  lpCursor.dwSize = 20;
  SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg,int bg) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, bg*16 + fg);
}

void gotoxy(int &x, int &y) {
  COORD c = { (SHORT)x, (SHORT)y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int &x, int &y) {
  gotoxy(x, y);
  setcolor(2, 4);
  printf("<-0->");
}

void erase_ship(int &x, int &y) {
  gotoxy(x, y);
  setcolor(7, 0);
  printf("     ");
}

class Bullet {
private:
  int x, y;
  int active = 0;

  void erase() {
    gotoxy(x, y);
    setcolor(7, 0);
    printf(" ");
  }

  void draw() {
    gotoxy(x, y);
    setcolor(7, 0);
    printf("|");
  }

public:
  bool fire(int x, int y) {
    if (active) {
      return 0;
    }
    active = 1;
    this->x = x;
    this->y = y;
    return 1;
  }

  void update() {
    erase();
    if (y-- == 0) {
      active = 0;
      return;
    }
    draw();
  }
};

Bullet bullet[BULLET_COUNT];

void fire(int x, int y) {
  for (int i = 0; i < BULLET_COUNT; i++)
    if (bullet[i].fire(x, y - 1))
      break;
}

int main() {
  setcursor(0);

  char ch = ' ';
  int dir = 0;
  int x = 38, y = 20;
  draw_ship(x, y);

  do {
    if (_kbhit()) {
      ch = _getch();
      if      (ch == 'a') dir = -1;
      else if (ch == 'd') dir = 1;
      else if (ch == 's') dir = 0;
      if (ch == ' ') fire(x, y);
      fflush(stdin);
    }

    if      (dir == -1) {}
    else if (dir == 1) {}

    for (int i = 0; i < BULLET_COUNT; i++)
      bullet[i].update();
    
    Sleep(DTIME);
  } while (ch != 'x');

  return 0;
}