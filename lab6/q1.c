#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DIGITS 10

char digits[4][MAX_DIGITS * 4];
char segments[MAX_DIGITS];


void clear_digits_array();
void process_digit(int digit, int position);
void print_digits_array(void);

int main(int argc, char ** argv)
{
    char input[100];
    int position = 0;

    printf("Enter a number: ");
    scanf("%100s", input);

    int i = 0;
    int j = 0;
    

    while ( (input[i] != 0) && (j < MAX_DIGITS))
    {
        if ( (input[i] >= 48) && (input[i] <= 57) )
        {
            segments[j] = input[i];
            i++;
            j++;
        } else
        {
            i++;
        }
    }

    clear_digits_array();
    i = 0;
    while ((segments[i] != 0) && (i < MAX_DIGITS))
    {
        process_digit(segments[i] - '0', position);
        i++;
        position++;
    }

    print_digits_array();

    return 0;
}

void clear_digits_array()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < MAX_DIGITS*4; j++)
        {
            digits[i][j] = ' ';
        }
    }


}

void process_digit(int digit, int position)
{
    char _0[4][4] = { {' ', ' ', ' ', ' '},
                      {' ', '_', ' ', ' '},
                      {'|', ' ', '|', ' '},
                      {'|', '_', '|', ' '}};
    char _1[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' '},
                     {' ', ' ', '|', ' '},
                     {' ', ' ', '|', ' '}};
    char _2[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {' ', '_', '|', ' '},
                     {'|', '_', ' ', ' '}};
    char _3[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {' ', '_', '|', ' '},
                     {' ', '_', '|', ' '}};
    char _4[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' '},
                     {'|', '_', '|', ' '},
                     {' ', ' ', '|', ' '}};
    char _5[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {'|', '_', ' ', ' '},
                     {' ', '_', '|', ' '}};
    char _6[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {'|', '_', ' ', ' '},
                     {'|', '_', '|', ' '}};
    char _7[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {' ', ' ', '|', ' '},
                     {' ', ' ', '|', ' '}};
    char _8[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {'|', '_', '|', ' '},
                     {'|', '_', '|', ' '}};
    char _9[4][4] = {{' ', ' ', ' ', ' '},
                     {' ', '_', ' ', ' '},
                     {'|', '_', '|', ' '},
                     {' ', '_', '|', ' '}};

    
    if (digit == 0)
    {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            digits[i][4 * position + j] = _0[i][j];
        }
    }
    }else if (digit == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _1[i][j];
            }
        }
    }else if (digit == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _2[i][j];
            }
        }
    }else if (digit == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _3[i][j];
            }
        }
    }else if (digit == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _4[i][j];
            }
        }
    }else if (digit == 5)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _5[i][j];
            }
        }
    }else if (digit == 6)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _6[i][j];
            }
        }
    }else if (digit == 7)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _7[i][j];
            }
        }
    }else if (digit == 8)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _8[i][j];
            }
        }
    }else if (digit == 9)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                digits[i][4 * position + j] = _9[i][j];
            }
        }
    }
}
void print_digits_array(void)
{
    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < MAX_DIGITS*4; j++)
        {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}
