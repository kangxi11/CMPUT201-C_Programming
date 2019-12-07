#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	unsigned int user_input = 0;
	unsigned int bills[4] = {20, 10, 5, 1};
	unsigned int bills_split[4] = {0, 0, 0, 0};
	
	printf("Enter a dollar amount: ");
	scanf("%d", &user_input);	
	
	for (int i = 0; i < 4; i++)
	{
		bills_split[i] = user_input / bills[i];
		user_input -= bills_split[i] * bills[i];
	}


	printf("\n$20 bills: %d\n", bills_split[0]);
	printf("$10 bills: %d\n", bills_split[1]);
	printf(" $5 bills: %d\n", bills_split[2]);
	printf(" $1 bills: %d\n", bills_split[3]);
	
	
	
	
	

	return 0;
}
