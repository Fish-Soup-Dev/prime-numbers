#include <stdio.h>
#include <time.h>

int main()
{

    float k = 1.0;
    float s = 0.0;
    int max = 1000000000;
    double time_spent = 0.0;

    printf("starting... \n");
    clock_t begin = clock();
    
    for (int i = 0; i != max; i++)
    {
        if (i % 2 == 0)
        {
            s += 4 / k;
        }
        else{
            s -= 4 / k;
        }
        k += 2;
    }   

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds. pi is %f", time_spent, s);

}