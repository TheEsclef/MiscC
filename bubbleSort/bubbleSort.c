#include <stdio.h>

int array[] = {20, 10, 22, 6, 30, 99};
int length = sizeof(array) / sizeof(array[0]);

void bubbleSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {

            // Swap if elements are in the wrong order
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    bubbleSort(array, length);
    
    return 0;
}