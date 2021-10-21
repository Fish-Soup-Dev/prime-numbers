#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//  starting amout of numbers to serch through.
const int max = 100000;

// output from threads
struct thread_result
{
    int x;
    double t;
    int prime_array[10000];
};

// * retunrns number of primes found
void* find_prime(void *arg) {

    clock_t start = clock();

    // * weird magic.
    int *val_p = (int *) arg;
    struct thread_result *res = malloc(sizeof *res);
    int prime = 1;
    register int total = 0;
    int smol_num = val_p[0];

    // * regular prime number finder code.
    for (int x = 1; x <= smol_num; x++) {

        for (int i = 2; i <= val_p[x] / 2; i++) {

            if (val_p[x] % i == 0) { 

                prime = 0;
                break;

            }

        }

        if (prime == 1) {
            res -> prime_array[total] = val_p[x];
            total++;
        }

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

    //* if starting on a negtive number or 0 dont compute and just print error
    if (max >= 1) {

        // * define all starting variables.
        FILE *fp;
        int prime_numbers = 0;
        pthread_t th[4];
        void *out_void;
        struct thread_result *out;
        register int s = 0;
        register int i = 0;
        register int j = 0;
        register int x = 1;

        int smol_num = (max / 2) / 4 + 1;
        int nums[max / 2];
        int numsA[smol_num];
        int numsB[smol_num];
        int numsC[smol_num];
        int numsD[smol_num];

        // * start clock.
        printf("\033[0;33mstarting... \n");
        clock_t begin = clock();

        // * remove all even numbers then devide all numbers in to 4 arrys.
        for (x; x <= max; x += 2) {
            nums[s] = x; 
            s++; 
        }
        for (j; j < (max / 2); j += 4) { 
            numsA[i + 1] = nums[j + 0]; 
            numsB[i + 1] = nums[j + 1]; 
            numsC[i + 1] = nums[j + 2]; 
            numsD[i + 1] = nums[j + 3];
            i++; 
        }

        numsA[0] = i;
        numsB[0] = i;
        numsC[0] = i;
        numsD[0] = i;

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
        int primesA[out -> x];

        for (x = 0; x != out -> x; x++){
            primesA[x] = out -> prime_array[x];
        }
        
        pthread_join(th[2], &out_void);
        out = out_void;
        prime_numbers += out -> x;
        double thread_time2 = out -> t;
        int primesB[out -> x];

        for (x = 0; x != out -> x; x++){
            primesB[x] = out -> prime_array[x];
        }

        pthread_join(th[3], &out_void);
        out = out_void;
        prime_numbers += out -> x;
        double thread_time3 = out -> t;
        int primesC[out -> x];

        for (x = 0; x != out -> x; x++){
            primesC[x] = out -> prime_array[x];
        }

        pthread_join(th[4], &out_void);
        out = out_void;
        prime_numbers += out -> x;
        double thread_time4 = out -> t;
        int primesD[out -> x];

        for (x = 0; x != out -> x; x++){
            primesD[x] = out -> prime_array[x];
        }

        fp = fopen("Output.txt","w+");

        for (x = 0; x != (prime_numbers / 4); x++) {
            fprintf(fp, "%i \n" , primesA[x]);
            fprintf(fp, "%i \n" , primesB[x]);
            fprintf(fp, "%i \n" , primesC[x]);
            fprintf(fp, "%i \n" , primesD[x]);
        }
        
        // * end clock and print results.
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        printf("\033[0;33mThread 1 compleated in %.3f seconds.\033[0;0m\n", thread_time1);
        printf("\033[0;33mThread 2 compleated in %.3f seconds.\033[0;0m\n", thread_time2);
        printf("\033[0;33mThread 3 compleated in %.3f seconds.\033[0;0m\n", thread_time3);
        printf("\033[0;33mThread 4 compleated in %.3f seconds.\033[0;0m\n", thread_time4);
        printf("\033[0;94mIt took \033[0;31m%.3f\033[0;94m seconds.\nFound \033[0;32m%i\033[0;94m prime numbers\033[0m",
            time_spent, prime_numbers);

    } else {

        printf("\033[0;33mError \033[0;94mno negtive numbers are prime\033[0;0m");

    }

    return 0;
}