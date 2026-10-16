#include <stdio.h>

// Function for dy/dx = x + y
double f(double x, double y)
{
    return x + y;
}

int main()
{
    double x = 0.0;     // Starting x value
    double y = 1.0;     // Initial condition y(0) = 1
    double h = 0.2;     // Step size

    printf("Euler Method\n");
    printf("x\t y\n");
    printf("%.1f\t %.4f\n", x, y);

    // Calculate values from x = 0 to x = 1.0
    while (x < 1.0)
    {
        // Euler formula:
        // y_new = y_old + h * f(x, y)
        y = y + h * f(x, y);

        // Move to next x value
        x = x + h;

        printf("%.1f\t %.4f\n", x, y);
    }

    return 0;
}