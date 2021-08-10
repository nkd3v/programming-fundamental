#include <stdio.h>

int main()
{
  for (int n = 1, init = 1; n <= 10000; n++) {
    
    int sum = 0;

    for (int i = 1; i < n; i++) {
      if (n % i == 0) sum += i;
    }

    if (sum == n) {
      if (!init) printf(", ");
      printf("%d", n);
      init = 0;
    }
  }
}