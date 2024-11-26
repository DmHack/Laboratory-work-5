#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "func/vvod/vvod.h"
#include "func/randvVod/randVvod.h"
#include "func/sort/vstavka/vstavka.h"
#include "func/copyMass//copyMass.h"
#include "func/vuvod/vuvod.h"
#include "func/sort/vibor/vibor.h"
#include "func/sort/pyzir/pyzir.h"
#include "func/sort/counting/counting.h"
#include "func/sort/sliyanie/sliyanie.h"
#include "func/sort/quickSort/quickSort.h"
#include "func/isSorted/isSorting.h"
#include "func/poisk/lineal/lineal.h"
#include "func/poisk/binary/binary.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size, vubor;

    bool whProd = true;
    double* array;
    double* copyArray;

    int cont = 0;
    while (whProd) {
        printf("\nМеню:\n");
        printf("1. Ввести количество элементов массива\n");
        printf("2. Заполнить массив\n");
        printf("3. Cпособ сортировки\n");
        printf("4. Другие алгоритмы\n");
        printf("5. Выход\n");
        printf("Выберите опцию:");
        scanf("%d", &cont);
        vubor = 0;
        switch (cont) {
            case 1: {
                printf("Введите количество элементов массива:");
                scanf("%d", &size);
                if(size < 1) {
                    printf("Массив должен быть больше 1 элента!");
                    break;
                }
                array = (double *) malloc(size * sizeof(double));
                copyArray = (double*)malloc(size * sizeof(double));
                cont++;
            }; break;

            case 2: {
                    printf("Выберите способ генерации массива(вручную - 0, рандомно - 1):");
                    scanf("%d", &vubor);
                    if (vubor == 0) {
                        vvodMass(array, size);
                        cont++;
                        break;
                    } else if (vubor == 1) {
                        printf("Нужны ли границы для генерации случайных чисел? (0 - нет, 1 - да):");
                        scanf("%d", &vubor);
                        if (vubor == 0) {
                            vvodMassRand(array, size);
                            cont++;
                            break;
                        } else if (vubor == 1) {
                            double vverh, niz;
                            printf("Введите верхнюю границу:");
                            scanf("%lf", &vverh);
                            printf("Введите нижнюю границу:");
                            scanf("%lf", &niz);
                            vvodMassRandGran(array, size, vverh, niz);
                            cont++;
                            break;
                        }

                    }
                }
            case 3: {
                if(size < 1) {
                    printf("Массив должен быть больше 1 элента!");
                    break;
                }
                else {
                    printf("\nВыберите способ сортировки или другие алгоритмы:\nСортировки:\n1)Вставками\n2)Выбором\n3)Пузырьком без модификаци\n4)Пузырьком с модификациями\n5)Сортировка подсчетом для целых чисел\n6)Слиянием (рекурсивная версия)\n7)Быстрая сортировка (сортировка Хоара)\n");
                scanf("%d", &vubor);
                int vuborProm = 0;
                int iterations = 0;
                copyMass(array, size, copyArray);

                switch (vubor) {
                    clock_t start, end;
                    case 1: {
                        printf("Сортировка вставками\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);

                        start = clock();
                        vstavkaSort(copyArray, size, &iterations, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("Количество итераций: %d\n", iterations);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 2: {
                        printf("Сортировка выбором\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        viborMass(copyArray, size, &iterations, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("Количество итераций: %d\n", iterations);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 3: {
                        printf("Сортировка пузырьком без модификаций\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        pyzir(copyArray, size, &iterations, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("Количество итераций: %d\n", iterations);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 4: {
                        printf("Сортировка пузырьком с модификациями\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        pyzirMod(copyArray, size, &iterations, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("Количество итераций: %d\n", iterations);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 5: {
                        printf("Сортировка подсчетом для целых чисел\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        counting(copyArray, size, &iterations, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("Количество итераций: %d\n", iterations);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 6: {
                        printf("Сортировка слиянием (рекурсивная версия)\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        int fg = mergeSort(copyArray, 0, size - 1, size, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("\nКоличество итераций: %d\n", fg);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                    case 7: {
                        printf("Быстрая сортировка (сортировка Хоара)\n");
                        printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                        scanf("%d", &vuborProm);
                        start = clock();
                        int fg = quickSort(copyArray, 0, size - 1, vuborProm);
                        end = clock();
                        vuvodMass(copyArray, size);
                        printf("\nКоличество итераций: %d\n", fg);
                        double time = (double) (end - start) / CLOCKS_PER_SEC;
                        printf("Время сортировки: %f секунд\n", time);
                        printf("Массив отсортирован:%s", isSorting(copyArray, size) ? "True" : "False");
                        break;
                    }
                }

                }

            } break;
            case 4: {
                double poiskChislo = 0;
                printf("\n1) Линейный поиск\n");
                printf("2) Бинарный поиск\n");
                scanf("%d", &vubor);
                printf("Введите элемент, который нужно найти:");
                scanf("%lf", &poiskChislo);
                switch (vubor) {
                    case 1: {
                        int chw = linealSearch(copyArray, size, poiskChislo);
                        if (chw != -1) {
                            printf("Индекс: %d", chw);
                        } else {
                            printf("Такого числа нет в массиве");
                        }
                    }
                    case 2: {
                        printf("Массив должен быть отсортирован!\n");
                        int chw = binarySearch(copyArray, size, poiskChislo);
                        if (chw != -1) {
                            printf("Индекс: %d", chw);
                        } else {
                            printf("Такого числа нет в массиве");
                        }
                    }
                }
            }
            case 5: {
                int prodol = 0;
                printf("\nПродолжить работу(0 - нет, 1 - да):");
                scanf("%d", &prodol);
                if (prodol) {
                    printf("Использовать тот же массив? (0 - нет, 1 - да)");
                    scanf("%d", &prodol);
                    if (prodol == 1) {
                        printf("Можете продолжать сортировку с массивом\n");
                    } else {
                        printf("Можете сгенерировать новый массив");
                    }
                } else {
                    whProd = false;
                }
            }
            default:
            {}
        }
    }
}