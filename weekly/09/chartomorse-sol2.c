#include <stdio.h>

int main()
{
    for (char c; (c = getchar()) != '\n' && c != EOF;)
    {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';

        const char *r;

        switch (c)
        {
        case 'a':
            r = ".-";
            break;
        case 'b':
            r = "-...";
            break;
        case 'c':
            r = "-.-.";
            break;
        case 'd':
            r = "-..";
            break;
        case 'e':
            r = ".";
            break;
        case 'f':
            r = "..-.";
            break;
        case 'g':
            r = "--.";
            break;
        case 'h':
            r = "....";
            break;
        case 'i':
            r = "..";
            break;
        case 'j':
            r = ".---";
            break;
        case 'k':
            r = "-.-";
            break;
        case 'l':
            r = ".-..";
            break;
        case 'm':
            r = "--";
            break;
        case 'n':
            r = "-.";
            break;
        case 'o':
            r = "---";
            break;
        case 'p':
            r = ".--.";
            break;
        case 'q':
            r = "--.-";
            break;
        case 'r':
            r = ".-.";
            break;
        case 's':
            r = "...";
            break;
        case 't':
            r = "-";
            break;
        case 'u':
            r = "..-";
            break;
        case 'v':
            r = "...-";
            break;
        case 'w':
            r = ".--";
            break;
        case 'x':
            r = "-..-";
            break;
        case 'y':
            r = "-.--";
            break;
        case 'z':
            r = "--..";
            break;
        case ' ':
            r = "/";
            break;
        }

        printf("%s ", r);
    }
}