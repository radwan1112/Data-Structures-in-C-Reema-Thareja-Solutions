#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{

    printf("--Sort Student Names--\n\n");
    printf("Enter the number of students: ");
    int n;
    int str_len = 20;
    scanf("%d", &n);
    getchar();
    char names[n][str_len];
    int i, j;

    //Enter the name of the students
    for(i = 0; i < n; i++)
    {
        printf("Enter student no %d name: ", i + 1);
        fgets(names[i], str_len, stdin);
    }

    char temp[str_len];
    //Sort students names
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(strcasecmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
                break;
            }
        }
    }

    printf("Names arranged in thGe alphabetical order: \n");
    for( i = 0; i < n; i++)
    {
        printf("%d. %s", i+1, names[i]);
    }
    return 0;

}
