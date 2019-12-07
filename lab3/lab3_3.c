#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int user[4] = {0};
  int smallest = 0;
  int largest = 0;

  printf("Enter four integers: ");

  for (int i = 0; i < 4; i++)
  {
    scanf("%d", &user[i]);

    if (i == 0)
    {
      smallest = user[i];
      largest = user[i];
    } else if (user[i] < smallest)
    {
      smallest = user[i];
    } else if (user[i] > largest)
    {
      largest = user[i];
    }
  }

  printf("Largest: %d\nSmallest: %d\n", largest, smallest);

  return 0;
}
