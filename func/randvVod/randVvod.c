#include "randVvod.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vvodMassRand(double* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = (double)(rand() % 1000) + (double)rand() / RAND_MAX;
    }
}

void vvodMassRandGran(double* arr, int size, double vverh, double niz) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = niz + (double)rand() / RAND_MAX * (vverh - niz);
    }
}
