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

int check_date(int day, int month, int year)
{

    int valid = 0;
    if(month == 2)
    {
        if(is_leap_year(year))
        {
            if(day >= 1 && day <= 29)
            {
                valid = 1;
            }
            else
            {
                valid = 0;
            }
        }

        else
        {
            if(day >= 1 && day <= 28)
            {
                valid = 1;
            }
            else
            {
                valid = 0;
            }
        }
    }

    else if(check_month(month))
    {
        if(day >= 1 && day <= 31)
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }
    }
    else
    {
        if(day >= 1 && day <= 30)
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }
    }
    if(valid)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void increment_date(struct date *today)
{
    today->day++;
    today->month++;
    today->year++;

    if(check_date(today->day, today->month, today->year))
    {
        printf("\n%d %d %d is a valid date", today->day, today->month, today->year);
    }
    else
    {
        printf("\n%d %d %d is an invalid date", today->day, today->month, today->year);
        today->day--;
        today->month--;
        today->year--;
    }

}

int main()
{
    struct date today;
    struct date *ptr_today;
    ptr_today = &today;
    int option;

    do
    {
        printf("\n Enter the date dd/mm/yy: ");
        scanf(" %d %d %d", &today.day, &today.month, &today.year);

        if(check_date(today.day, today.month, today.year))
        {
            printf("\n%d %d %d is a valid date", today.day, today.month, today.year);
            increment_date(ptr_today);
        }
        else
        {
            printf("\n%d %d %d is an invalid date", today.day, today.month, today.year);
        }
    }
    while(option != '*');



    return 0;
}
