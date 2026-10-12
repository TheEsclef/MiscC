#include <stdlib.h>
#include <stdio.h>

// Create the cashier's list of coins and the amount of money to return
int coins[] = {50, 20, 10, 5, 2, 1};
int length = sizeof(coins) / sizeof(coins[0]);

int returnAmount = 87;
int moneyReturned = 0;
int returnedCoins[100];

int main()
{
    int x = 0;

    while (moneyReturned < returnAmount)
    {
        for (int i = 0; i < length; i++)
        {
            if (coins[i] + moneyReturned <= returnAmount)
            {
                moneyReturned += coins[i];
                returnedCoins[x] = coins[i];
                x++;
                break;
            }
        }
    }


    printf("Coins used: ");
    for (int i = 0; i < x; i++){
        printf("%d ", returnedCoins[i]);
    }

    printf("\nReturned amount: %d\n", moneyReturned);
    return 0;
}