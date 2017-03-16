//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int n = 12;
    int a[n], b[n], c[n];
#pragma omp parallel for num_threads(3)
    {

    }
#pragma omp parallel for num_threads(4)
    {

    }
}
