#include <stdio.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int y = n - 1; y >= -n + 1; y--) {
    for (int x = -n + 1; x <= n - 1; x++) {
      if (abs(y) <= abs(x))
        printf("*  ");
      else
        printf("   ");
    }
    putchar('\n');
  }

  return 0;
}