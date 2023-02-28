#include <stdio.h>

struct TIME
{

    int seconds;

    int minutes;

    int hours;

};

void difference(struct TIME t1,

                struct TIME t2,

                struct TIME *diff);

int main()
{

    struct TIME startTime, stopTime, diff;

    printf("Enter the start time. \n");

    printf("Enter hours, minutes and seconds: ");

    scanf("%d %d %d", &startTime.hours, &startTime.minutes,  &startTime.seconds);

    printf("Enter the stop time. \n");

    printf("Enter hours, minutes and seconds: ");

    scanf("%d %d %d", &stopTime.hours,

          &stopTime.minutes,

          &stopTime.seconds);



    difference(startTime, stopTime, &diff);

    printf("\nTime Difference: %d:%d:%d - ", startTime.hours,

           startTime.minutes,

           startTime.seconds);

    printf("%d:%d:%d ", stopTime.hours,

           stopTime.minutes,

           stopTime.seconds);

    printf("= %d:%d:%d\n", diff.hours,

           diff.minutes,

           diff.seconds);

    return 0;

}

void difference(struct TIME start,

                struct TIME stop,

                struct TIME *diff)
{

    while (stop.seconds > start.seconds)
    {

        --start.minutes;

        start.seconds += 60;

    }

    diff->seconds = start.seconds - stop.seconds;

    while (stop.minutes > start.minutes)
    {

        --start.hours;

        start.minutes += 60;

    }

    diff->minutes = start.minutes - stop.minutes;

    diff->hours = start.hours - stop.hours;

    if( diff->seconds != 0 || diff->minutes!=0 || diff->hours!=0)
        printf("GOOD DAY");

}
