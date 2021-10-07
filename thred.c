#include <stdio.h>
#include <time.h>

int main()
{
    int max = 100000;
    int prime_numbers = 0;
    double time_spent = 0.0;
 
    printf("starting... ");
    clock_t begin = clock();

    for (int x = 0; x != max + 1; x++)
    {
        if (x > 1)
        {
            int prime = 1;
            for (int i = 2; i != x; i++)
            {   
                if ((x % i) == 0) 
                { 
                    prime = 0; break; 
                }
            }
            if (prime == 1) 
            {
                prime_numbers ++; 
            }
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}