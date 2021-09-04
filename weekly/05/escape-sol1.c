#include <stdio.h>

int grid[200][200];
int n, m;

int solve(int y, int x) {
  if (x > n) {
    return 1;
  }
  if (x <= 0 || y <= 0 || y > n
      || grid[y][x] != 0) {
    return 0;
  }
  grid[y][x] = 1;

  return (
    solve(y, x + 1)
    || solve(y, x - 1)
    || solve(y + 1, x)
    || solve(y - 1, x)
  );
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  printf("%s", solve(1, 1) ? "Yes" : "No");
}