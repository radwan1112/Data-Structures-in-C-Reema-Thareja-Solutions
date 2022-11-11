#include <stdio.h>

int main(){

    int sum = 0;
    int even = 0;

    int i = 1;
    while(i <= 200){

        if(i % 2 == 0){
            even++;
        }

        sum += i;


        i++;
    }

    printf("The total number of even numbers between 1 and 200 is: %d \n", even);
    printf("The sum total of numbers between 1-200 is: %d", sum);

    return 0;
}
