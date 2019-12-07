#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

int main(int argc, char ** argv)
{

  unsigned int user_int = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &user_int);

  printf("The machine format is: ");
  for (int i = 31; i >= 0; i--)
  {
    if ((user_int >> i) & 1) // shifting by i bytes each time
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
  }
  printf("\n");

  float user_float = 0.0;
  printf("Enter a positive point float: ");
  scanf("%f", &user_float);

  unsigned int int_32 = *((unsigned int *) (&user_float));
  
  printf("The machine format is: ");
  for (int i = 31; i >= 0; i--)
  {
    if ((int_32 >> i) & 1) // shifting by i bytes each time
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
  }
  printf("\n");

  return 0;
}
