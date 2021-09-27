#include <stdio.h>

int main() {
    double n;
    scanf("%lf", &n);
    
    double r = (n + 1) * 0.5;
    for (int lim = 1000; r * r > n && lim--;) {
        r = (r + n/r) * 0.5;
    }

    printf("%lf", r);

    return 0;
}