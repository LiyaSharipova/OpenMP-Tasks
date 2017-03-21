//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>

int main() {
    double start = omp_get_wtime();

    int n = 1600;
    int a[n], b[n];

#pragma omp parallel num_threads(8)
    {
//#pragma omp for schedule(static, 15) num_threads(8)
//#pragma omp for schedule(dynamic, 15) num_threads(8)
//#pragma omp for schedule(guided, 15) num_threads(8)
#pragma omp for schedule(auto)
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
//#pragma omp for schedule(static, 15) num_threads(8)
//#pragma omp for schedule(dynamic, 15) num_threads(8)
//#pragma omp for schedule(guided, 15) num_threads(8)
#pragma omp for schedule(auto)
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                b[i] = i;
            } else {
                b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
            }
        }


    }
    double end = omp_get_wtime();
    printf("Time = %.16g\n", end - start);

    printf("===========================\n");

    printf("Average results for : \nstatic = 0,001096011\ndynamic = 0,00031841\nguided = 0,000286057\nauto = 0,000315018");
}

