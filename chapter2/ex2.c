#include <stdio.h>

int main(){

    int A, B;
    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%d", &B);

    if(A > B){
        printf("%d", A);
    }
    else if(A < B){
        printf("%d", B);
    }
    else{
        printf("A and B are Equal");

    }
}
