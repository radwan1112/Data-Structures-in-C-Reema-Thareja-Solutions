#include <stdio.h>
#include <string.h>

int  main()
{

    char str[] = "Good Morning";
    char str2[] = "GOOD MORNING";

    if(strcmp(str, str2) == 0){
        printf("String 1 and string 2 are equal");
    }
    else{
        printf("string and string 2 are not the equal");
    }


    return 0;
}
