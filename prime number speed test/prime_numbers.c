#include <stdio.h>
#include <time.h>

int main()
{
    int max = 10;
    int prime_numbers = 0;
    double time_spent = 0.0;
    int prime = 1, x, i;
    
    printf("starting... \n");
    clock_t begin = clock();

    for (x = 2; x <= max; x++)
    {   
        if (x % 2 != 0 || x % 5 != 0 || x % 3 != 0)
        {
            for (i = 2; i <= x / 2; i++)
            {   
                if (x % i == 0)
                {
                    prime = 0;
                    break;
                }
            }
            if (prime == 1) 
            {
                printf("%i\n", x);
                prime_numbers ++; 
            }
            prime = 1;
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. Found %i prime numbers", time_spent, prime_numbers);
    return 0;
}
