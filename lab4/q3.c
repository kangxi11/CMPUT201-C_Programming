#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int num = 0;
  int den = 0;

  int int_1 = 0;
  int int_2 = 0;

  int gcd = 0;

  int int_temp = 0;

  printf("Enter a fraction: ");
  scanf("%d/%d", &int_1, &int_2);

  num = int_1;
  den = int_2;

  if (int_1 == 0)
  {
    printf("In lowest terms: 0\n");
  } else if (int_2 == 0)
  {
    printf("In lowest terms: UNDEFINED\n");
  } else
  {
    while (int_2 != 0)
    {
      int_temp = int_1 - (int_2*(int_1 / int_2));
      int_1 = int_2;
      int_2 = int_temp;
    }
    gcd = int_1;

    printf("In lowest terms: %d/%d\n", num/gcd, den/gcd);
  }


  return 0;
}
