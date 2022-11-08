#include <stdio.h>

int main(){

    int m, n, first_num, second_number, sum = 0;

    printf("Please Enter a First Number: ");
    scanf("%d", &m);
    printf("Please Enter a Second Number: ");
    scanf("%d", &n);

    if(n >= m){
        first_num = m;
        second_number = n;
    }
    else {
        first_num = n;
        second_number = m;
    }

    while(first_num <= second_number){
        sum += first_num;
        first_num++;
    }

    if(n >= m){
        first_num = m;
        second_number = n;
    }
    else {
        first_num = n;
        second_number = m;
    }

    printf("The sum of numbers from %d to %d is: %d", first_num, second_number, sum);

    return 0;
}
