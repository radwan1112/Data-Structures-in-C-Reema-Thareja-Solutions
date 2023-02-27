#include <stdio.h>
#include <time.h>

struct shijian
{
    int hours;
    int min;
    int sec;
};

int main()
{
    struct shijian yemen = {10, 20, 50};
    struct shijian china = {5, 30, 40};

    //add time
    int sum_hours = yemen.hours + china.hours;
    int sum_min = yemen.min + china.min;
    int sum_sec = yemen.sec + china.sec;

    if(sum_sec >= 60)
    {
        sum_min += sum_sec / 60;
        sum_sec = sum_sec % 60;
    }

    if(sum_min >= 60)
    {
        sum_hours += sum_min/60;
        sum_min = sum_min % 60;
    }
    printf("\n %dhrs %dmins %dsec + %dhrs %dmins %dsec = %dhrs %dmins %dsec\n", yemen.hours, yemen.min, yemen.sec, china.hours, china.min, china.sec, sum_hours, sum_min, sum_sec);

    //sub time
    int sub_hours = abs(yemen.hours - china.hours);
    int sub_min = abs(yemen.min - china.min);
    int sub_sec = abs(yemen.sec - china.sec);

    if(sub_sec >= 60)
    {
        sub_min += sub_sec/60;
        sub_sec = sub_sec % 60;
    }
    if(sub_min >= 60)
    {
        sub_hours += sub_min / 60;
        sub_min = sub_min % 60;
    }
    printf("\n %dhrs %dmins %dsec - %dhrs %dmins %dsec = %dhrs %dmins %dsec", yemen.hours, yemen.min, yemen.sec, china.hours, china.min, china.sec, sub_hours, sub_min, sub_sec);


    return 0;
}
