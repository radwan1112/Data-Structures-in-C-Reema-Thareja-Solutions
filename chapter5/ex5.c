#include <stdio.h>

struct distance
{
    int km;
    int m;
};

struct distance d1, d2, dr;

struct distance add_distance(struct distance d1, struct distance d2)
{

    struct distance sum;
    sum.m = d1.m + d2.m;
    sum.km = d1.km + d2.km;
    while(sum.m >= 1000)
    {
        sum.m %= 1000;
        sum.km += 1;
    }
    return sum;
};

struct distance sub_distance(struct distance d1, struct distance d2)
{

    struct distance diff;

    if(d1.m >= 1000)
    {
        d1.km += d1.m/1000;
        d1.m %= 1000;
    }
    if(d2.m >= 1000)
    {
        d2.km += d2.m/1000;
        d2.m %= 1000;
    }

    if(d1.km >= d2.km)
    {
        diff.km = d1.km - d2.km;
    }
    else
    {
        diff.km = d2.km - d1.km;
    }
    if(d1.m > d2.m)
    {
        diff.m = d1.m - d2.m;
    }
    else
    {
        diff.m = d2.m - d1.m;
    }

    int times = 0;
    if(diff.m >= 1000)
    {
        times = diff.m/1000;
        diff.m %= 1000;
        diff.km += times;
    }

    return diff;
};


int main()
{


    int option;
    do
    {
        printf("\n ******** MAIN MENU *********");
        printf("\n 1. Add the distances");
        printf("\n 2. Subtract the distances");
        printf("\n 3. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the first distance in kms and meters: ");
            scanf("%d %d", &d1.km, &d1.m);
            printf("\n Enter the second distance in kms and meters: ");
            scanf("%d %d", &d2.km, &d2.m);
            dr = add_distance(d1, d2);
            printf("%d km and %d meters + %d km and %d meters = %d km and %d meters", d1.km, d1.m, d2.km, d2.m, dr.km, dr.m);
            break;
        case 2:
            printf("\n Enter the first distance in kms and meters: ");
            scanf("%d %d", &d1.km, &d1.m);
            printf("\n Enter the second distance in kms and meters: ");
            scanf("%d %d", &d2.km, &d2.m);
            dr = sub_distance(d1, d2);
            printf("%d km and %d meters - %d km and %d meters = %d km and %d meters", d1.km, d1.m, d2.km, d2.m, dr.km, dr.m);
            break;
        }
    }
    while(option != 3);


    return 0;
}
