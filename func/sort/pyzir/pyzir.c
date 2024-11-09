#include <stdio.h>

void pyzir(double arr[], int size, int *iterations, int vv) {
    int i, j;
    double temp;
    *iterations = 0; // Инициализируем количество итераций

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами элементы
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        (*iterations)++;
        if (vv == 1) {
            printf("\nПосле итерации %d: ", i);
            for (int k = 0; k < size; k++) {
                printf("%f ", arr[k]);
            }
        }

    }
}



void pyzirMod(double arr[], int size, int *iterations, int vv) {
    int i, j, temp;
    *iterations = 0;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        (*iterations)++;
        if (vv == 1) {
            printf("\nПосле итерации %d: ", i);
            for (int k = 0; k < size; k++) {
                printf("%f ", arr[k]);
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

