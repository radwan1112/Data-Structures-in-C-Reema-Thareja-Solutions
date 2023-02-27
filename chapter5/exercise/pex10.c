#include <stdio.h>

int is_leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf(" %d", &year);
    if(is_leap_year(year))
    {
        printf("\n %d is a leap year");
    }
    else
    {
        printf("\n %d is not a leap year\n");
    }
    return 0;
}
