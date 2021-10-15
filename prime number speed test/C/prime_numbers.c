#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

// * retunrns 1 if a number is prime and 0 if its not.
// ! this also might be broken.
// TODO test fully.
void* find_prime(void* arg) {
    int value = *(int*)arg;
    int* result = malloc(sizeof(int));
    int prime = 1;

    // run through all numbers less then input number.
    for (int i = 2; i <= value / 2; i++)
    {   
        // if number is davisable buy another number that isnt itself then break loop.
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

    // free data.
    free(arg);
    return (void*) result;
}

// * Main loop
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
        // * if a numbre is davisable by 2, 3, or 5 then skip it.
        // ! might be broken.
        // TODO test and see if is working.
        if (x % 2 != 0 || x % 5 != 0 || x % 3 != 0)
        {

            int* a = malloc(sizeof(int));
            *a = x;

            // * create thread with number that we are testing if it is prime.
            if ( pthread_create(&th[x], NULL, &find_prime, a) != 0) {
                printf("create thread failed\n");
            }

            thread_num += 1;
        }
    }
    
    // * add all threads awnsers togeather.
    // ! some threads fail to join.
    // TODO fix the thing.
    for (int y = 0; y != thread_num; y++)
    {

        if ( pthread_join(th[y], (void**) &res) != 0) {
            printf("join thread failed\n");
        }

        // add result to total primes found.
        // TODO make error cheaking system. cuz som numbas are like -142345 and thats not how they shoud be.
        prime_numbers += *res;
    }

    // free data.
    free(res);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}