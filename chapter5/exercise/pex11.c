#include <stdio.h>
#include <string.h>

struct employee
{
    char name[100];
    int age;
    char position[100];
};

void print_data(struct employee *ptr_emp1)
{
    printf("Name: %s\nAge: %d\nPosition: %s\n", ptr_emp1->name, ptr_emp1->age, ptr_emp1->position);
}

int main()
{
    struct employee
    {
        char name[100];
        int age;
        char position[100];
    };

    struct employee emp_1, *ptr_emp1;
    ptr_emp1 = &emp_1;
    strcpy(ptr_emp1->name, "Radwan AlShawesh");
    ptr_emp1->age = 30;
    strcpy(ptr_emp1->position, "Engineer");
    print_data(ptr_emp1);

    return 0;
}



