#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void pb (int n)
{
  if (n != 0)
  {
    pb(n/2);
    putchar('0' + n%2);
  }
}

int main(int argc, char ** argv)
{
  int user_int = 0;

  printf("Please enter an integer: ");
  scanf("%d", &user_int);


  pb(user_int);
  return 0;
}
