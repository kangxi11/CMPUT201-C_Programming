#include <stdio.h>

int main(int argc, char ** argv)
{
	float loan = 0.0;
	float interest_rate = 0.0;
	float monthly_payment = 0.0;
	
	float balance_remaining[4] = {0.0, 0.0, 0.0, 0.0};

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	
	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);
	
	interest_rate = interest_rate / 100 / 12; // /100 to create a percentage and /12 for the monthly
	balance_remaining[0] = loan;

	for (int i = 1; i < 4; i++)
	{
		balance_remaining[i] = (balance_remaining[i-1] - monthly_payment) + interest_rate*(balance_remaining[i-1]);
	}
	
	printf("\nBalance remaining after first payment: $%.2f\n", balance_remaining[1]);
	printf("Balance remaining after second payment: $%.2f\n", balance_remaining[2]);
	printf("Balance remaining after third payment: $%.2f\n", balance_remaining[3]);
	
	return 0;
}
