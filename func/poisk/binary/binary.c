#include <stdio.h>

int binarySearch(double array[], int size, double tr) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left +  (right - left) / 2;
        if (array[mid] == tr) {
            return mid;
        }
        if (array[mid] > tr) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}