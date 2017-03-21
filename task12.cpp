//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int n = 40;
    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
    }
    int max_7 = 0;
#pragma omp parallel for num_threads(4)
    for (int i = 0; i < n; ++i) {
#pragma omp critical
        {
            if (a[i] % 7 == 0 && a[i] > max_7) {

                max_7 = a[i];
            }

        }
    }
    printf("%d is the max value devided by 7", max_7);
}
