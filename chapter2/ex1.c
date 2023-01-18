#include <stdio.h>

int main(){

    int A, B, temp;
    printf("Enter value of A: ");
    scanf("%d" ,&A);
    printf("Enter value of B: ");
    scanf("%d", &B);

    temp = A;
    A = B;
    B = temp;

    printf("After swapping A now = %d and B = %d", A, B);
    return 0;

}
