#include <stdio.h>
#include <stdlib.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(int argc, char **argv)
{
    unsigned int user_input = 0;

    int twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &user_input);

    pay_amount(user_input, &twenties, &tens, &fives, &ones);

    printf("\n$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf(" $5 bills: %d\n", fives);
    printf(" $1 bills: %d\n", ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    unsigned int bills_split[4] = {0, 0, 0, 0};
    unsigned int bills[4] = {20, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        bills_split[i] = dollars / bills[i];
        dollars -= bills_split[i] * bills[i];
    }

    *twenties = bills_split[0];
    *tens = bills_split[1];
    *fives = bills_split[2];
    *ones = bills_split[3];
}
