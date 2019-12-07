#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void DFS_Visit(int n, char color[n], int *time, int vertex, int dtime[n], int ftime[n], int matrix[n][n], int predecessor[n])
{
    color[vertex] = 'G';
    *time = *time + 1;
    
    dtime[vertex] = *time;

    for (int i = 0; i < n; i++)
    {
        if (matrix[vertex][i] == 1)
        {
            if (color[i] == 'W')
            {
                predecessor[i] = vertex;
                DFS_Visit(n, color, time, i, dtime, ftime, matrix, predecessor);
            }
        }

    }
    color[vertex] = 'B';
    printf("%d ", vertex);
    *time += + 1;
    ftime[vertex] = *time;


}

int main(int argc, char ** argv)
{
    // scan in a matrix
    int array_size = 0;

    scanf("%d", &array_size);

    int multi_array[array_size][array_size];
    int *p;

    for (p = &multi_array[0][0]; p <= &multi_array[array_size - 1][array_size - 1]; p++)
    {
        scanf("%d", &(*p));
    }

    char color[array_size];
    int predecessor[array_size];
    int dtime[array_size];
    int ftime[array_size];

    for (int i = 0; i < array_size; i++)
    {
        color[i] = 'W';
        predecessor[i] = -1;
    }
    int time = 0;

    printf("\n");

    for (int i = 0; i < array_size; i++)
    {
        if (color[i] == 'W')
        {
            DFS_Visit(array_size, color, &time, i, dtime, ftime, multi_array, predecessor);
        }
    }

    return 0;
}