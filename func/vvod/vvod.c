#include "vvod.h"
#include <stdio.h>
void vvodMass(double arr[], int size) {
    if(size < 1) {
        printf("Массив должен быть больше 1 элента!");
    } else {
        for (int i = 0; i < size; i++) {
            printf("Введите элемент %d:", i + 1);
            scanf("%lf", &arr[i]);
        }
        printf("Массив заполнен\n");
    }

}