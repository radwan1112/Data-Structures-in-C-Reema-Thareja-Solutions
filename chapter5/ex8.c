#include <stdio.h>
#include <stdlib.h>

struct student
{
    int r_no;
    char name[100];
    char course[100];
    int fees;
};

void display(struct student *ptr){

    printf("\n Details of students");
    printf("\n Student number: %d", ptr->r_no);
    printf("\n Name: %s", ptr->name);
    printf("\n Course: %s", ptr->course);
    printf("\n Fees: %d", ptr->fees);

}



int main()
{

    struct student *ptr;
    ptr = (struct student *)malloc(sizeof(struct student));
    printf("\n Enter the data for the student ");
    printf("\n ROLL NO.: ");
    scanf(" %d", &ptr->r_no);
    getchar();
    printf("\n NAME: ");
    gets(ptr->name);
    printf("\n COURSE: ");
    gets(ptr->course);
    printf("\n FEES: ");
    scanf("%d", &ptr->fees);

    display(ptr);


    return 0;
}
