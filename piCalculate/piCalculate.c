#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

// N is for how many points are generated, Z is a dummy integer for how many of them are in the quartercircle
int N = 100000;
int Z;

void generatePoints(int N){
    for (int i = 0; i < N; i++){
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x*x+y*y < 1.0)
            Z++;
    }
}

int main(){
    // set a random seed for RNG
    srand(time(NULL));

    generatePoints(N);
    double pi = 4.0 * ((double)Z / N);

    printf("Pi = %.10f", pi);
    return 0;
}