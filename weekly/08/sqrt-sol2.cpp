#include <stdio.h>

double sqrt(double n) {
    double l, r, m {1};

    if (n < 1)  l = n, r = 1;
    else        l = 1, r = n;

    while (l < r) {
        m = l + (r - l) * 0.5;
        if (m * m < n)  l = m + 1e-7;
        else            r = m - 1e-7;
    }

    return m;
}

int main() {
    double n;
    scanf("%lf", &n);
    printf("%lf", sqrt(n));

    return 0;
}