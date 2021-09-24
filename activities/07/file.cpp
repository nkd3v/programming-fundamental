#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>

int main()
{
    struct player {
        char name[50];
        int level;
        int score;
    } p[5], p2[5];

    for (int i = 0; i < 5; i++) {
        strcpy(p[i].name, "Anonymous");
        p[i].level = i;
        p[i].score = i * 100;
    }

    for (int i = 0; i < 5; i++) {
        printf("name : %s\t", p[i].name);
        printf("level : %d\t", p[i].level);
        printf("score : %d\n", p[i].score);
    }

    FILE *f;

    f = fopen("players.dat", "wb");
    if (f) fwrite(p, sizeof(player), 5, f);
    fclose(f);

    f = fopen("players.dat", "rb");
    if (f) fread(p2, sizeof(player), 5, f);
    fclose(f);

    for (int i = 0; i < 5; i++) {
        printf("name : %s\t", p2[i].name);
        printf("level : %d\t", p2[i].level);
        printf("score : %d\n", p2[i].score);
    }
    
    return 0;
}
