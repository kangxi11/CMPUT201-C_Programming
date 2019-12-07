/*
Submitting student: Ryan Kang (1543686)

Collaborating Classmates: N/A

Other collaborators: N/A

References:
    Carlos Delgado
    https://ourcodeworld.com/articles/read/884/how-to-get-the-square-root-of-a-number-without-using-the-sqrt-function-in-c
    For calculating the sqaure root of a number because <math.h> was not working

    Steve Summit
    https://www.eskimo.com/~scs/cclass/int/sx9b.html
    Allocating memory for 2D arrays and avoid memory leaks. The example in class was not working.

    Ryan Kang (myself)
    Using longest common subsequence code from assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000+1

void lcs(char s1[], char s2[], char *lcsString);
void lps(char s[]);
void lts(char s[]);


int main(int argc, char **argv)
{
    // allocating memory dynamically for the two strings up to 10 000
    char *s1 = (char *) malloc(MAX * sizeof(char));
    char *s2 = (char *) malloc(MAX * sizeof(char));

    _Bool error = false;
    // checking that the sequences only contain 0-9 digits

    // Functionality 1: Read in 2 sequences of length up to 10 000
    do
    {
        error = false; //reset error eveytime we read in inputs

        printf("Enter the first sequence: ");

        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch < '0' || ch > '9')
            {
                printf("Error, non-digit character detected!\n");
                error = true;
            }
            s1[i++] = ch;
        }
        s1[i] = '\0';

        if (error == true)
        {
            continue; // don't read in the second sequence
        }

        printf("Enter the second sequence: ");
        i = 0;
        while ((ch = getchar()) != '\n')
        {
            if (ch < '0' || ch > '9')
            {
                printf("Error, non-digit character detected!\n");
                error = true;
            }
            s2[i++] = ch;
        }
        s2[i] = '\0';
    } while (error == true); // keeps going until no errors are found

    printf("\n");
    lts(s1);
    lps(s2);
    
    // free the strings to avoid memory leaks
    free(s1);
    free(s2);


    return 0;
}

// Functionality 4: Longest Common Subseqeunce is a function
// Longest Tandem Subsequence is a function
// Longest palindromic subsequence is a function

void lcs(char s1[], char s2[], char* lcs_string)
{
    
    // finding the LCS of the two sequence of numbers
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);


    int lcs_i = 0;
    
    // dynamically allocating a 2D array of up to 10 000 by 10 000
    int **lcs_table = (int **)malloc((s2_len + 1) * sizeof(int *)); // [rows][columns]
    //int **lcs_temp = lcs_table_original;
    for (int i = 0; i < s2_len + 1; i++)
    {
        lcs_table[i] = (int *)malloc((s1_len + 1) * sizeof(int));
    }


    /* s1 will be the columns and s2 will be the rows
  //    s1[0] s1[1] s1[2] s1[3] ......
  s2[0]______|_____|_____|______|.....
  s2[1]______|_____|_____|______|.....
  s2[2]______|_____|_____|______|.....
  s2[3]______|_____|_____|______|.....
  .
  .
  .

  */

    // making sure each of the elements in the array is 0 to start
    for (int i = 0; i < s2_len + 1; i++)
    {
        for (int j = 0; j < s1_len + 1; j++)
        {
            lcs_table[i][j] = 0;
        }
    }

    // creating the table that holds the LCS path
    for (int row = 0; row < s2_len; row++)
    {
        for (int col = 0; col < s1_len; col++)
        {
            if (s2[row] == s1[col])
            {
                // if equal, add one to the number to its diagonal left (up 1 left 1)
                lcs_table[row + 1][col + 1] = lcs_table[row][col] + 1;
            }
            else
            {
                // if not equal copy the highest number of its neighbour directly up
                // or directly to the left
                if (lcs_table[row + 1][col] > lcs_table[row][col + 1])
                {
                    lcs_table[row + 1][col + 1] = lcs_table[row + 1][col];
                }
                else
                {
                    lcs_table[row + 1][col + 1] = lcs_table[row][col + 1];
                }
            }
        }
    }

    // now to retrace the steps and find all of the pairs that created the greatest number
    // the highest number will always be at the very bottom right of the lcs_table

    int row = s2_len;
    int col = s1_len;

    do
    {
        // if all three neighbours are different, then it must have been a pair
        if ((lcs_table[row][col] != lcs_table[row - 1][col]) && (lcs_table[row][col] != lcs_table[row][col - 1]) && (lcs_table[row][col] != lcs_table[row - 1][col - 1]))
        {
            lcs_string[lcs_i] = s2[row - 1];
            lcs_i++;
            row--;
            col--;
            // if not diagonally, it must have come either from left or above
        }
        else if (lcs_table[row][col] == lcs_table[row - 1][col])
        {
            row--;
        }
        else if (lcs_table[row][col] == lcs_table[row][col - 1])
        {
            col--;
        }
    } while (lcs_table[row][col] != 0);
    lcs_string[lcs_i] = '\0';
    // setting the last element+1 as \0 to terminate the string
    
    // reversing the subsequence so it is in the right order
    char *p = lcs_string;
    char *p_end = lcs_string + lcs_i - 1;
    char temp;
    while (p < p_end)
    {
        temp = *p;
        *p++ = *p_end;
        *p_end-- = temp;
    }
    
    for (int k = 0; k < s2_len + 1; k++)
    {
        free(lcs_table[k]);
    }
    free(lcs_table);
}

