/*
Submitting student: Ryan Kang (1543686)

Collaborating Classmates: N/A

Other collaborators: N/A

References:
  Tushar Roy
  https://www.youtube.com/watch?v=NnD96abizww
  Video explaining the math of the problem, no coding was done
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void lcs(char s1[], char s2[]);

int main(int argc, char ** argv)
{
  char *s1 = (char *)malloc(10000 * sizeof(char));
  char *s2 = (char *)malloc(10000 * sizeof(char));

  int s1_received;
  int s2_received;
  // will get 1 if scanf reads in an input, -1 if nothing is entered

  _Bool error = false;
  // checking that the sequences only contain 0-9 digits

  // Functionality 1 and Functionality 2
  do
  {
    error = false; //reset error eveytime we read in inputs

    printf("To compute an LCS,\nenter the first sequence: ");
    s1_received = scanf("%1000s", s1);

    if (s1_received == 1)
    {
      for (int i = 0; i < strlen(s1) ; i++)
      { // we use ascii to compare characters and scanf's return value to check
        // if the user inputed anything. Should only be 1 input at a time
        if (s1[i] < '0' || s1[i] > '9')
        {
          printf("Error, non-digit character detected!\n");
          error = true;
        }
      }
    }

    if (error == true)
    {
      continue; // don't read in the second sequence
    }

    printf("enter the second sequence: ");
    s2_received = scanf("%1000s", s2);

    if (s2_received == 1)
    {
      for (int i = 0; i < strlen(s2) ; i++)
      {
        if (s2[i] < '0' || s2[i] > '9')
        {
          printf("Error, non-digit character detected!\n");
          error = true;
        }
      }
    }
  } while (error == true); // keeps going until no errors are foun

  lcs(s1, s2);
  return 0;
}

void lcs(char s1[], char s2[])
{
  // finding the LCS of the two sequence of numbers
  int s1_len = strlen(s1);
  int s2_len = strlen(s2);

  char *lcs_string = (char *)malloc(10000 * sizeof(char));
  int lcs_i = 0;

  int **lcs_table = (int **)malloc((s2_len + 1) * sizeof(int *)); // [rows][columns]
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
  // Functionality 4
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

  for (int i = strlen(lcs_string) - 1; i >= 0; i--)
  {
    printf("%c", lcs_string[i]);
  }
  printf("\n");

  free(lcs_string);
  free(lcs_table);
}