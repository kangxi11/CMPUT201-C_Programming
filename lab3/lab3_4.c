#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv)
{
	float loan = 0.0;
	float interest_rate = 0.0;
	float monthly_payment = 0.0;
  int numPayments = 0;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

  printf("Enter the number of payments: ");
  scanf("%d", &numPayments);

  float balance_remaining[numPayments+1];

	interest_rate = interest_rate / 100 / 12; // /100 to create a percentage and /12 for the monthly
	balance_remaining[0] = loan;

	for (int i = 1; i < numPayments+1; i++)
	{
		balance_remaining[i] = (balance_remaining[i-1] - monthly_payment) + interest_rate*(balance_remaining[i-1]);
	}

  for (int i = 1; i < numPayments+1; i++)
  {
    printf("Balance remaining after payment %d: $%.2f\n", i, balance_remaining[i]);
  }

	return 0;
}
