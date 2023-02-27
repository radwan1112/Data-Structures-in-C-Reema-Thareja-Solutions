#include <stdio.h>
#include <math.h>

struct heigth
{
    int foot;
    int inch;
};

int main()
{
    struct heigth first = {6, 2};
    struct heigth second = {5, 4};

    // Add heights
    int foot_sum = first.foot + second.foot;
    int inch_sum = first.inch + second.inch;

    if(inch_sum > 11)
    {
        foot_sum += inch_sum/12;
        inch_sum = inch_sum%12;
    }
    printf("\n %d'%d\" + %d'%d\" = %d'%d\"", first.foot, first.inch, second.foot, second.inch, foot_sum, inch_sum);

    //Sub heights
    int foot_sub = abs(first.foot - second.foot);
    int inch_sub = abs(first.inch - second.inch);

    if(inch_sub > 11)
    {
        foot_sub += foot_sub/12;
        inch_sub = inch_sub%12;
    }
    printf("\n %d'%d\" - %d'%d\" = %d'%d\"", first.foot, first.inch, second.foot, second.inch, foot_sub, inch_sub);
    return 0;
}
