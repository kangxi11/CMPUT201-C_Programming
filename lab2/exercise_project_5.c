#include <stdio.h>

int main( int argc, char ** argv)
{
	int user_input[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int rows[4] = {0,0,0,0};
	int columns[4] = {0,0,0,0};
	int diagonals[2] = {0,0};
	
	printf("Enter the numbers from 1 to 16 in any order: \n");
	
	for (int i = 0; i < 16; i++)
	{
		scanf("%d", &user_input[i]);
		
		rows[ i / 4] += user_input[i];
		columns[ i - (i/4)*4 ] += user_input[i];
		
		if (i % 5 == 0)
		{
			diagonals[0] += user_input[i];
		} else if (i % 3 == 0)
		{
			diagonals[1] += user_input[i];
		}
		
		
		if ( i % 4 == 0)
		{
			printf("\n");
		}
		printf("%2d ", user_input[i]);
		
	}

	
	printf("\n\nRow sums: %d %d %d %d\n", rows[0], rows[1], rows[2], rows[3]);
	printf("Column sums: %d %d %d %d\n", columns[0], columns[1], columns[2], columns[3]);
	printf("Diagonal sums: %d %d\n", diagonals[0], diagonals[1]);
	return 0;
}
