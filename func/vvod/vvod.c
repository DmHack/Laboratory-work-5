#include "vvod.h"
#include <stdio.h>
void vvodMass(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите элемент %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }
    printf("Массив введёт\n");
}