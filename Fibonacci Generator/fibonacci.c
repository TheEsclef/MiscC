#include <stdio.h>

int main()
{
    void fibonacci()
    {
        int x = 1;
        int y = 0;
        int z;
        int amount;

        printf("input the amount of numbers (1 - 46) \n");
        scanf("%d", &amount);
        for (int i = 1; i < amount; i++)
        {
            z = x + y;
            y = x;
            x = z;
            printf("%d \n", z);
        }
    }

    fibonacci();
}