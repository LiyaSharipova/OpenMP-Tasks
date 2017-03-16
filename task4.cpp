//
// Created by liya on 28.02.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, -6, 8, 9};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
#pragma omp parallel num_threads(2)
    {
        int min_a, max_b;
        int rank = omp_get_thread_num();
        if (rank == 0) {
            min_a = *std::min_element(a, a + 10);
            printf("Min value in a = %d\n", min_a);


        } else {
            max_b = *std::max_element(std::begin(b), std::end(b));
            printf("Max value in b = %d", max_b);

        }
//        printf("Min value in a = %d\n Max value in b = %d", min_a, max_b);
    }
}