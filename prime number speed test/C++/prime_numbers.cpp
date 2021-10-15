#include <iostream>
#include <time.h>

int main() {
    int max = 100000;
    int prime_numbers = 0;
    double time_spent = 0.0;
    int prime = 1, x, i;
    
    std::cout << "starting... \n";
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
                prime_numbers ++; 
            }
            prime = 1;
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << "It took " << time_spent << " seconds. Found " << prime_numbers << " prime numbers";
    return 0;
}