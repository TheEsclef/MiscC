#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

// Find the middle element
float findMedian(int arr[], int n){
    qsort(arr, n, sizeof(int), compare);

    // if even, median is the average of two
    // middle elements
    if (n % 2 == 0){
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }

    // If odd, median is the middle element
    else {
        return arr[n / 2];
    }
}

int main(){
    // initialize arrays and get the length of the array
    int arr[] = {7, 2, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // get the median
    float m = findMedian(arr, n);

    printf("%.2f\n", m);
    return 0;
}