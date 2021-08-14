#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define DTIME 20

#define MIN_X 0
#define MAX_X 80
#define MIN_Y 0
#define MAX_Y 25

#define BULLET_COUNT 5

void setcursor(bool visible);
void setcolor(int fg,int bg);

void gotoxy(int &x, int &y);
void draw_ship(int &x, int &y);
void erase_ship(int &x, int &y);
void move_ship(int &x, int &y, int dx, int dy);
void bnd_change(int &x, int &y, int dx, int dy);

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

class Bullet {
public:
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
    printf(".");
  }

  void fire(int x, int y) {
    active = 1;
    this->x = x;
    this->y = y;
  }

  void update() {
    erase();

    if (y == 0) {
      active = 0;
      return;
    }

    y--;
    draw();
  }
};

Bullet bullet[BULLET_COUNT];

void fire(int x, int y) {
  for (int i = 0; i < BULLET_COUNT; i++) {
    if (!bullet[i].active) {
      bullet[i].fire(x, y - 1);
      break;
    }
  }
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

      if (ch == 'a') {
        dir = -1;
      } else if (ch == 'd') {
        dir = 1;
      } else if (ch == 's') {
        dir = 0;
      }

      if (ch == ' ') {
        fire(x, y);
      }

      fflush(stdin);
    }

    if (dir == -1) {
      move_ship(x, y, -1, 0);
    } else if (dir == 1) {
      move_ship(x, y, 1, 0);
    }

    for (int i = 0; i < BULLET_COUNT; i++) {
      bullet[i].update();
    }
    
    Sleep(DTIME);
  } while (ch != 'x');

  return 0;
}