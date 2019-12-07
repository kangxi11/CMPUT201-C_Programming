#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(int argc, char ** argv)
{
  int num = 0;
  int den = 0;

  int re_num;
  int re_den;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);

  if (num == 0)
  {
    printf("In lowest terms: 0\n");
  } else if (den == 0)
  {
    printf("In lowest terms: UNDEFINED\n");
  } else
  {
    reduce(num, den, &re_num, &re_den);
    printf("In lowest terms: %d/%d\n", re_num, re_den);
  }


  return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int int_1 = numerator;
    int int_2 = denominator;

    int int_temp;

    while (int_2 != 0)
    {
      int_temp = int_1 - (int_2*(int_1 / int_2));
      int_1 = int_2;
      int_2 = int_temp;
    }
    int gcd = int_1;

    *reduced_numerator = numerator/gcd;
    *reduced_denominator = denominator/gcd;
}