// Functionality 3: Compute an LPS for the second string
// this is done by finding the LCS between a string and its reverse
void lps(char s[])
{
    // edge case the string is empty
    if (strlen(s) == 0)
    {
        printf("# an LPS (length = 0) for the second sequence is: \n");
        return;
    }
    char *lpsString = (char *)malloc((MAX) * sizeof(char));
    char *s_reversed = (char *)malloc(MAX * sizeof(char));

    // create a string that is the reverse of s
    int j = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        s_reversed[j++] = s[i];
    }
    s_reversed[j] = '\0'; // correctly terminates the string with a NULL

    // to find longest palindrome, find the longest common subsequence between string and
    // revered version of itself

    lcs(s, s_reversed, lpsString);

    printf("# an LPS (length = %d) for the second sequence is: \n%s\n", (int)strlen(lpsString), lpsString);

    free(lpsString);
    free(s_reversed);
}

// Functionality 2: Compute an LTS for the first string
// This is done by splitting the string into left and right, then finding the
// LCS between the right and left side
void lts(char s[])
{
    // edge case the string is empty
    if (strlen(s) == 0)
    {
        printf("# an LTS (length = 0) for the first sequence is: \n");
        return;
    }
    int pivot = 0; // index which splits the string
    int pivotDistance = 1; // how many indexes away from index we split
    int  s_len = strlen(s);
    int len_max = 0; // max LTS length
    
    
    char *s_right = (char *)malloc( MAX * sizeof(char));
    char *s_left = (char *)malloc( MAX * sizeof(char));
    char *ltsString = (char *)malloc( MAX * sizeof(char));
    ltsString[0] = '\0';
    char *lts_temp = (char *)malloc( MAX * sizeof(char));


    // assume that the LTS is from splitting the sequence in half.
    // then check either side until one side is equal to the length of the
    // current LTS (because it's impossible afterwards)

    // first find the pivot that gives the largest len
    // done by checking every sqrt()th interval
    float temp, sqrt;
    sqrt = s_len/2;
    temp = 0;
    while (sqrt != temp)
    {
        temp = sqrt;
        sqrt = (s_len/temp + temp) / 2;
    }
    
    int interval = sqrt;
    int i = interval;

    while(i <= s_len - interval)
    {
        // using memset to reset the strings so it doesn't conflict later
        memset(s_left, 0, MAX);
        memset(s_right, 0, MAX);
        strncpy(s_left, s, i);
        strncpy(s_right, s + i, s_len - i);

        lcs(s_left, s_right, lts_temp);
        if (strlen(lts_temp) > len_max)
        {
            strcpy(ltsString, lts_temp); // using = would bind their memory address
            len_max = strlen(ltsString);
            pivot = i;
        }
        memset(lts_temp, 0, MAX);
        i += interval;
    }

    do
    {// now check either side until one side becomes too small
        
        // move the pivot to the right
        memset(s_left, 0, MAX);
        memset(s_right, 0, MAX);
        strncpy(s_left, s, pivot + pivotDistance);
        strncpy(s_right, s + pivot + pivotDistance, (s_len - pivot)-pivotDistance+1);


        lcs(s_left, s_right, lts_temp);

        
        if (strlen(lts_temp) > len_max)
        {
            strcpy(ltsString, lts_temp); // using = would bind their memory address
            len_max = strlen(ltsString);
        }
        memset(lts_temp, 0, MAX);
        
        
        // move the pivot to the left
        
        memset(s_left, 0, strlen(s_left)); // reset both of the char arrays
        memset(s_right, 0, strlen(s_right));
        strncpy(s_left, s, pivot - pivotDistance);
        strncpy(s_right, s + pivot - pivotDistance, (s_len - pivot) + pivotDistance);

        lcs(s_left, s_right, lts_temp);

        if (strlen(lts_temp) > len_max)
        {
            strcpy(ltsString, lts_temp); // using = would bind their memory address
            len_max = strlen(ltsString);
        }
        memset(lts_temp, 0, strlen(lts_temp)); // reset lts_temp
        
        pivotDistance ++;
    } while ((pivotDistance <= interval+1) && (strlen(s_left) > len_max) && (strlen(s_right) > len_max));

    printf("# an LTS (length = %d) for the first seqence is: \n%s%s\n", len_max*2, ltsString, ltsString);
    
    free(s_left);
    free(s_right);
    free(ltsString);
    free(lts_temp);
}
