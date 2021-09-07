#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char str[50];
    scanf("%s", str);

    char *p = str;
    while (*p != '\0') {
        if (*p != *(p + 1)) {
            putchar(*p);
        }
        p++;
    }

    return 0;
}