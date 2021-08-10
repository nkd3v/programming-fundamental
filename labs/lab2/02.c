#include <stdio.h>

int main() {
  int a, b;

  printf("Enter first number : ");
  scanf("%d", &a);
  
  printf("Enter second number : ");
  scanf("%d", &b);

  printf("Greatest coommon divisor = ");
  for (int i = a; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      printf("%d", i);
      break;
    }
  }

  return 0;
}