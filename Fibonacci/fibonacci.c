#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// Create a dummy uint64 for memory storage
// uint64 creates 2 to power of 64 max int (bigint)
uint64_t memo[60] = {0};

// Function that generates fibonacci
uint64_t generateFibonacci(int length){
    if (length == 0)
        return 0;
    if (length == 1)
        return 1;

    // If length isn't 0 return memory at the current position
    if (memo[length] != 0)
        return memo[length];

    // Set the memory's value at position "length" to be a fibonacci number
    memo[length] = generateFibonacci(length - 1) + generateFibonacci(length - 2);

    return memo[length];
}

int main(){
    printf("F(50) = %llu\n", generateFibonacci(50));
    
    return 0;
}