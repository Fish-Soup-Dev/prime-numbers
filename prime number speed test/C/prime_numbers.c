#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

// * retunrns number of primes found
void* find_prime(void *arg) {

    int *val_p = (int *) arg;
    int* result = malloc(sizeof(int));
    int prime = 1;
    int total = 0;

    for (int x = 1; x <= 49999; x++) {

        if (val_p[x] % 2 != 0) {

            for (int i = 2; i <= val_p[x] / 2; i++) {

                if (val_p[x] % i == 0) {
                    
                    prime = 0;
                    break;
                }
            }

            if (prime == 1) {

                total++;
            }

            prime = 1;

        }
    }

    *result = total;

    return (void*) result;
}

// * Main loop
int main(int argc, char* argv[]) {

    int max = 100000;
    int prime_numbers = 0;
    double time_spent = 0.0;

    pthread_t th[max];
    int* res;

    int numsA[max / 2];
    int numsB[max / 2];

    int s = 0;
    int h = 1, hh = 0;
    int g = 0, gg = 0;

    printf("starting... \n");
    clock_t begin = clock();

    // TODO finsh the array asiment.
    for (int x = 1; x <= max; x++) {

        if (h == 1){
            numsA[s] = x;
            h = 0;
            g = 1;
            hh = 1;
        }
        if (g == 1){
            numsB[s] = x;
            g = 0;
            h = 1;
            gg = 1;
        }

        if ( gg == 1 && hh == 1) {
            s += 1;
            hh = 0;
            gg = 0;
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