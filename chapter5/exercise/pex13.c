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

struct date
{
    int day;
    int month;
    int year;
};

int check_month(int month)
{
    int month_31_days[] = {1, 3, 5, 7, 8, 10, 12};
    int i;
    for(i = 0; i < 7; i++)
    {
        if(month == month_31_days[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct date today;
    int invalid = 1;

    do
    {
        printf("\n Enter the date dd/mm/yy: ");
        scanf(" %d %d %d", &today.day, &today.month, &today.year);

        if(today.month == 2)
        {
            if(is_leap_year(today.year))
            {
                if(today.day >= 1 && today.day <= 29)
                {
                    invalid = 0;
                }
                else
                {
                    invalid = 1;
                }
            }

            else
            {
                if(today.day >= 1 && today.day <= 28)
                {
                    invalid = 0;
                }
                else
                {
                    invalid = 1;
                }
            }
        }

        else if(check_month(today.month))
        {
            if(today.day >= 1 && today.day <= 31)
            {
                invalid = 0;
            }
            else
            {
                invalid = 1;
            }
        }
        else
        {
            if(today.day >= 1 && today.day <= 30)
            {
                invalid = 0;
            }
            else
            {
                invalid = 1;
            }
        }
        if(invalid)
        {
            printf("\n%d %d %d is an invalid date", today.day, today.month, today.year);
        }
        else
        {
            printf("\n%d %d %d is a valid date", today.day, today.month, today.year);
        }
    }
    while(invalid);

    return 0;
}
