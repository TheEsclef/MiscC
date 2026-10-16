#include <stdio.h>
#include "../mergeSort/mergeSort.c"
#include "../bubbleSort/bubbleSort.c"

int array[] = {10, 2, 9, 122, 50, 99};

int returnFirst(int array[]){
    return array[0];
}

int binarySearch(int array[], int index){
    int length = sizeof(array) / sizeof(array[0]);
    mergeSort(array, 0, length - 1);

    return array[index];
}

int sumOfArray(int array[]){
    int length = sizeof(array) / sizeof(array[0]);
    int x;
    for(int i = 0; i < length; i++){
        x += array[i];
    }

    return x;
}

int bubbleSort(int array[]){
    int length = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, length);
    
    return array;
}