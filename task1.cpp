//
// Created by liya on 22.02.17.
//




#include <iostream>
#include <omp.h>

using namespace std;

int main(){

#pragma omp parallel  num_threads(8)
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        printf("Hello World from thread = %d; number of threads = %d\n", tid, nthreads);

    }
}