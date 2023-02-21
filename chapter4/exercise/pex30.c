#include <stdio.h>

int main()
{

    char stud[20][200] = {"Jack", "Mick", "Jackson", "Mohammed", "Ahmed", "Sarah", "Radwan", "Salah", "Rachel", "Khalid", "Bob", "Zack", "Tyson", "Ali"};
    printf("List of current students: \n\n");

    int i = 0;
    int j;
    //sort the array
    char temp[200];
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

    i = 0;
    while(stud[i][0] != '\0')
    {
        printf("%2d. %s\n", i+1, stud[i]);
        i++;
    }

    printf("\nEnter the name you wish to delete: ");
    char del_name[200];
    gets(del_name);

    i = 0;
    while(stud[i][0] != '\0')
    {
        if(strcasecmp(stud[i], del_name) == 0)
        {
            j = i;
            while(stud[j][0] != '\0')
            {
                strcpy(stud[j], stud[j+1]);
                j++;
            }
        }
        i++;
    }


    printf("\nDeleting name...\n\n");

    i = 0;
    while(stud[i][0] != '\0')
    {
        printf("%2d. %s\n", i+1, stud[i]);
        i++;
    }

    return 0;
}
