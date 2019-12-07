#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
    char message[100], *p;

    printf("Enter a message: ");

    int i = 0;
    char ch;
    while ( (ch = getchar()) != '\n')
    {
        message[i++] = ch;
    }

    printf("Reversal is: ");
    for (p = message + i - 1; p >= message; p--)
    {
        printf("%c", *p);
    }
    printf("\n");

    return 0;
}