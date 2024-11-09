#include <stdio.h>

void copyMass(double* original, int size, double* copy) {
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }
}
