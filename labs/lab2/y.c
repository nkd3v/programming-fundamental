#include <stdio.h>
int main()
{
    char s[10000];
    scanf("%s", s);
    int i, A = 0, a = 0;
    for (i = 0; i < 10000; i++)
    {
        if (s[i] == NULL)
            break;
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                a = 1;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                A = 1;
        }
    }
    if (A == 1 && a == 0)
        printf("All Capital Letter");
    else if (A == 0 && a == 1)
        printf("All Small Letter");
    else
        printf("Mix");
}