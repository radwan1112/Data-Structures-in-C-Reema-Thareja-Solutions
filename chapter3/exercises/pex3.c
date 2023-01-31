#include <stdio.h>

void main(){

    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    int arr[len];
    printf("\nEnter the elements of the array\n\n");

    int i, j;
    for(i = 0; i < len; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int temp;
    temp = arr[1];
    arr[1] = arr[len - 2];
    arr[len - 2] = temp;

    printf("The second element has been swapped with the second last element\n\n");
    for(i = 0; i < len; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }

}
