//
// Created by liya on 01.03.17.
//


#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int n = 10;
    int a[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sum_a = 0;
    float sum_b = 0;

#pragma omp parallel for reduction(+:sum_a, sum_b)
    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
        sum_b += b[i];
    }
    float avg_a = sum_a / n;
    float avg_b = sum_b / n;
    printf("Average of a[] = %.2f \nAverage of b[] = %.2f\n", avg_a, avg_b);


    if (avg_a == avg_b) {
        printf("Averages of arrays are equal");
    } else if (avg_a > avg_b) {
        printf("Average of a is greater than average of b");
    } else {
        printf("Average of b is greater than average of b");
    }

}

