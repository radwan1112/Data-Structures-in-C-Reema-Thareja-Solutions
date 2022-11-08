#include <stdio.h>

char even_or_odd(int number){

    if(number % 2 == 0){
        return 'e';
    }
    else{
        return 'o';
    }
}

void print_result(char result){

    if(result == 'e'){
        printf("The number is even.");
    }
    else{
        printf("The number is odd.");
    }
}


int main(){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    print_result(even_or_odd(number));

    return 0;
}
