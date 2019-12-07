#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
  int array_size = 0;

  scanf("%d", &array_size);

  int multi_array[array_size][array_size];
  int max_match[array_size][2];
  int match_i = 0;

  for (int i = 0; i < array_size; i++)
  {
    for (int j = 0; j < array_size; j++)
    {
      scanf("%d", &multi_array[i][j]);
    }
  }

  _Bool match = true;

  for (int col = 0; col < array_size; col++)
  {
    for (int col_2 = 0; col_2 < array_size; col_2++)
    {
      match = true;
      for (int row = 0; row < array_size; row++)
      {
        if (col_2 != col)
        {
          if (multi_array[row][col] == multi_array[row][col_2])
          {
            match = false;
          }

          if (row == array_size-1)
          {
            if (match == true)
            {
              // have to check for duplicates
              for (int i = 0; i < match_i; i++)
              {
                if (max_match[i][0] == col_2 && max_match[i][1] == col)
                {
                  match = false;
                }
              }
              if (match == true)
              {
              max_match[match_i][0] = col;
              max_match[match_i][1] = col_2;
              match_i++;
              }
            }
          }
        }
      }
    }
  }

  printf("There are %d edges in the maximal matching:\n", match_i);
  for (int i = 0; i < match_i; i++)
  {
    printf("%d %d\n", max_match[i][0]+1, max_match[i][1]+1);
  }



  return 0;
}
