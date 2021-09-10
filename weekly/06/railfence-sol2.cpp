#include <stdio.h>

int main() {
    char s[1000];
    int n;
    scanf("%[^\n] %d", s, &n);

    int len = 0;
    while (s[len++]);

    for (int i = 0; i < n; i++) {
        int j = i;

        int p = 2 * (n - i - 1);
        int q = 2 * i;
        if (p * q == 0) p = q = 2 * (n - 1);

        while (1) {
            if (j >= len) break;
            putchar(s[j]);
            j += p;

            if (j >= len) break;
            putchar(s[j]);
            j += q;
        }
    }
}