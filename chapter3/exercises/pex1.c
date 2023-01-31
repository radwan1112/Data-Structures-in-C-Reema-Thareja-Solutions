#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void fill_array(int marks[20][5], int rows, int cols)
{

    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            marks[i][j] = rand() % 101;
        }
    }
}


void print_marks(int marks[20][5], int rows, int cols)
{
    int i, j, average = 0, sum = 0;
    int avg_sub[5] = {0, 0, 0, 0, 0};
    int num = 0;
    printf("Students Marks Overview: \n\n");

    printf("Student No |");
    printf("Subject No.1  | Subject No.2 | Subject No.3 | Subject No.4 | Subject No.5 | Average\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    for(i = 0; i < rows; i++)
    {
        sum = 0;
        average = 0;
        printf(" %.2d.       ", i + 1);
        for(j = 0; j < cols; j++)
        {
            avg_sub[j] += marks[i][j];
            sum += marks[i][j];
            printf("|%3d           ", marks[i][j]);
        }
        average = sum / cols;
        if(average < 50){
            num++;
        }
        printf("|%3d\n", average);
    }
    printf("\nSummary: \n\n");

    for(i = 0; i < 5; i++){
        avg_sub[i] /= 20;
        printf("  Subject %d average =  %d\n", i+1, avg_sub[i]);
    }
    printf("\n  %d Students have an average below 50\n", num);


}



int main()
{

    srand(time(NULL));
    int marks[20][5];
    fill_array(marks, 20, 5);
    print_marks(marks, 20, 5);






    return 0;
}
