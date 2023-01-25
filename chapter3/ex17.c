#include <stdio.h>
#include <math.h>

long factorial(long n)
{
    int f;

    for(f = 1; n > 1; n--)
        f *= n;

    return f;
}

long ncr(long n, long r)
{
    return factorial(n) / ( factorial(n-r) * factorial(r) );
}

void draw_pascale_triangle(int n)
{

    int k, r;
    int triangle[n][n];


    for(r = 0; r < n; r++)
    {
        for(int space = 0; space < n - r; space++)
        {
            printf("  ");
        }

        for(k = 0; k <= r; k++)
        {
            triangle[r][k] = ncr(r, k);
            printf(" %3d", triangle[r][k]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    printf("Pascale Triangle Generator\n\n");
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    draw_pascale_triangle(n);



    return 0;
}
