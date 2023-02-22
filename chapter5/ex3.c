#include <stdio.h>

int main()
{
    struct name
    {
        char firstname[100];
        char middlename[100];
        char lastname[100];
    };
    struct dob
    {
        int day;
        int month;
        int year;
    };
    struct student
    {
        int stno;
        struct name stname;
        struct dob birthday;
        float fees;
    };

    printf("Student Info\n\n");
    struct student stud1;
    printf("Enter student number: ");
    scanf(" %d", &stud1.stno);
    printf("Enter student name: ");
    scanf(" %s %s %s", stud1.stname.firstname, stud1.stname.middlename, stud1.stname.lastname);
    printf("Enter Student birth date: ");
    scanf("%d %d %d", &stud1.birthday.day, &stud1.birthday.month, &stud1.birthday.year);
    printf("Enter total fees: ");
    scanf("%f", &stud1.fees);

    printf("\nPrinting student info: \n");
    printf("Student Number: %d\n", stud1.stno);
    printf("FullName: %s %s %s\n", stud1.stname.firstname, stud1.stname.middlename, stud1.stname.lastname);
    printf("Birthday: %d-%d-%d \n", stud1.birthday.day, stud1.birthday.month, stud1.birthday.year);
    printf("Total Fees: %f$", stud1.fees);
    getchar();

    return 0;

}
