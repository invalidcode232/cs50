#include <stdio.h>
#include <cs50.h>

int main(void) {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int smallest = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                //smallest = arr[i];
                //arr[j] = smallest;
                //arr[j] = arr[i];

                smallest = arr[j];
                arr[j] = arr[i];
                arr[i] = smallest;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%i, ", arr[i]);
    }

    printf("\n");
}