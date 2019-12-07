#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int int_1 = 0;
  int int_2 = 0;

  int int_temp = 0;

  printf("Enter two integers: ");
  scanf("%d %d", &int_1, &int_2);

  if (int_1 == 0)
  {
    printf("Greatest common divisor: %d\n", int_2);
  } else if (int_1 == 0)
  {
    printf("Greatest common divisor: %d\n", int_1);
  } else
  {
    while (int_2 != 0)
    {
      int_temp = int_1 - (int_2*(int_1 / int_2));
      int_1 = int_2;
      int_2 = int_temp;
    }
    printf("Greatest common divisor: %d\n", int_1);
  }


  return 0;
}
