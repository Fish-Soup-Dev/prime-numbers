#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

// * retunrns 1 if a number is prime and 0 if its not.
// ! this is broken.
// TODO please fix the for loops.
void* find_prime(void *arg) {

    int *val_p = (int *) arg;
    int* result = malloc(sizeof(int));
    int prime = 1;

    int size = sizeof val_p / sizeof *val_p;

    for (int x = 2; x <= size; x++) {

        // run through all numbers less then input number.
        for (int i = 2; i <= val_p[x] / 2; i++) {   

            // if number is davisable buy another number that isnt itself then break loop.
            if (val_p[x] % i == 0) {

                prime = 0;
                *result += 0;
                break;
            }
        }

        if (prime == 1) {

            *result += 1;
        }
    }

    return (void*) result;
}

// * Main loop
int main(int argc, char* argv[]) {

    int max = 10;
    int prime_numbers = 0;
    double time_spent = 0.0;

    pthread_t th[max];
    int* res;

    int numsA[max / 2];
    int numsB[max / 2];

    int s = 0;

    printf("starting... \n");
    clock_t begin = clock();

    // TODO finsh the array asiment.
    for (int x = 0; x <= max; x++) {

        if (x % 2 != 0) {
            int numsA[s];
            s += 1;
        }

    }

    // * create thread with number that we are testing if it is prime.
        if ( pthread_create(&th[1], NULL, &find_prime, numsA) != 0) {
            printf("create thread failed\n");

        }
        if ( pthread_create(&th[2], NULL, &find_prime, numsB) != 0) {
            printf("create thread failed\n");

        }
    
    // * add all threads awnsers togeather.
    if ( pthread_join(th[1], (void**) &res) != 0) {
        printf("join thread failed\n");
    }

    // add result to total primes found.
    prime_numbers += *res;

    if ( pthread_join(th[2], (void**) &res) != 0) {
        printf("join thread failed\n");
    }

    // add result to total primes found.
    prime_numbers += *res;

    // free data.
    free(res);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}