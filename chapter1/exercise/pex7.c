#include <stdio.h>
#include <math.h>

int main()
{

    int choice;
    float si, ci, p, r, t, n;

    printf("Enter principal amount (p): \n");
    scanf("%f", &p);
    printf("Enter time in year (t): \n");
    scanf("%f", &t);
    printf("Enter rate in percent (r): ");
    scanf("%f", &r);


    si = (p*r*t)/100.0;
    ci = p * (pow(1+r/100, t) - 1);

    printf("Simple interest = %0.3f \n", si);
    printf("Compound interest = %0.3f", ci);


    return 0;
}
