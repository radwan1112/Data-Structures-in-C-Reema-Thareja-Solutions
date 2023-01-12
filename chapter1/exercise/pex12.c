#include <stdio.h>
#include <stdlib.h>
#include <time.h>



float RandomFloat()
{
    float number;
    srand((unsigned int)time(NULL));
    float a = 10000.0; //Max Range of random number
    for (int i=0; i<20; i++)
    {
        number = ((float)rand()/(float)(RAND_MAX)) * a;

    }
    return number;
}

int main()
{

    float number = RandomFloat();
    printf("Decimal Format: %f", number);
    printf("\nExponential format: ");
    printf("\n Correct to two decimal places: %.2e", number);
    printf("\n Correct to four decimal places: %.4e", number);
    printf("\n Correct to eight decimal places: %.8e", number);


    return 0;
}
