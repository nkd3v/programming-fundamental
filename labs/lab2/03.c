#include <stdio.h>

int main() {
  int n;
  printf("Enter number : ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 || i == n
          || j == 1 || j == n) {
        putchar('*');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }

  return 0;
}