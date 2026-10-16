#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MIN_X -10.0
#define MAX_X 10.0

// Objective function
double f(double x)
{
    return x * x + 10.0 * sin(x);
}

// Generate a random number in the range [0, 1]
double randomDouble()
{
    return (double)rand() / RAND_MAX;
}

int main()
{
    srand(time(NULL));

    // Initial random solution
    double currentX = MIN_X + randomDouble() * (MAX_X - MIN_X);
    double currentValue = f(currentX);

    // Store the best solution found
    double bestX = currentX;
    double bestValue = currentValue;

    // Simulated Annealing parameters
    double temperature = 100.0;
    double coolingRate = 0.995;
    double minTemperature = 0.0001;

    while (temperature > minTemperature)
    {

        // Generate a neighboring solution
        double newX = currentX + (randomDouble() * 2.0 - 1.0);

        // Keep x within the allowed range
        if (newX < MIN_X)
            newX = MIN_X;
        if (newX > MAX_X)
            newX = MAX_X;

        double newValue = f(newX);

        // Difference between the new and current solution
        double delta = newValue - currentValue;

        // Always accept better solutions
        if (delta < 0)
        {
            currentX = newX;
            currentValue = newValue;
        }
        // Sometimes accept worse solutions based on temperature
        else
        {
            double probability = exp(-delta / temperature);

            if (randomDouble() < probability)
            {
                currentX = newX;
                currentValue = newValue;
            }
        }

        // Update the best solution found
        if (currentValue < bestValue)
        {
            bestValue = currentValue;
            bestX = currentX;
        }

        // Gradually reduce the temperature
        temperature *= coolingRate;
    }

    printf("Best x found = %f\n", bestX);
    printf("f(x) = %f\n", bestValue);

    return 0;
}