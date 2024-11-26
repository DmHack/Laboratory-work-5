#include <stdio.h>

int linealSearch(double array[], int size, double tr) {
    for (int i = 0; i < size; i++) {
        if (array[i] == tr) {
            return i;
        }
    }
    return -1;
}