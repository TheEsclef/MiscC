#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#define MAX_COUNT 93      // This sets the max amount of different ASCII characters one can use
#define MAX_PASS_LENGTH 5 // This changes the length of the randomly generated Password

char AsciiArray[MAX_COUNT] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1203495687.!-@*_$#/,+%&?;=~^)[\\]`(:<'>|\"";
char guessPass[MAX_PASS_LENGTH + 1]; // Create a char to store the guess password
char password[MAX_PASS_LENGTH + 1];  // Create a char to store the dummy password
uint64_t guessAmount;                // Useless info for seeing how long it took to crack | using uint64_t for big integer

// This is a generic function for generating a randomized password
void generatePassword()
{
    for (int i = 0; i < MAX_PASS_LENGTH; i++)
    {
        password[i] = AsciiArray[rand() % MAX_COUNT]; // starting from "a", ending with "
    }
    password[MAX_PASS_LENGTH] = '\0';
}

// A function for bruteforcing an ASCII password
void bruteForce(int position)
{
    if (position == MAX_PASS_LENGTH)
    {
        guessPass[MAX_PASS_LENGTH] = '\0';

        if (strcmp(guessPass, password) == 0) // if the guesspass equals password
        {
            printf("\nFound: %s\n", guessPass);
            printf("\nIt only took: %llu tries", guessAmount);
            exit(0);
        }

        return;
    }

    for (int i = 0; i < MAX_COUNT; i++, guessAmount++)
    {
        guessPass[position] = AsciiArray[i];
        bruteForce(position + 1);
    }
}

int main()
{
    srand(time(NULL));                            // set the random seed for RNG based on time
    generatePassword();                           // Call the generate password function
    printf("Generated password: %s\n", password); // print out the generated password for easier control
    bruteForce(0);                                // call the bruteForce function

    return 0;
}