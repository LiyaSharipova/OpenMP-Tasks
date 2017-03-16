//
// Created by liya on 22.02.17.
//

#include <omp.h>
#include <iostream>

int main() {
    int a = 0;
    int b = 1;
    int rank;
    printf("Before the 1st area: a = %d, b = %d\n", a, b);
#pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        rank = omp_get_thread_num();
        a = a + rank;
        b = b + rank;
        printf("In the 1st area: thread = %d, a = %d, b = %d\n", rank, a, b);

    }
    printf("After the 1st area: a = %d, b = %d\n", a, b);
    printf("--------------------------------------------\n");
    printf("Before the 2st area: a = %d, b = %d\n", a, b);

#pragma omp parallel num_threads(4) shared(a) private(b)
    {

        rank = omp_get_thread_num();
        a = a - rank;
        b = b - rank;
        printf("In the 2st area: thread = %d, a = %d, b = %d\n", rank, a, b);

    }
    printf("After the 2st area: a = %d, b = %d\n", a, b);

}