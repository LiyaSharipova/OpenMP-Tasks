//
// Created by liya on 01.03.17.
//



#include <omp.h>
#include <iostream>
#include <algorithm>

int main() {
    int n = 6;
    int m = 8;
    int d[n][m];


    for (int i = 0; i < n; i++) {

        for (int j = 0; i < m; j++) {
            d[i][j] = (rand() % 100);
        }

    }

#pragma omp parallel sections
    {
#pragma omp section
        {

            int sum, avg;
            for (int i = 0; i < n; i++) {
                for (int j = 0; i < m; i++) {
                    sum += d[i][j];
                }
            }
            avg = sum / (n + m);
            printf("section 1 thread = %d average value = %d\n", omp_get_thread_num(), avg);
        }

#pragma omp section
        {

            int max, min;
            max = d[0][0];
            min = d[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (d[i][j] > max) {
                        max = d[i][j];
                    }
                    if (d[i][j] < min) {
                        min = d[i][j];
                    }
                }
            }

            printf("section 2 thread = %d, max = %d , min = %d\n", omp_get_thread_num(), max, min);
        }
#pragma omp section
        {
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (d[i][j]%3 == 0)
                        count++;
                }
            }
            printf("section 3 thread = %d, count of element devided by 3 = %d ", omp_get_thread_num(), count);

        }

    }
}