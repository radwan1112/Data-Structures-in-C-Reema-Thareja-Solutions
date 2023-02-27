#include <stdio.h>

struct department
{

    char name[100];
    int age;
    int year_of_xp;
    char position[100];

} employees[5];

int main()
{
    for(int i = 0; i < 5; i++)
    {
        printf("\nEmployee no %d info\n\n", i+1);
        printf("Enter name: ");
        gets(employees[i].name);
        printf("Enter the age: ");
        scanf(" %d", &employees[i].age);
        printf("Enter years of experience: ");
        scanf(" %d", &employees[i].year_of_xp);
        printf("Enter position: ");
        getchar();
        gets(employees[i].position);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("\nEmployee no %d info\n\n", i+1);
        printf("Name: %s", employees[i].name);
        printf("Age: %d", &employees[i].age);
        printf("Years of xp: %d", &employees[i].year_of_xp);
        printf("Position: %s", employees[i].position);
    }

    int edit;
    printf("enter the number of employee you wish to edit his details: ");
    scanf(" %d", &edit);
    printf("\nEmployee no %d info\n\n", edit);
    edit--;
    printf("Enter name: ");
    gets(employees[edit].name);
    printf("Enter the age: ");
    scanf(" %d", &employees[edit].age);
    printf("Enter years of experience: ");
    scanf(" %d", &employees[edit].year_of_xp);
    printf("Enter position: ");
    getchar();
    gets(employees[edit].position);

    for(int i = 0; i < 5; i++)
    {
        printf("\nEmployee no %d info\n\n", i+1);
        printf("Name: %s", employees[i].name);
        printf("Age: %d", &employees[i].age);
        printf("Years of xp: %d", &employees[i].year_of_xp);
        printf("Position: %s", employees[i].position);
    }

    return 0;
}
