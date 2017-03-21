//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {

    int n = 8;
    int needed_thread = n - 1;

#pragma omp parallel num_threads(8)
    {
        bool b = true;
        int tid = omp_get_thread_num();
        while (b) {

            if (tid == needed_thread) {
                printf("Hello World from thread = %d; number of threads = %d\n", tid, n);
#pragma omp atomic
                needed_thread--;
                b = false;
            }
        }

    }

}




