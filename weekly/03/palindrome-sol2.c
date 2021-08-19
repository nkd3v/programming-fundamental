#include <stdio.h>

int main() {
  char input[10000], str[10000], rev[10000];
  scanf("%[^\n]", input);

  int len = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z')
      str[len++] = input[i];
    else if (input[i] >= 'A' && input[i] <= 'Z')
      str[len++] = input[i] - 'A' + 'a';
  }
  str[len] = '\0';

  for (int i = 0; i < len; i++)
    rev[i] = str[len - 1 - i];

  for (int i = 0; i < len; i++) {
    if (str[i] != rev[i]) {
      printf("\"%s\" is not a palindrome.", input);
      return 0;
    }
  }

  printf("\"%s\" is a palindrome.", input);
}