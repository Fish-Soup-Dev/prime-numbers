#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

//  starting amout of numbers to serch through.
const int max = 100000;

// output from threads
struct thread_result
{
    int x;
    double t;
};

// * retunrns number of primes found
void* find_prime(void *arg) {

    clock_t start = clock();

    // * weird magic.
    int *val_p = (int *) arg;
    struct thread_result *res = malloc(sizeof *res);
    int prime = 1, total = 0;
    int smol_num = (max / 2) / 4;

    // * regular prime number finder code.
    for (int x = 1; x <= smol_num; x++) {

        for (int i = 2; i <= val_p[x] / 2; i++) {

            if (val_p[x] % i == 0) { 

                prime = 0; 
                break;

            }

        }

        if (prime == 1) { total++; }

        prime = 1;
    }

    clock_t end = clock();

    // * put res into out struct.
    res -> x = total;
    res -> t = (double)(end - start) / CLOCKS_PER_SEC;
    return res;
}

// * Main loop
int main(int argc, char* argv[]) {

    // * define all starting variables.
    int prime_numbers = 0;
    pthread_t th[4];
    void *out_void;
    struct thread_result *out;
    int smol_num = (max / 2) / 4;
    int nums[max / 2];
    int numsA[smol_num];
    int numsB[smol_num];
    int numsC[smol_num];
    int numsD[smol_num];
    int s = 0, i = 0, j = 0, x = 1;

    // * start clock.
    printf("\033[0;33mstarting... \n");
    clock_t begin = clock();

    // * remove all even numbers then devide all numbers in to 4 arrys.
    for (x; x <= max; x += 2) {
        nums[s] = x; 
        s++; 
    }
    for (j; j < (max / 2); j += 4) { 
        numsA[i] = nums[j + 0]; 
        numsB[i] = nums[j + 1]; 
        numsC[i] = nums[j + 2]; 
        numsD[i] = nums[j + 3]; 
        i++; 
    }

    // * create thread with number that we are testing if it is prime.
    pthread_create(&th[1], NULL, &find_prime, &numsA);
    pthread_create(&th[2], NULL, &find_prime, &numsB);
    pthread_create(&th[3], NULL, &find_prime, &numsC);
    pthread_create(&th[4], NULL, &find_prime, &numsD);
    
    // * add all threads awnsers togeather.
    pthread_join(th[1], &out_void);

    out = out_void;
    prime_numbers += out -> x;
    double thread_time1 = out -> t;

    pthread_join(th[2], &out_void);
    out = out_void;
    prime_numbers += out -> x;
    double thread_time2 = out -> t;

    pthread_join(th[3], &out_void);
    out = out_void;
    prime_numbers += out -> x;
    double thread_time3 = out -> t;

    pthread_join(th[4], &out_void);
    out = out_void;
    prime_numbers += out -> x;
    double thread_time4 = out -> t;

    // * end clock and print results.
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\033[0;33mThread 1 compleated in %.3f seconds.\033[0;0m\n", thread_time1);
    printf("\033[0;33mThread 2 compleated in %.3f seconds.\033[0;0m\n", thread_time2);
    printf("\033[0;33mThread 3 compleated in %.3f seconds.\033[0;0m\n", thread_time3);
    printf("\033[0;33mThread 4 compleated in %.3f seconds.\033[0;0m\n", thread_time4);
    printf("\033[0;94mIt took \033[0;31m%.3f\033[0;94m seconds.\nFound \033[0;32m%i\033[0;94m prime numbers\033[0m",
        time_spent, prime_numbers);
    
    return 0;
}