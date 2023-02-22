#include <stdio.h>
#include <time.h>

int main()
{

    struct fullname
    {

        char firstname[100];
        char middlename[100];
        char lastname[100];

    };

    struct DOB
    {
        int day;
        int month;
        int year;
    };

    struct student
    {

        int st_no;
        struct fullname name;
        struct DOB birthday;
        float fees;
    };
    printf("****Students Records****\n\n");
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    struct student stud[num];

    int i;
    for(i = 0; i < num; i++)
    {
        printf("\n\nStudent No.%d\n\n", i+1);
        printf("Enter Student number : ");
        scanf(" %d", &stud[i].st_no);
        printf("Enter Fullname: ");
        scanf(" %s %s %s", stud[i].name.firstname, stud[i].name.middlename, stud[i].name.lastname);
        printf("Enter date of birth: ");
        scanf(" %d %d %d", &stud[i].birthday.day, &stud[i].birthday.month, &stud[i].birthday.year);
        printf("Enter total fees: ");
        scanf(" %f", &stud[i].fees);
    }

    //print
    printf("\nClass Info\n\n");
    for(i = 0; i < num; i++)
    {
        printf("\n\nStudent No.%d\n\n", i+1);
        printf("Student Number: %d\n", stud[i].st_no);
        printf("Name: %s %s %s\n", stud[i].name.firstname, stud[i].name.middlename, stud[i].name.lastname);
        printf("Birthday: %d /%d /%d\n", stud[i].birthday.day, stud[i].birthday.month, stud[i].birthday.year);
        printf("Total Fees: %f\n", stud[i].fees);
    }

    int n;
    printf("Enter the student number you wish to edit: ");
    scanf("%d", &n);
    n = n-1;
    printf("\nStudent No.%d\n", n + 1);
    printf("Enter Student number : ");
    scanf("%d", &stud[n].st_no);
    printf("Enter Fullname: ");
    scanf(" %s %s %s", stud[n].name.firstname, stud[n].name.middlename, stud[n].name.lastname);
    printf("Enter date of birth: ");
    scanf(" %d %d %d", &stud[n].birthday.day, &stud[n].birthday.month, &stud[n].birthday.year);
    printf("Enter total fees: ");
    scanf(" %f", &stud[n].fees);


    //print
    printf("\nClass Info\n\n");
    for(i = 0; i < num; i++)
    {
        printf("\n\nStudent No.%d\n\n", i+1);
        printf("Student Number: %d\n", stud[i].st_no);
        printf("Name: %s %s %s\n", stud[i].name.firstname, stud[i].name.middlename, stud[i].name.lastname);
        printf("Birthday: %d/%d/%d\n", stud[i].birthday.day, stud[i].birthday.month, stud[i].birthday.year);
        printf("Total Fees: %f\n", stud[i].fees);
    }

    return 0;
}
