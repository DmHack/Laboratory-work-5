#include <stdio.h>

void vuvodMass(double mass[], int size) {
    printf("Вывод массива:\n");
    for (int i = 0; i < size; i++) {
        printf("%lf ", mass[i]);
    }
}