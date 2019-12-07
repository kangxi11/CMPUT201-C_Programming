#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void enqueue (int n, int v_queue[n], int vertex)
{
    // add vertex to the queue
    for (int i = 0; i < n; i++)
    {
        if (v_queue[i] == -1)
        {
            v_queue[i] = vertex;
            break;
        }
    }

}

int dequeue (int n, int v_queue[n])
{
    int temp = v_queue[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n-1)
        {
            v_queue[i] = v_queue[i + 1];
        } else
        {
            v_queue[i] = -1;
        }
    }
    return temp;
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

    // start at vertex 0
    char color[array_size];
    int distance[array_size];
    int predecessor[array_size];

    for (int i = 0; i < array_size; i++)
    {
        color[i] = 'W';
        distance[i] = 9999999;
        predecessor[i] = -1;

    }

    // set the list to empty
    int v_queue[array_size];
    int queue_size = 0;
    int v_temp;
    for (int i = 0; i < array_size; i++)
    {
        v_queue[i] = -1;
    }
    enqueue(array_size, v_queue, 0);
    queue_size += 1;

    color[0] = 'G';
    distance[0] = 0;

    printf("\n");

    while (queue_size != 0)
    {
        v_temp = dequeue(array_size, v_queue);
        queue_size -= 1;
        for (int i = 0; i < array_size; i++)
        {
            if (multi_array[v_temp][i] == 1)
            {
                if (color[i] == 'W')
                {
                    color[i] = 'G';
                    distance[i] = distance[v_temp] + 1;
                    predecessor[i] = v_temp;
                    enqueue(array_size, v_queue, i);
                    queue_size += 1;
                }
            }
        }
        color[v_temp] = 'B';
        printf("%d ", v_temp);
    }
    printf("\n");
    

    return 0;
}