#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int grid[200][200];
int n, m;

int solve(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny > 0 && ny <= n
        && nx > 0 && nx <= m
        && grid[ny][nx] == 0) {
      grid[ny][nx] = 1;
      int found = nx > n || solve(ny, nx);
      if (found) return found;
    }
  }

  return 0;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  printf("%s", (solve(1, 1) && !grid[1][1]) ? "Yes" : "No");
}