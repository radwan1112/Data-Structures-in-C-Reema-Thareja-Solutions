#include <stdio.h>

struct student
{

    char name[10];
    int age;
    int level;

};

union student2
{
    char name[10];
    int age;
    int level;

};

int main()
{

    struct student stud1 = {"Radwan", 30, 20};
    union student2 stud2 = {"Radwan", 30, 20};

    printf("The size of structure is %d\n", sizeof(stud1));
    printf("The size of union is %d", sizeof(stud2));

    return 0;
}
