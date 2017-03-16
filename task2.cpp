//
// Created by liya on 22.02.17.
//

#include <omp.h>
#include <iostream>

int printThreadIdAndNum (int size){
#pragma omp parallel num_threads(size) if(size>1)
    {
        int tid, nthreads;
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("thread = %d; number of threads = %d\n", tid, nthreads);
    }
}

int main() {
    int tid, nthreads;

    int size1 = 3;
    int size2 = 1;
//    printThreadIdAndNum(size1);
//    printThreadIdAndNum(size2);

#pragma omp parallel num_threads(size1) if(size1>1)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("thread = %d; number of threads = %d\n", tid, nthreads);
    }
#pragma omp parallel num_threads(size2) if(size2>1)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("thread = %d; number of threads = %d\n", tid, nthreads);
    }
}