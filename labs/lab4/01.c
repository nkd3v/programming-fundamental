#include <stdio.h>

int main() {
  char str[10000];
  fgets(str, 10000, stdin);

  for (int i = 0, n = 1; str[i]; i++, n = 1) {
    if (str[i] >= '0' && str[i] <= '9') {
      sscanf(str + i, "%d", &n);
      while (str[i] >= '0' && str[i] <= '9') i++;
    }

    for (int j = 0; j < n; j++)
      putchar(str[i]);
  }
}