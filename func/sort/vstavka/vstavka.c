#include <stdio.h>

void vstavkaSortBez(double arr[], int size, int *iterations) {
    double key;
    int j;
    *iterations = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        (*iterations)++;
    }
}

void vstavkaSort(double arr[], int size, int *iterations) {
    double key;
    int j;
    *iterations = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        (*iterations)++;
        printf("После итерации %d: ", i);
        for (int k = 0; k < size; k++) {
            printf("%f ", arr[k]);
        }
        printf("\n");

    }
}