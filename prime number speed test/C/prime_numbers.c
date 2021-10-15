#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

void* find_prime(void* arg) {
    int value = *(int*)arg;
    int* result = malloc(sizeof(int));
    int prime = 1;

    for (int i = 2; i <= value / 2; i++)
    {   
        if (value % i == 0)
        {
            prime = 0;
            *result = 0;
            break;
        }
    }
    if (prime == 1) 
    {
        *result = 1;
    }

    free(arg);
    return (void*) result;
}

int main(int argc, char* argv[])
{
    int max = 10;
    int prime_numbers = 0;
    double time_spent = 0.0;
    int thread_num = 0;

    pthread_t th[max];
    int* res;

    printf("starting... \n");
    clock_t begin = clock();

    for (int x = 2; x <= max; x++)
    {   
        if (x % 2 != 0 || x % 5 != 0 || x % 3 != 0)
        {
            int* a = malloc(sizeof(int));
            *a = x;
            if ( pthread_create(&th[x], NULL, &find_prime, a) != 0) {
                printf("create thread failed\n");
            }
            thread_num += 1;
        }
    }

    for (int y = 0; y != thread_num; y++)
    {
        if ( pthread_join(th[y], (void**) &res) != 0) {
            printf("join thread failed\n");
        }
        prime_numbers += *res;
    }
    free(res);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}