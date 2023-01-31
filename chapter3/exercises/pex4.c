#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){

    srand(time(NULL));
    int i, len = 10;
    int arr[len];
    int total = 0;

    for(i = 0; i < len; i++){
        arr[i] = rand() % 11;
        printf("arr[%d] = %d\n", i, arr[i]);
        total += pow(arr[i], 2);
    }
    printf("The sum of squares of the elements is = %d", total);




    return 0;
}
