#include <stdio.h>
#include <math.h>

int main() {
  int n;
  scanf("%d", &n);

  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      for (int j = -(n - 1) / 2; j <= (n - 1) / 2; j++) {
        putchar(abs(j) == i ? '*' : '-');
      }
      putchar('\n');
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
      for (int j = -(n - 1) / 2; j <= (n - 1) / 2; j++) {
        putchar(abs(j) == i ? '*' : '-');
      }
      putchar('\n');
    }
  } else {
    for (int i = 0; i <= n / 2; i++) {
      for (int j = -(n - 1) / 2; j <= (n - 1) / 2; j++) {
        putchar(abs(j) == i ? '*' : '-');
      }
      putchar('\n');
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
      for (int j = -(n - 1) / 2; j <= (n - 1) / 2; j++) {
        putchar(abs(j) == i ? '*' : '-');
      }
      putchar('\n');
    }
  }
}