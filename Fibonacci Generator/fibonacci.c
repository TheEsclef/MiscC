#include<stdio.h>

int main(){

    int x = 1;
    int y = 0;
    int z;
    int amount = 10;
    for(int i = 1; i < amount; i++)
    {
        z = x + y;
        y = x;
        x = z;
        printf("%d \n", z);
    }   
}