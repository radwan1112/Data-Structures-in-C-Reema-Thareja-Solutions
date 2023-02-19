#include <stdio.h>

int main()
{
    printf("Enter the number of Employees: ");
    int num;
    scanf("%d", &num);
    getchar();
    char names[num][100];
    int i;
    for(i = 0; i < num; i++)
    {
        printf("Enter Employees No. %d name: ", i+1);
        gets(names[i]);
    }

    printf("\nEmployees of the Software Department: \n\n");

    int j;
    for(j = 0; j < num; j++){
        printf("%d. %s\n", j+1, names[j]);
    }


    return 0;

}
