#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>

#define INF 999

void primMST(int n, int G[n][n]);
void kruskalMST(int n, int G[n][n]);

int main(int argc, char ** argv)
{
    // scan in a matrix
    int array_size = 0;

    scanf("%d", &array_size);

    int multi_array[array_size][array_size];

    for (int i = 1; i <= array_size; i++)
    {
        for (int j = 1; j <= array_size; j++)
        {
            scanf("%d", &multi_array[i][j]);
            if (multi_array[i][j] == -1)
                multi_array[i][j] = INF;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%3d ", G[i][j]);
        }
        printf("\n");
    }

    //primMST(array_size, multi_array);
    kruskalMST(array_size, multi_array);

    return 0;
}

void kruskalMST(int n, int G[n][n])
{
    int i, j, a, b, u, v, ne = 1;
    int min, cost[9][9], parent[9];

    // set all of the -1 to INF for easier algorithms
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%3d ", G[i][j]);
        }
        printf("\n");
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = INF; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        while (parent[u])
        {
            u = parent[u];
        }
        while (parent[v])
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[v] = u;
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
        }
        cost[a][b] = cost[b][a] = INF;
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