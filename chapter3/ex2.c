#include <stdio.h>

int main(){

    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float mean;

    for(int l = 0; l < n; l++){
        sum += arr[l];
    }

    mean = (float)sum / (float)n;
    printf("The mean is equal = %.2f", mean);




    return 0;
}
