#include <stdio.h>

void calc_area(float base, float height, float *area){

    *area = 0.5 * (base * height);

}

int main(){

    float base, height, area;

    printf("Enter the base: ");
    scanf("%f", &base);

    printf("Enter the height: ");
    scanf("%f", &height);

    calc_area(base, height, &area);

    printf("Area of triangle : %.2f", area);

    return 0;
}
