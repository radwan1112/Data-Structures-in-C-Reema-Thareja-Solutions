#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int stack[MAX];
int stack2[MAX];

int top = -1;
int top2 = -1;

int main()
{

    printf("\n Input the first stack\n");
    int i = 0;
    while(top < MAX)
    {
        printf("\n Stack[%d] = ", i++);
        scanf(" %d", &stack[++top]);
    }

    printf("\n Input the second stack\n");
    i = 0;
    while(top2 < MAX)
    {
        printf("\n Stack2[%d] = ", i++);
        scanf(" %d", &stack2[++top2]);
    }

    i = top;
    while(stack[i] == stack2[i])
    {
        i--;
    }

    if(i > -1)
    {
        printf("\n BOTH STACKS ARE DIFFERENT");
    }
    else
    {
        printf("\n BOTH STACKS ARE THE IDENTICAL");
    }


    return 0;
}
