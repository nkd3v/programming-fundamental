#include <stdio.h>

int main() {
  char str[1000];
  scanf("%[^\n]", str);

  for (int i = 0; str[i] != '\0'; i++) {
    int n = str[i] >= '0' && str[i] <= '9' ? 0 : 1;

    for ( ; str[i] >= '0' && str[i] <= '9'; i++)
      n = (n * 10) + (str[i] - '0');

    while (n--)
      putchar(str[i]);
  }

  return 0;
}
