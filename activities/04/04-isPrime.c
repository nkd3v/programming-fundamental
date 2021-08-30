#include <stdio.h>

int isPrime(int n);

int main() {
  int n;
  scanf_s("%d", &n);

  if (isPrime(n))
    printf("Prime Number");
  else
    printf("Not Prime Number");
}

int isPrime(int n) {
  if (n < 2) return 0;

  for (int i = 2; i*i <= n; i++)
    if (n % i == 0) return 0;

  return 1;
}