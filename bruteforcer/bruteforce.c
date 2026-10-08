#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[] = "Beans"; // You can make this as long as you want
char AsciiArray[94];       // create the array for all Ascii Integer values

int main()
{
    for (int i = 0; i < 94; i++) // Loop the function 94 times to get all the Ascii characters (except space)
    {
        AsciiArray[i] = (char)(i + 33); // Turn the integer into an ASCII character and add it to the array
    }

    int lenOfPas = strlen(password);                             // get the length of the password given
    int lenOfArray = sizeof(AsciiArray) / sizeof(AsciiArray[0]); // Get the length of the ASCII array
    int lenOfPass = sizeof(password) / sizeof(password[0]);      // Get the length of the password



    int isSolved = 0;
    while (isSolved == 0)
    {
        
    }

    return 0;
}