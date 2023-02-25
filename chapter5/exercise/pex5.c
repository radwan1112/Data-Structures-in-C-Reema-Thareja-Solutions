#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_num(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    srand(time(NULL));
    printf("-- Find the Smallest Number Using structs --\n\n");
    struct numbers
    {
        int n[3];
    } three_n;

    for(int i = 0; i < 3; i++)
    {
        three_n.n[i] = rand_num(0, 100);
        printf("Number %d = %d\n",i+1, three_n.n[i]);
    }

    int smallest = three_n.n[0];

    for(int i = 0; i < 3; i++)
    {
        if(three_n.n[i] < smallest)
        {
            smallest = three_n.n[i];
        }
    }

    printf("\n The smallest number is %d", smallest);

    return 0;
}
