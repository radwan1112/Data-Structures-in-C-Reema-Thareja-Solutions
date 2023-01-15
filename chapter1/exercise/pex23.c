#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int isArmStrong(int n)
{

    int num = n, sum = 0, last_digit, power;
    power =(n==0)?1:((int)log10(n))+1;

    while(num > 0)
    {
        last_digit = num % 10;
        sum += round(pow(last_digit, power));
        num /= 10;
    }

    if(sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{

    int num;

    while(num != -1)
    {

        printf("\nEnter a Number: ");
        scanf(" %d", &num);
        if(num == -1)
        {
            printf("...Program ended");
            break;
        }
        else
        {
            if(isArmStrong(num))
            {
                printf("%d is an Armstrong number", num);
            }
            else
            {
                printf("%d is not an Armstrong number", num);

            }
        }

    }
    return 0;
}
