#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    float aRandomNumber;
    srand (time(NULL));

    for(int i = 0; i < 50; i++)
    {
        aRandomNumber = (float)(rand() % 2000) / 100;
        printf("Number %d is %f\n", i + 1, aRandomNumber);
    }
    return 0;
}