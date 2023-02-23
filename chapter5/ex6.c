#include <stdio.h>

struct students
{

    int std_no;
    char name[100];
    char course[100];
    int fees;
};


int main()
{

    struct students stud1, *ptrstud1;
    ptrstud1 = &stud1;

    printf("\n Enter the details of the student: ");
    printf("\n Enter the roll number: ");
    scanf(" %d", &ptrstud1->std_no);
    printf("\n Enter the name: ");
    scanf(" %s", ptrstud1->name);
    printf("Enter the course name: ");
    scanf(" %s", ptrstud1->course);
    printf("\n Enter the total fees: ");
    scanf(" %d", &ptrstud1->fees);

    printf("\n Details of the student");
    printf("\n Roll Number: %d", ptrstud1->std_no);
    printf("\n Name: %s", ptrstud1->name);
    printf("\n Course: %s", ptrstud1->course);
    printf("\n fees: %d", ptrstud1->fees);


    return 0;
}
