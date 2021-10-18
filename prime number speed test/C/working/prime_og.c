#include <stdio.h>
#include <time.h>

int main()
{
    int max = 100000;
    int prime_numbers = 0;
    double time_spent = 0.0;
    int prime = 1, x = 1, i = 2, s = 0;
    int nums[max / 2];
    int smol_num = max / 2;
    
    printf("starting... \n");
    clock_t begin = clock();

    for (x; x <= max; x++) {
        if (x % 2 != 0) { 
            nums[s] = x; 
            s++; 
        } 
    }

    for (int x = 0; x <= smol_num; x++) {

        for (int i = 2; i <= nums[x] / 2; i++) {

            if (nums[x] % i == 0) { 

                prime = 0; 
                break;

            }

        }

        if (prime == 1) { prime_numbers++; }

        prime = 1;
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}