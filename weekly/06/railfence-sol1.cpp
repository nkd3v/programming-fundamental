#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int n;
    scanf("%[^\n] %d", s, &n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < strlen(s); j += 2*(n-1)) {
            putchar(s[j]);
            if (i % (n-1) != 0)
                putchar(s[j + 2*(n-i-1)]);
        }
    }
}