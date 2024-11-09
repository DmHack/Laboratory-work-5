#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <sys/time.h>

#include "func/vvod/vvod.h"
#include "func/randvVod/randVvod.h"
#include "func/goBack/goBack.h"
#include "func/sort/vstavka/vstavka.h"
#include "func/copyMass//copyMass.h"
#include "func/vuvod/vuvod.h"
#include "func/sort/vibor/vibor.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size, vubor;
    int goBac = 0;
    bool whProd = true;
    double *array;
    double* copyArray;
    int cont = 0;
    while (whProd) {
        goBac = 0;
        vubor = 0;
        switch (cont) {
            case 0: {
                printf("Введите количество элементов массива:");
                scanf("%d", &size);
                array = (double *) malloc(size * sizeof(double));
                copyArray = (double*)malloc(size * sizeof(double));
                cont++;
            }; break;

            case 1: {
                goBack("ввод размера массива?", &goBac);

                if (goBac == 1) {
                    cont--;
                } else if (goBac == 0) {
                    printf("Выберите способ генерации массива(вручную - 0, рандомно - 1):");
                    scanf("%d", &vubor);
                    if (vubor == 0) {
                        vvodMass(array, size);
                        cont++;
                    } else if (vubor == 1) {
                        printf("Нужны ли границы для генерации случайных чисел? (0 - нет, 1 - да):");
                        scanf("%d", &vubor);
                        if (vubor == 0) {
                            vvodMassRand(array, size);
                            cont++;
                        } else if (vubor == 1) {
                            double vverh, niz;
                            printf("Введите верхнюю границу:");
                            scanf("%lf", &vverh);
                            printf("Введите нижнюю границу:");
                            scanf("%lf", &niz);
                            vvodMassRandGran(array, size, vverh, niz);
                            cont++;
                        }

                    }
                }
            }; break;

            case 2: {
                goBack("генерация массива", &goBac);
                if (goBac == 1) {
                    cont--;
                } else if (goBac == 0) {
                    printf("\nВыберите способ сортировки или другие алгоритмы:\nСортировки:\n1)Вставками\n2)Выбором\n3)Пузырьком без модификаци\n4)Пузырьком с модификациями\n5)Сортировка подсчетом для целых чисел\n6)Слиянием (рекурсивная версия)\n7)Быстрая сортировка (сортировка Хоара)\n");
                    printf("\nДругие алгоритмы:\n8)Линейный поиск\n9)Бинарный поиск\n10)Слияние двух отсортированных массивов\n");
                    scanf("%d", &vubor);
                    int vuborProm = 0;
                    int iterations = 0;
                    copyMass(array, size, copyArray);
                    long seconds_start, seconds_end, microseconds_start, microseconds_end;
                    struct timeval start, end;
                    switch (vubor) {
                        case 1: {
                            printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                            scanf("%d", &vuborProm);
                            if (vuborProm == 0) {
                                gettimeofday(&start, NULL);
                                vstavkaSortBez(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            } else if (vuborProm == 1) {
                                gettimeofday(&start, NULL);
                                vstavkaSort(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            }
                        }; break;
                        case 2: {
                            printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                            scanf("%d", &vuborProm);
                            if (vuborProm == 0) {
                                gettimeofday(&start, NULL);
                                viborMassBez(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            } else if (vuborProm == 1) {
                                gettimeofday(&start, NULL);
                                viborMass(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            }

                        }
                        case 3: {
                            printf("Выводить промежуточные изменения массива после итераций сортировки?(0 - нет, 1 - да):");
                            scanf("%d", &vuborProm);
                            if (vuborProm == 0) {
                                gettimeofday(&start, NULL);
                                viborMassBez(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            } else if (vuborProm == 1) {
                                gettimeofday(&start, NULL);
                                viborMass(copyArray, size, &iterations);
                                gettimeofday(&end, NULL);

                                seconds_start = start.tv_sec;
                                microseconds_start = start.tv_usec;
                                seconds_end = end.tv_sec;
                                microseconds_end = end.tv_usec;
                                double time_spent = (seconds_end - seconds_start) + (microseconds_end - microseconds_start) / 1000000.0;

                                vuvodMass(copyArray, size);
                                printf("\nВремя сортировки: %.6f секунд\n", time_spent);
                                printf("Количество итераций: %d\n", iterations);
                                cont++;
                            }
                        }
                }
            }; break;

            case 3: {
                int prodol = 0;
                printf("\nПродолжить работу(0 - нет, 1 - да):");
                scanf("%d", &prodol);
                if (prodol) {
                    printf("Использовать тот же массив? (0 - нет, 1 - да)");
                    scanf("%d", &prodol);
                    printf("%d", prodol);
                    if (prodol) {
                        cont = 2;
                    } else {
                        cont = 0;
                    }
                } else {
                    whProd = false;
                }
            }; break;
            default:
            {}
        }
    }
}}
