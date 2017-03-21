//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {

    int n = 8;
    int needed_thread = n - 1;

#pragma omp parallel for num_threads(8) ordered
    for (int i = n; i > 0; i--) {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

#pragma omp ordered
        {
            printf("Hello World from thread = %d; number of threads = %d\n", tid, nthreads);
        }
    }
}




