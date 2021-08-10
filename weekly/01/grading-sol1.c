#include <stdio.h>

int gradeCount = 8;
int gradeUpperBound[] = {101, 80, 75, 70, 65, 60, 55, 50};
int gradeLowerBound[] = {80, 75, 70, 65, 60, 55, 50, 0};
char gradeResult[][3] = {"A", "B+", "B", "C+", "C", "D+", "D", "F"};

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int score = a + b + c;
    
    for (int i = 0; i < gradeCount; i++) {
        if (score >= gradeLowerBound[i] && score < gradeUpperBound[i]) {
            printf("%s", gradeResult[i]);
        }
    }
}