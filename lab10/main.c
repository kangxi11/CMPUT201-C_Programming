/* QuickSort Algorithm */
#include "main.h"

int main (int argc, char *argv[])
{
    int a[N];
    int c;

    c = readNumbers(a);

    if (argv[1][1] == 'i')
    {
        insertionsort(a, 0, c - 1);
    }
    else if (argv[1][1] == 'q')
    {
        quicksort(a, 0, c-1);
    }


    printf("In sorted order: ");
    for (int i = 0; i < c; i++)
        printf("%d ", a[i]);

    printf("\n");

    #ifdef COUNT
        COUNT
    #endif

    return 0;
}
