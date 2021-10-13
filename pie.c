#include <stdio.h>

int main()
{

    float k = 1.0;
    float s = 0.0;
    int max = 1000000;
    
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
    printf("%.10f", s);   
}