#include <stdio.h>

int main()
{

    int sales[5][3] = {{23, 23, 45}, {34, 45, 63}, {36, 33, 43}, {33, 52, 35}, {32, 45, 64}};
    int total_sales = 0;
    int sales_per_item[3] = {0, 0, 0};

    for(int i = 0; i < 5; i++)
    {
        total_sales = 0;
        sales_per_item[0] += sales[i][0];
        sales_per_item[1] += sales[i][1];
        sales_per_item[2] += sales[i][2];

        for(int j =0; j < 3; j++)
        {
            total_sales += sales[i][j];
        }
        printf("Salesmen no. %d has sold %d items in total\n", i+1, total_sales);
    }

    printf("Item no. %d has been sold %d times\n", 1, sales_per_item[0]);
    printf("Item no. %d has been sold %d times\n", 2, sales_per_item[1]);
    printf("Item no. %d has been sold %d times\n", 3, sales_per_item[2]);

    return 0;
}
