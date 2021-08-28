#include <stdio.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);

  int p = n - 1;
  int q = p / 2;

  for (int y = p; y >= -p; y -= 2) {
    for (int x = -q; x <= q; x++) {
      putchar(abs(y / 2) + abs(x) == q ? '*' : '-');
    }

    putchar('\n');
  }
}