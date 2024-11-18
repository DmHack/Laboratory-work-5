#include <stdio.h>

int partition(double array[], int low, int high) {
    double pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            double temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    double temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

int count1 = 0;
int quickSort(double array[], int low, int high, int vv) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1, vv);
        quickSort(array, pi + 1, high, vv);
        count1++;
        if (vv == 1) {
            printf("После итерации %d: ", count1);
            for (int k = 0; k < high + 1; k++) {
                printf("%f ", array[k]);
            }
            printf("\n");
        }
    }

    return count1;
}