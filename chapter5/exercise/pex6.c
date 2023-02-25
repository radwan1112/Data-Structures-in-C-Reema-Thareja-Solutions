#include <stdio.h>
#include <math.h>

int main()
{


    struct points
    {

        int x, y;

    } point1 = {6, 3}, point2 = {2, 2};

    float distance;
    distance = sqrt(pow(abs(point1.x - point2.x), 2) + pow(abs(point1.y - point2.y), 2));

    printf("\nThe distance between (%d, %d) and (%d, %d) = %.2f \n", point1.x, point1.y, point2.x, point2.y, distance);



}
