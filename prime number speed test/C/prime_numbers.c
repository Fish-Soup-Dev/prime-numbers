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

    for (int x = 0; x <= 12500; x++) {

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

    *result = total;
    return (void*) result;
}

// * Main loop
int main(int argc, char* argv[]) {

    int max = 100000;
    int prime_numbers = 0;
    double time_spent = 0.0;

    pthread_t th[4];
    int* res;

    int nums[50000];
    int numsA[12500];
    int numsB[12500];
    int numsC[12500];
    int numsD[12500];

    int s = 0;
    int i = 0;
    int j;
    int x;

    printf("starting... \n");
    clock_t begin = clock();

    for (int x = 1; x <= max; x++) {

        if (x % 2 != 0) {

            nums[s] = x;
            s++;

        }

    }

    for(j = 0; j < 50000 ;j += 4) {

        numsA[i]=nums[j];
        numsB[i]=nums[j+1];
        numsC[i]=nums[j+2];
        numsD[i]=nums[j+3];

        i++;

    }

    // * create thread with number that we are testing if it is prime.
    pthread_create(&th[1], NULL, &find_prime, numsA);
    
    pthread_create(&th[2], NULL, &find_prime, numsB);

    pthread_create(&th[3], NULL, &find_prime, numsA);
    
    pthread_create(&th[4], NULL, &find_prime, numsB);
    
    // * add all threads awnsers togeather.
    pthread_join(th[1], (void**) &res);
    prime_numbers += *res;

    pthread_join(th[2], (void**) &res);
    prime_numbers += *res;

    pthread_join(th[3], (void**) &res);
    prime_numbers += *res;

    pthread_join(th[4], (void**) &res);
    prime_numbers += *res;

    // free data.
    free(res);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}