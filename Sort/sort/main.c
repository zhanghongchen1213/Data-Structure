#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

#define N 10

int main() {
    int data[N] = {0};
    srandom(10);
    for (int i = 0; i < N; ++i) {
        data[i] = random() % 100;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", data[i]);
    }
    puts(" ");
    quicksort(data, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        printf("%d ", data[i]);
    }
    puts(" ");
}
