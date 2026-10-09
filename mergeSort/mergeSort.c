#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For merging the numbers in the array
void merge(int array[], int left, int mid, int right)
{
    int i, j, k;             // Temporary variables for logic
    int n1 = mid - left + 1; // variable to store the amount of numbers to the left
    int n2 = right - mid;    // variable to store the amount of numbers to the right

    // create temporary array to store the two halves
    // Set the length with n1 and n2 aka how many numbers are to the left and to the right
    int leftArray[n1], rightArray[n2];

    // Copy the data to the temporary arrays
    for (i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into the array
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// The subarrays are sorted with the index range [left - right]
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {

        // Calculate the mid point
        int mid = left + (right - left) / 2;

        // Sort the first and second half
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

int main()
{
    int numbers[] = {69, 20, 50, 11, 5, 3, 88, 3, 12, 50, 80, 100, 200, 150, 133, 121, 195, 103, 1952, 1951, 2952, 2999};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    mergeSort(numbers, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}