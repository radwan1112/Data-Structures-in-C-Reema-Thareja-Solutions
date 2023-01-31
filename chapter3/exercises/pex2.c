#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_array(int *arr, int len){

    int i;
    for(i = 0; i < len; i++){
        arr[i] = rand() % 50;
    }
}

void display(int *arr, int len){

    int  i, j, count = 0;
    printf("Printing pair of numbers whose sum is equal to 50\n\n");
    for(i = 0; i < len; i++){
        for(j = i + 1; j < len; j++){
            if(arr[i] + arr[j] == 50){
                count++;
                printf("%.3d. (%2d, %2d)\n", count, arr[i], arr[j]);
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int arr[100];
    fill_array(arr, 100);
    display(arr, 100);

}

