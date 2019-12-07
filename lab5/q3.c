#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void)
// returns a random int betwenn 1 and 6
{
    return (rand() % 6);
}
bool play_game(void)
// plays 1 game. Return TRUE if player wins and FALSE if player loses
{
    int player_win[2] = {7, 11};
    int player_lose[3] = {2, 3, 12};
    int point;
    int roll;
    int point_lose = 7;

    bool result = false;

    point = roll_dice() + roll_dice() + 2;

    printf("You rolled: %d\n", point);

    if (point == player_win[0] || point == player_win[1])
    {
        printf("You win!\n");
        result = true;
    } else if (point == player_lose[0] || point == player_lose[1] || point == player_lose[2])
    {
        printf("You lose!\n");
    } else
    {
        printf("Your point is %d\n", point);

        do
        {
            roll = roll_dice() + roll_dice() + 2;
            printf("You rolled: %d\n", roll);

        } while (roll != point_lose && roll != point);

        if (roll == point_lose)
        {
            printf("You lose!\n");
        } else if (roll == point)
        {
            printf("You win!\n");
            result = true;
        }
    }
    return result;

}
int main(int argc, char ** argv)
{
    srand((unsigned)time(NULL));

    char exit;
    int win = 0;
    int lose = 0;


    do
    {
        if (play_game())
        {
            win++;
        } else
        {
            lose++;
        }


        printf("Play again? ");
        scanf(" %c", &exit);
        printf("\n");

    } while (exit == 'y' || exit == 'Y');

    printf("Wins: %d  Losses: %d\n", win, lose);
    
    return 0;
}