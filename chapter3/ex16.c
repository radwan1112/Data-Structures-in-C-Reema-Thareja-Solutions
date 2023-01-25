#include <stdio.h>

int main(){

    int arr[2][2] = {12, 34, 56, 32};
    int i, j;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }


}

