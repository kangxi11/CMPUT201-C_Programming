#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int user_input = 0;
  int hundreds = 0;
  int tens = 0;
  int ones = 0;

  printf("Enter a three-digit number: ");
  scanf("%d", &user_input);

  hundreds = user_input / 100;
  tens = (user_input - hundreds*100) / 10;
  ones = user_input - hundreds*100 - tens*10;

  printf("The reversal is: %d%d%d\n", ones, tens, hundreds);

  return 0;
}
