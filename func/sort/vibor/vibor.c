#include <stdio.h>

void viborMassBez(double arr[], int size, int *iterations) {
    int minIndex;
    double temp;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        (*iterations)++;

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

    }
}

void viborMass(double arr[], int size, int *iterations) {
    int minIndex;
    double temp;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        (*iterations)++;
        printf("После итерации %d: ", i);
        for (int k = 0; k < size; k++) {
            printf("%f ", arr[k]);
        }
        printf("\n");

    }
}