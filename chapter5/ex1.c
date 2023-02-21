#include <stdio.h>

int main()
{

    struct student
    {
        int r_no;
        char name[100];
        char course[100];
        float fees;
    };
    struct student stud1;

    printf("Enter Student info: \n");
    printf("Enter rolling number: ");
    scanf("%d", &stud1.r_no);
    getchar();
    printf("Enter student name: ");
    gets(stud1.name);
    printf("Enter the course name: ");
    gets(stud1.course);
    printf("Enter the course fees in USD: ");
    scanf(" %f", &stud1.fees);

    printf("\nStudent info summary:\n\n ");
    printf("Student Number: %d\n", stud1.r_no);
    printf("Student Name: %s\n", stud1.name);
    printf("Course: %s\n", stud1.course);
    printf("Total Fees: %f$\n", stud1.fees);

    return 0;

}
