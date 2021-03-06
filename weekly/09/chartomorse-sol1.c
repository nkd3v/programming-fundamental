#include <stdio.h>

const char *morse[26] = {
    ".-", "-...", "-.-.", "-..",
    ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-",
    "-.--", "--.."};

int main()
{
    for (char c; (c = getchar()) != '\n' && c != EOF;)
    {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z')
            printf("%s ", morse[c - 'a']);
        if (c == ' ')
            printf("/ ");
    }
}