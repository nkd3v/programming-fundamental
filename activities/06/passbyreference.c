#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a, b;
    scanf_s("%d %d", &a, &b);
    swap(&a, &b);
    printf_s("%d %d", a, b);
}