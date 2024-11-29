#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ALLOC 1000

void malloc_test()
{
    for (int i = 0; i < NUM_ALLOC; ++i)
    {
        int *ptr_1 = (int *)malloc(1000);
        int *ptr_2 = (int *)malloc(500);
        int *ptr_3 = (int *)malloc(200);
        int *ptr_4 = (int *)malloc(800);
        int *ptr_5 = (int *)malloc(300);
        int *ptr_6 = (int *)malloc(600);
        int *ptr_7 = (int *)malloc(400);

        free(ptr_3);
        free(ptr_6);
        free(ptr_2);

        ptr_3 = (int *)malloc(400);

        free(ptr_1);
        free(ptr_5);

        int *ptr_8 = (int *)malloc(1000);

        free(ptr_4);
        free(ptr_7);
        ptr_7 = (int *)malloc(500);
    }
}
int main()
{
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    mallocTest();

    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Performance rated at %f seconds.\n", total_time);

    return 0;
}