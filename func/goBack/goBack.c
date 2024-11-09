#include <stdio.h>


void goBack(char* name, int* goBack) {
    printf("\nХотите вернуться на предыдущий шаг - %s (0 - нет, 1 - да):", name);
    scanf("%d", goBack);
}