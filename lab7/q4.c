#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
    int array_size = 0;

    scanf("%d", &array_size);

    int multi_array[array_size][array_size];
    int *p;
    int x = 0;

    int square[array_size][array_size];
    int temp[array_size*array_size];

    for (p = &multi_array[0][0]; p <= &multi_array[array_size-1][array_size-1]; p++)
    {
        scanf("%d", &(*p));
    }

    for (int row = 0; row < array_size; row++)
    {
        for (int col = 0; col < array_size; col++)
        {
            if (row == col) // same vertice
            {
                square[row][col] = 0;
            } else
            {
                // first see if they are connected
                if (multi_array[row][col] == 1)
                {
                    square[row][col] = 1;
                } else
                {
                    square[row][col] = 0;
                    
                    // get all the vertices the row connects to
                    for (int i = 0; i < array_size; i++)
                    {
                        if (multi_array[row][i] == 1)
                        {
                            temp[x++] = multi_array[row][i];
                        }
                    }
                    // now see if anything in temp connects to col
                    for (int i = 0; i < x; i++)
                    {
                        if (multi_array[temp[i]][col] == 1)
                        {
                            square[row][col] = 1;
                        }
                    }

                    // reset temp
                    for (int i = 0; i < array_size*array_size; i++)
                    {
                        temp[i] = 0;
                    }
                }
            }
        }
    }

    printf("\n");
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            printf("%d ",square[i][j]);
        }
        printf("\n");
    }
    return 0;
}