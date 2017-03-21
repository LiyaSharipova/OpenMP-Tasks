//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>

int main() {
    int n = 12;
    int a[n], b[n], c[n];
#pragma omp parallel for schedule(static, 3) num_threads(3)
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        b[i] = i;
        printf("num_threads = %d; id = %d; a,b[%d] = %d \n", omp_get_num_threads(), omp_get_thread_num(), i, a[i] );
    }
printf("========================================\n");

#pragma omp parallel for  schedule(dynamic, 3) num_threads(4)
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
        printf("num_threads = %d; id = %d; c[%d] = %d \n", omp_get_num_threads(), omp_get_thread_num(), i, c[i] );

    }


}
