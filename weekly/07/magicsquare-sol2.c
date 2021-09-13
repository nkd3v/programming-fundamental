#include <stdio.h>

int n;
int mat[1000][1000];

int solve() {
    int sumRows[1000] = {0};
    int sumCols[1000] = {0};
    int sumDiags[2] = {0};

    for (int i = 0; i < n; i++) {
        sumDiags[0] += mat[i][i];
        sumDiags[1] += mat[i][n - i - 1];
        for (int j = 0; j < n; j++) {
            sumRows[i] += mat[i][j];
            sumCols[i] += mat[j][i];
        }
        if (sumRows[0] != sumCols[i]) return 0;
    }

    return sumDiags[0] == sumDiags[1] && sumDiags[0] == sumRows[0];
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