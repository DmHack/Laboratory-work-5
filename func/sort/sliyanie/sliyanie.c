#include <stdio.h>

void merge(double mass[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = mass[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = mass[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            mass[k] = L[i];
            i++;
        } else {
            mass[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mass[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        mass[k] = R[j];
        j++;
        k++;
    }
}
int count = 0;

int mergeSort(double mass[], int left, int right, int vv) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(mass, left, mid, vv);
        mergeSort(mass, mid + 1, right, vv);
        merge(mass, left, mid, right);
        count++;
        if (vv == 1) {
            printf("После итерации %d: ", count); // Выводим текущий счетчик итераций
            for (int k = left; k <= right; k++) {
                printf("%lf ", mass[k]);
            }
            printf("\n");
        }
    }
    return count;
}
