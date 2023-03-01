#include <stdio.h>

struct fraction
{
    float numerator;
    float denominator;
};


int comp_frac(struct fraction *frac1, struct fraction *frac2)
{

    if(frac1->numerator / frac1->denominator == frac2->numerator / frac2->denominator)
    {
        return 0;
    }
    else if(frac1->numerator / frac1->denominator < frac2->numerator / frac2->denominator)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}

int main()
{
    struct fraction frac1 = {12, 5};
    struct fraction frac2 = {12, 5};

    int num = comp_frac(&frac1, &frac2);

    printf("\n\n %f/%f = %f and %f/%f = %f the return result is %d", frac1.numerator, frac1.denominator, frac1.numerator/frac1.denominator, frac2.numerator, frac2.denominator, frac2.numerator/frac2.denominator, num);

    return 0;
}
