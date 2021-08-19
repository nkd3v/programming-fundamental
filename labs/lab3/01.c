#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  printf("%d", n);
  while (n > 9) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    printf(" -> %d", sum);
    n = sum;
  }

  return 0;
}