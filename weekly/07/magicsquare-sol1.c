#include <stdio.h>

int n;
int mat[1000][1000];

int solve() {
    int sumDiag1 = 0;
    int sumDiag2 = 0;

    for (int i = 0; i < n; i++) {
        sumDiag1 += mat[i][i];
        sumDiag2 += mat[i][n - i - 1];
    }

    if (sumDiag1 != sumDiag2) return 0;

    for (int i = 0; i < n; i++) {
        int sumRow = 0;
        int sumCol = 0;
        for (int j = 0; j < n; j++) {
            sumRow += mat[i][j];
            sumCol += mat[j][i];
        }
        if (sumRow != sumDiag1
            || sumCol != sumDiag1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("%s", solve() ? "Yes" : "No");
}