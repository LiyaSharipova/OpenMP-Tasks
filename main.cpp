#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
#pragma omp parallel
    {

//        omp_set_dynamic()
//        std::cout << "Hello World!\n";

    }

    int size, rank;
    int k =5;
//#pragma omp parallel firstprivate(k) num_threads(10)
//    {
//        k++;
//        size = omp_get_num_threads();
//        rank = omp_get_thread_num();
//        printf("HEllow %d out of %d\n", rank, size);
////        printf("HEllow %d out of %d\n", rank);
//
////        cout<< "hellow"<<endl;
//    }

//#pragma omp parallel sections
//    {
//#pragma omp section
//        {
//            rank = omp_get_thread_num();
//            printf("section 1 thread %d\n", rank);
//
//        }
//#pragma omp section
//        {
//            rank = omp_get_thread_num();
//            printf("section 2 thread %d\n", rank);
//        }
//#pragma omp section
//        {
//            rank = omp_get_thread_num();
//            printf("section 3 thread %d\n", rank);
//        }
//#pragma omp parallel for schedule(static, 5)
//#pragma omp parallel for schedule(dynamic, 5)
    double t1 = omp_get_wtime();
    int sum;
#pragma omp parallel for //reduction(+, sum) //schedule(guided, 10)

        for (int i = 0; i < 100 ; i++){
            rank = omp_get_thread_num();

            printf("iteration %d thread %d\n", i,  rank);
//#pragma omp critical
//            {
//                printf("iter %d thread %d", i , rank);
//            }

        }
    double t2 = omp_get_wtime();


//#pragma  omp master
#pragma omp barrier


}

//shared private
//critical = synchronized


//2 para

