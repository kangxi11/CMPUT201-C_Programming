#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int user_input = 0;
  int tens = 0;
  int ones = 0;

  printf("Enter a two-digit number: ");
  scanf("%d", &user_input);

  tens = user_input / 10;
  ones = user_input - tens*10;

  printf("The reversal is: %d%d\n", ones, tens);


  return 0;
}
