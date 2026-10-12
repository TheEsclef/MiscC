#include <stdlib.h>
#include <stdio.h>

// initialize values for two items
int X = 1;
int Y = 2;

// dummy integers for storing best solution
int bestX;
int bestY;
int maxProfit;

// Check the restrictions
void checkRestriction(int X, int Y)
{
    // check for both of the restrictions
    if ((X * 2 + Y) <= 20 &&
        (X + Y) <= 12)
    {
        int profit = X + (2 * Y);

        printf("Valid: X=%d Y=%d Profit=%d\n",
               X, Y, profit);

        if (profit > maxProfit)
        {
            maxProfit = profit;
            bestX = X;
            bestY = Y;
        }
    }
}

//  Function to test the values for X and Y combinations to check whether or not they're legit
//  Increments X by 1, then Y by 1, 20 times.
//  X = 1; Y = 1; | X = 1; Y = 2; | X = 1; Y = 3 | ... | X = 2; Y = 1; | X = 2; Y = 2 | ETC.
// Test all X and Y combinations
void testValues(int X, int Y)
{
    for (X = 0; X <= 20; X++)
    {
        for (Y = 0; Y <= 20; Y++)
        {
            checkRestriction(X, Y);
        }
    }
}

int main()
{
    testValues(X, Y);

    printf("\nBest solution found:\n");
    printf("X1 = %d\n", bestX);
    printf("X2 = %d\n", bestY);
    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}