#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

int max = 100000;

// * retunrns number of primes found
void* find_prime(void *arg) {

    int *val_p = (int *) arg;
    int* result = malloc(sizeof(int));
    int prime = 1, total = 0;
    int smol_num = (max / 2) / 4;

    for (int x = 1; x <= smol_num; x++) {
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

    int prime_numbers = 0;
    double time_spent = 0.0;
    pthread_t th[4];
    int* res;
    int smol_num = (max / 2) / 4;
    int nums[max / 2];
    int numsA[smol_num];
    int numsB[smol_num];
    int numsC[smol_num];
    int numsD[smol_num];
    int s = 0, i = 0, j = 0, x = 1;

    printf("starting... \n");
    clock_t begin = clock();

    for (x; x <= max; x++) {
        if (x % 2 != 0) {
            nums[s] = x;
            s++;
        }
    }

    for(j; j < (max / 2); j += 4) {
        numsA[i] = nums[j + 0];
        numsB[i] = nums[j + 1];
        numsC[i] = nums[j + 2];
        numsD[i] = nums[j + 3];
        i++;
    }

    // * create thread with number that we are testing if it is prime.
    pthread_create(&th[1], NULL, &find_prime, numsA);
    pthread_create(&th[2], NULL, &find_prime, numsB);
    pthread_create(&th[3], NULL, &find_prime, numsC);
    pthread_create(&th[4], NULL, &find_prime, numsD);
    
    // * add all threads awnsers togeather.
    pthread_join(th[1], (void**) &res);
    prime_numbers += *res;
    pthread_join(th[2], (void**) &res);
    prime_numbers += *res;
    pthread_join(th[3], (void**) &res);
    prime_numbers += *res;
    pthread_join(th[4], (void**) &res);
    prime_numbers += *res;

    free(res);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}