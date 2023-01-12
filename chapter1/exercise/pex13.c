#include <stdio.h>
#include <stdlib.h>
#include <time.h> // use time.h header file to use time\


int smallest_number(int n[]){

    int smallest = n[0];

    for(int i = 0; i < 3; i++){
        if(n[i] < smallest){
            smallest = n[i];
        }
    }

    return smallest;
}

int main()
{
    int num = 3, i;
    time_t t1; // declare time variable
    int number[2];

    int max;
    printf("Enter the maximum limit for random number: ");
    scanf("%d", &max);

    /* define the random number generator */
    srand ( (unsigned) time (&t1)); // pass the srand() parameter

    /* generate 3 random numbers between 0 to max */
    for (i = 0; i < num; i++)
    {
        number[i] = rand() % max;
        printf("\nNo.%d\t%d", i+1, number[i]);
    }


    printf("\n\n The smallest number is: %d", smallest_number(number));


    return 0;
}
