#include <stdio.h>
#include <stdlib.h>

struct student
{
    int stdno;
    char name[100];
    char course[100];
    int fees;
};

struct student *ptr_stud[10];


int main()
{

    int i, n;
    printf("\n Enter the number of students: ");
    scanf(" %d", &n);

    for(i = 0; i < n; i++)
    {
        ptr_stud[i] = (struct student *)malloc(sizeof(struct student));
        printf("\n Enter the data for student %d ", i+1);
        printf("\n Student no. : ");
        scanf(" %d", &(*ptr_stud[i]).stdno);
        printf("\n Enter the student name: ");
        scanf(" %s", (*ptr_stud[i]).name);
        printf("Enter the course name: ");
        scanf(" %s", (*ptr_stud[i]).course);
        printf("Enter the amount of fees: ");
        scanf(" %d", &(*ptr_stud[i]).fees);
    }

    printf("\n DETAILS OF STUDENTS");
    for(i = 0; i < n; i++)
    {
        printf("\n Roll no. : %d", ptr_stud[i]->stdno);
        printf("\n Name : %s", ptr_stud[i]->name);
        printf("\n Course: %s", ptr_stud[i]->course);
        printf("\n Fees: %d", ptr_stud[i]->fees);
    }


    return 0;
}
