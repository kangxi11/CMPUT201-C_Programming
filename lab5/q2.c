#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void create_magic_square (int n, int magic_square[n][n])
{
  int row = 0;
  int col = n/2;
  int counter = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      magic_square[i][j] = 0;
    }
  }

  while (counter <= n*n)
  {
    magic_square[row][col] = counter;
    counter ++;

    row--;
    col++;

    if (row < 0 && col == n)
    {
      row = row + 2;
      col = col - 1;
    }else if (row < 0)
    {
      row = n-1;
    }else if (col == n)
    {
      col = 0;
    }else if (magic_square[row][col] > 0)
    {
      row = row + 2;
      col = col - 1;
    }
  }


}

void print_magic_square(int n, int magic_square[n][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%3d ", magic_square[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv)
{
  int size = 0;
  printf("The program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99\n,");
  printf("Enter size of magic square: ");
  scanf("%d", &size);

  int ms[size][size];

  create_magic_square(size, ms);
  print_magic_square(size, ms);

  return 0;
}
