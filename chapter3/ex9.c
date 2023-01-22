#include <stdio.h>
#include <stdlib.h>

int main()
{


    int n;
    int upper = 100, lower = 0;
    srand(time(0));
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    int arr[n];


    //fill the array with random numbers
    for(int i = 0 ; i < n ; i++ )
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int pos;

    printf("\nEnter the position of the number you wish to delete: ");
    scanf("%d", &pos);
    if(pos >= 0 && pos < n)
    {
        for(int i = pos; i < n - 1; i++){
            arr[i] = arr[i + 1];
        }
        n--;
    }

    else
    {
        printf("\nYou need to enter a correct index position");
    }

    for(int k = 0; k < n; k++){
        printf("arr[%d]: %d\n", k, arr[k]);
    }


}
