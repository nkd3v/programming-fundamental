#include <windows.h>
#include <time.h>

#define screen_x 80
#define screen_y 25

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_y][screen_x];
COORD bufferSize = {screen_x, screen_y};
COORD characterPos = {0, 0};
SMALL_RECT windowSize = {0, 0, screen_x - 1, screen_y - 1};

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

void fill_data_to_buffer()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[y][x].Char.AsciiChar = 'A' + rand() % 26;
            consoleBuffer[y][x].Attributes = rand() % 255;
        }
    }
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, (CHAR_INFO *)consoleBuffer, bufferSize, characterPos,
                        &windowSize);
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        setConsole(screen_x, screen_y);
        fill_data_to_buffer();
        fill_buffer_to_console();
    }
    return 0;
}