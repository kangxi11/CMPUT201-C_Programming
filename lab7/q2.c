#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
    char message[100], *left, *right;

    printf("Enter a message: ");

    int i = 0;
    char ch;
    while ( (ch = getchar()) != '\n')
    {
        message[i++] = ch;
    }

    left = message;
    right = message + i - 1;

    bool palin = true;

    while (left < right)
    {
        if ( !((*left >= 'A') && (*left <= 'Z')) && !( (*left >= 'a') && (*left <= 'z')))
        {
            left++;
        } else if (!((*right >= 'A') && (*right <= 'Z')) && !((*right >= 'a') && (*right <= 'z')))
        {
            right--;
        } else if (toupper(*left) != toupper(*right))
        {
            palin = false;
            break;
        } else
        {
            left++;
            right--;
        }
    }

    if (palin)
    {
        printf("Palindrome\n");
    } else
    {
        printf("Not a palindrome\n");
    }
    

    return 0;
}