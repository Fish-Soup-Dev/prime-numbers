#include <stdio.h>

int main()
{
    int max = 11;

    for (int x = 0; x != max + 1; x++)
    {
        if (x > 1)
        {
            int prime = 1;
            for (int i = 2; i != x; i++)
            {   
                if ((x % i) == 0) { prime = 0; break; }
            }
            if (prime == 1) { printf("%i\n",x); }
        }
    }
}