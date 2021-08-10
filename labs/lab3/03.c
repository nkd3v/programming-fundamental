#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = -n + 1; i <= n - 1; i++) {
    for (int j = -n + 1; j <= n - 1; j++) {
      if (abs(j) >= abs(i))
        printf("* ");
      else
        printf("  ");
    }
    putchar('\n');
  }
}