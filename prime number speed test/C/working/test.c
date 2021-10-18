#include <stdio.h>
#include <time.h>

int main() {

    double time_spent = 0.0;
    float x, y;

    printf("starting... \n");
    clock_t begin = clock();

    for (int i = 0; i <= 10000000; i++) {
        x = 40.0 / 2.0;
    }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("davide with / took %.3f seconds.\n", time_spent);

    printf("%f\n", x);



    printf("starting... \n");
    begin = clock();
    for (int i = 0; i <= 10000000; i++) {
        y = (40 >> 1);
    }

    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("davide with >> took %.3f seconds.\n", time_spent);

    printf("%f\n", y);

    

    return 0;
}