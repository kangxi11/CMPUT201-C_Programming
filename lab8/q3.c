#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LENGTH 20

int read_line(char str[], int n);

int main(int argc, char ** argv)
{
    char **words = (char**) malloc (sizeof(char*));
    char *word;
    int num_words = 0;

    int i = 0;

    while (1)
    {
        word = (char*) malloc ( (LENGTH+1)*sizeof(char));
        read_line(word, LENGTH);

        if (word[strlen(word)-1] == '\n')
        {
            word[strlen(word) - 1] = '\0';
        }

        if (word[0] == '\0')
        {
            break;
        }

        *(words+i) = word;
        i++;
        num_words++;
    }

    // now bubblesort the array of words
    i = 0;
    int j = 0;
    char temp[LENGTH+1];
    for (i = 0; i < num_words-1; i++)
    {
        for (j = 0; j < num_words-i-1; j++)
        {
            if ( (strcmp(words[j], words[j+1])) > 0)
            {
                strcpy(temp, words[j]);
                *(words+j) = words[j+1];
                *(words+j+1) = temp;
            }
        }
    }

    printf("In sorted order: ");
    for (i = 0; i < num_words; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    

    return 0;
}

int read_line(char str[], int n)
{
    char ch;
    int i = 0;
    printf("Enter word: ");
    while ( (ch = getchar()) != '\n')
    {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}