#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>

#define INF 999999

void primMST(int n, int G[n][n]);
void kruskalMST(int n, int G[n][n]);

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

    primMST(array_size, multi_array);
    kruskalMST(array_size, multi_array);

    return 0;
}

void kruskalMST(int n, int G[n][n])
{
    int min;
    int a, u, v, b;
    int chosen[n+2];

    // set all of the -1 to INF for easier algorithms
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == -1)
            {
                G[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        min = INF;
        for (int m = 0; m < n; m++)
        {
            for (int l = 0; l < n; l++)
            {
                if (G[m][l] < min)
                {
                    min = G[m][l];
                    a=u=m;
                    b=v=l;
                }
            }
        }

        while (chosen[u])
        {
            u = chosen[u];
        }
        while (chosen[v])
        {
            v = chosen[v];
        }

        if (u != v)
        {
            chosen[v] = u;
            printf("(%d, %d, %d)\n", i, a, b);
        }
        G[a][b] = G[b][a] = INF;
    }
}


void primMST(int n, int G[n][n])
{
    int mst[n];
    int key[n];
    bool chosen[n];

    int min;
    int min_i;

    // set all keys to INFINITE
    // set all edges to not chosen yet
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        chosen[i] = false;
    }

    // currently setting first to chosen
    key[0] = 0;
    mst[0] = -1;

    for (int i = 0; i < n-1; i++)
    {
        // pick the lowest cost edge out of the edges not picked yet
        min = INF;
        for (int j = 0; j < n; j++)
        {
            if ( (chosen[j] == false) && (key[j] < min))
            {
                min = key[j];
                min_i = j;
            }
        }

        chosen[min_i] = true;

        for (int x = 0; x < n; x++)
        {
            if ((G[min_i][x] > -1) && (chosen[x] == false) && (G[min_i][x] < key[x]))
            {
                mst[x] = min_i;
                key[x] = G[min_i][x];
            }
        }
    }

    for (int i = 1; i < n; i++)
        printf("(%d, %d, %d)\n", mst[i]+1, i+1, G[i][mst[i]]);
}