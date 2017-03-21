//
// Created by liya on 01.03.17.
//

#include <omp.h>
#include <iostream>

int main() {
    int n = 30;
    int a[n];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = (rand() % 100);
    }


#pragma omp parallel for num_threads(4)
    for (int j = 0; j < n; ++j) {
        if (a[j] % 9 == 0) {

#pragma omp atomic
            count++;
        }
    }
    printf("%d elements that can be devided by 9 ", count);

}
