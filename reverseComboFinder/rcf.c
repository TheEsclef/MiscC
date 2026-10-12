#include <stdio.h>

// Recursive function to check for combinations
void backtrack(int numbers[], int n, int target,
               int combination[], int size,
               int start, int sum) {

    // If a valid combination has been found
    if (sum == target) {
        printf("[ ");
        // Print out every number in the combination
        for (int i = 0; i < size; i++) {
            printf("%d ", combination[i]);
        }
        printf("]\n");
        return;
    }

    // If the sum got too big
    if (sum > target) {
        return;
    }

    // Try out all the possible combinations
    for (int i = start; i < n; i++) {
        combination[size] = numbers[i];

        backtrack(numbers, n, target,
                  combination, size + 1,
                  i,                  // We can pass through the same number again
                  sum + numbers[i]);
    }
}

int main() {
    // Initialize the values
    int numbers[] = {2, 3, 6, 7};
    int target = 7;
    int combination[100];

    // Call the function
    backtrack(numbers, 4, target,
              combination, 0, 0, 0);

    return 0;
}