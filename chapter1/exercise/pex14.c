#include <stdio.h>

float area_of_triangle(float height, float base){

    float area = (base * height) * 0.5;
    return area;

}


int main(){

    float height, base;
    printf("Enter the height of the triangle: ");
    scanf("%f", &height);
    printf("\nEnter base of the triangle: ");
    scanf("%f", &base);
    printf("\nArea is Equal: %.2f", area_of_triangle(height, base));

    return 0;
}
