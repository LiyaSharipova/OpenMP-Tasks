//
// Created by liya on 01.03.17.
//


#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int n = 10;
    int a[n] = {0, 1, 2, 3, 4, 5, 6, -6, 8, 9};
    int b[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
    int avg_a, avg_b;
#pragma omp parallel for reduction()
    {
        for (int i = 0; i < n; ++i) {

        }
    }

}

