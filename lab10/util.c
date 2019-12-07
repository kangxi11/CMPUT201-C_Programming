#include "util.h"
#include <stdio.h>
int readNumbers(int a[])
{
    printf("Enter uo to 1000 numbers to be sorted: ");
    char newline;
    int c = 0;

    do
    {
        scanf("%d%c", &a[c++], &newline);
    } while (newline != '\n');

    return c;
}