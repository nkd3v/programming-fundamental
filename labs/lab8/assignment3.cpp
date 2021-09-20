#include <stdio.h>
#include <windows.h>
#include <time.h>

#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
COORD bufferSize = {screen_x, screen_y};
SMALL_RECT windowSize = {0, 0, screen_x - 1, screen_y - 1};
CHAR_INFO consoleBuffer[screen_y][screen_x];
COORD star[scount];
COORD ship{10, 12};
WORD shipColor = 7;
int life = 10;

void setcursor(bool visible)
{
    CONSOLE_CURSOR_INFO lpCursor{20, visible};
    SetConsoleCursorInfo(wHnd, &lpCursor);
}

int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
              ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

void gotoxy(SHORT x, SHORT y)
{
    SetConsoleCursorPosition(wHnd, {x, y});
}

void clear_buffer()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[y][x] = {};
        }
    }
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, (CHAR_INFO *)consoleBuffer, bufferSize, {},
                        &windowSize);
}

void init_star()
{
    for (int i = 0; i < scount; i++)
    {
        star[i] = {SHORT(rand() % screen_x), SHORT(rand() % screen_y)};
    }
}

void star_fall()
{
    for (int i = 0; i < scount; i++)
    {
        if (star[i].Y >= screen_y - 1)
        {
            star[i] = {SHORT(rand() % screen_x), 1};
        }
        else
        {
            star[i] = {star[i].X, SHORT(star[i].Y + 1)};
        }
    }
}

void fill_star_to_buffer()
{
    for (int i = 0; i < scount; i++)
    {
        consoleBuffer[star[i].Y][star[i].X] = {'*', 7};
    }
}

void draw_ship_to_buffer()
{
    for (int i = 0; i < 7; i++)
    {
        consoleBuffer[ship.Y][ship.X + i] = {L" <-0-> "[i], shipColor};
    }
}

void star_collision()
{
    if (life == 0) return;
    for (int i = 0; i < scount; i++)
    {
        int relativePosX = star[i].X - ship.X;
        if (relativePosX >= 0 && relativePosX < 7 && ship.Y - star[i].Y == 1)
        {
            star[i].X = rand() % screen_x;
            star[i].Y = 1;
            life--;
        }
    }
}

void fill_num_to_buffer(int n)
{
    if (n == 10)
    {
        consoleBuffer[0][1] = { '0', 7 };
        consoleBuffer[0][0] = { '1', 7 };
    }
    else
    {
        consoleBuffer[0][0] = { wchar_t('0' + n), 7 };
    }
}

int main()
{
    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setcursor(0);
    setMode();
    init_star();

    while (play && life > 0)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT &&
                    eventBuffer[i].Event.KeyEvent.bKeyDown == TRUE)
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {
                        play = false;
                    }
                    else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
                    {
                        shipColor = rand() % 255;
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT)
                {
                    ship.X = eventBuffer[i].Event.MouseEvent.dwMousePosition.X - 3;
                    ship.Y = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                        FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        shipColor = rand() % 255;
                    }
                }
            }
            delete[] eventBuffer;
        }

        clear_buffer();
        star_collision();
        star_fall();
        fill_star_to_buffer();
        draw_ship_to_buffer();
        fill_num_to_buffer(life);
        fill_buffer_to_console();

        Sleep(100);
    }

    return 0;
}