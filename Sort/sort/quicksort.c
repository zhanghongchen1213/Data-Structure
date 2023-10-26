//
// Created by k on 23-10-7.
//

#include "quicksort.h"
#include <stdio.h>

int quicksort(int *data, int low, int high) {
    if (data == NULL || low < 0 || high < 0 || low >= high) {
        return -1;
    }
    int t = partion(data, low, high);
    quicksort(data, low, t - 1);
    quicksort(data, t + 1, high);
    return 0;
}

int partion(int *data, int low, int high) {
    int temp = data[low];
    while (low < high) {
        while (temp <= data[high] && low < high)
            high--;
        data[low] = data[high];
        while (data[low] <= temp && low < high)
            low++;
        data[high] = data[low];
    }
    data[low] = temp;
    return low;
}