#include <stdio.h>
#include <stdbool.h>

struct fullname
{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
};

struct dob
{

    int day;
    int month;
    int year;
};

struct marks
{
    int english;
    int maths;
    int computer_science;
};

struct student
{
    bool isstudent;
    int roll_no;
    struct fullname name;
    char sex;
    struct dob birthday;
    struct marks grade;
};

int main()
{






    return 0;
}
