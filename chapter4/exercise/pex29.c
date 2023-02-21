#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{

    char stud[20][200] = {"Jack", "Mick", "Jackson", "Mohammed", "Ahmed", "Sarah", "Radwan", "Salah", "Rachel", "Khalid", "Bob", "Zack", "Tyson", "Ali"};

    printf("List of current students: \n\n");
    int i = 0;
    while(stud[i][0] != '\0')
    {
        printf("%2d. %s\n", i+1, stud[i]);
        i++;
    }

    int len = i;
    int j = len - 1;





    printf("\nEnter a student name: ");
    char new_name[200];
    gets(new_name);

    strcpy(stud[len], new_name);



    //sort the array
    char temp[200];
    i = 0;
    while(stud[i][0] != '\0')
    {
        j = 0;
        while(stud[j][0] != '\0')
        {
            if(i == j)
            {
                j++;
                continue;
            }
            else
            {
                if(strcasecmp(stud[i], stud[j]) < 0)
                {
                    strcpy(temp, stud[i]);
                    strcpy(stud[i], stud[j]);
                    strcpy(stud[j], temp);

                }
            }
            j++;
        }
        i++;
    }

    printf("\nSorting...\n\n");
    i = 0;
    while(stud[i][0] != '\0')
    {
        printf("%2d. %s\n", i+1, stud[i]);
        i++;
    }

}
