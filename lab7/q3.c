#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reverse (char *message);

int main(int argc, char **argv)
{
    char message[100];

    printf("Enter a message: ");

    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        message[i++] = ch;
    }
    message[i] = '\0';

    reverse(message);

    printf("Reversal is: %s\n", message);
}

void reverse(char *message)
{
    char *left = message;
    char *right = message + strlen(message) - 1;
    char temp;

    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
