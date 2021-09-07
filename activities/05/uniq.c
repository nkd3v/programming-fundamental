#include <stdio.h>

int main() {
  char str[50];
  scanf_s("%s", str, 50);

  char *p = str - 1;
  while (*++p)
    if (*p != *(p + 1))
      putchar(*p);

  return 0;
}