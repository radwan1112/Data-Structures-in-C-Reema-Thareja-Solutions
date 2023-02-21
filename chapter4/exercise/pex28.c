#include <stdio.h>
#include <string.h>

void delete_pattern(char *str, const char *pattern)
{
    size_t len = strlen(pattern);
    char *p = NULL;
    while ((p = strstr(str, pattern)) != NULL)
    {
        memmove(p, p + len, strlen(p + len) + 1);
    }
}

int main()
{
    printf("Enter some text: ");
    char str[10000];
    gets(str);
    char pattern[100];
    printf("Enter the pattern you wish to delete: ");
    gets(pattern);
    delete_pattern(str, pattern);
    printf("%s\n", str); // Output: "This is a  string."
    return 0;
}
