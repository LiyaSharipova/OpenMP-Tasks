//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int m = 6;
    int n = 6;
    int d[m][n];
    int max, min;
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < m; j++) {
            d[i][j] = (rand() % 100);
        }
    }
    max = d[0][0];
    min = d[0][0];
#pragma omp parallel  for num_threads(4)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
#pragma omp critical
            {
                if (d[i][j] > max) {
                    max = d[i][j];
                }
                if (d[i][j] < min) {
                    min = d[i][j];
                }
            }
        }
    }
    printf(" max = %d , min = %d\n",max, min);



}
