#include <stdio.h>

int main()
{

    int grade;
    printf("Enter your grade: ");
    scanf("%d", &grade);

    if(grade > 75)
    {
        printf("O");

    }
    else if (grade >= 60 && grade <= 75)
    {
        printf("A");

    }
    else if (grade >= 50 && grade <= 59)
    {
        printf("B");

    }
    else if (grade >= 40 && grade <= 49)
    {
        printf("C");

    }
    else
    {
        printf("D");
    }

}
