#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = arr;
    int *ptr2 = &arr[8];

    while(ptr <= ptr2) {
        printf("arr[%d] = %d \n", ptr, *ptr);
        ptr++;
    }



}
