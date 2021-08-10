#include <stdio.h>

int main() {
  int n;

  printf("Enter number : ");
  scanf("%d", &n);

  printf("Factoring Result : ");
  for (int i = 2; i <= n; i++) {
    while (n % i == 0) {
      printf("%d", i);
      if (n != i) printf(" x ");
      n /= i;
    }
  }

  return 0;
}