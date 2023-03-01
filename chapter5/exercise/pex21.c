#include <stdio.h>

struct POINT
{
    int x, y;
};


int main()
{
    struct POINT point1;

    printf("Enter point x: ");
    scanf(" %d", &point1.x);
    printf("Enter point y: ");
    scanf(" %d", &point1.y);

    if(point1.x > 0 && point1.y > 0)
    {
        printf("(%d, %d) Lies in quadrant 1", point1.x, point1.y);
    }
    else if(point1.x < 0 && point1.y > 0)
    {
        printf("(%d, %d) Lies in quadrant 2", point1.x, point1.y);
    }
    else if(point1.x < 0 && point1.y < 0)
    {
        printf("(%d, %d) Lies in quadrant 3", point1.x, point1.y);
    }
    else
    {
        printf("(%d, %d) Lies in quadrant 4", point1.x, point1.y);
    }
    return 0;
}
