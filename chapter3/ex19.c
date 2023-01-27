#include <stdio.h>

int find_highest_mark(int arr[5][3], int sub_no)
{

    int hightest = 0;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i][sub_no] >= hightest){
            hightest = arr[i][sub_no];
        }
    }
    return hightest;

}

int main()
{


    int grades[5][3] = {{89, 76, 100}, {99, 90, 89}, {67, 76, 56}, {88, 77, 66}, {67, 78, 89}};
    int highest_marks[3];

    for(int i = 0; i < 3; i++){
        highest_marks[i] = find_highest_mark(grades, i);
        printf("The highest mark attained in subject no.%d is %d\n", i+1, highest_marks[i]);
    }

    return 0;
}
