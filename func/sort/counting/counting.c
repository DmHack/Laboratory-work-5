#include <stdio.h>
#include <stdlib.h>

void counting(double arr[], int size, int *iterations, int vv) {
    int maxVal = 0;
    for (int i = 0; i < size; i++) {
        if ((int) arr[i] > maxVal) {
            maxVal = (int) arr[i];
        }
    }
    int *count = (int *)calloc(maxVal + 1, sizeof(int));
    int i;

    for (i = 0; i < size; i++) {
        int index = (int)(arr[i]);
        count[index]++;
    }
    int index = 0;
    for (i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = (double)i ;
            count[i]--;
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