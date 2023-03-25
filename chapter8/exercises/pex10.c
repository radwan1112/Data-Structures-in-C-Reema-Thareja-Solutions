#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int front = 0;
int rear = 9;

int stack[MAX];
int top = -1;

int main()
{
    printf("\n Converting queue to stack... \n");

    int i;
    for(i = rear; i >= 0; i--)
    {
        if(top == -1)
        {
            top = 0;
            stack[top] = queue[i];
        }
        else
        {
            stack[++top] = queue[i];
        }
    }

    printf("\n Queue: Front -> Rear\n\n   ");
    for(i = front; i < rear; i++)
    {
        printf("%d -> ", queue[i]);
    }
    printf("%d\n", queue[i]);

    printf("\n Stack: Top -> Bottom\n\n   ");
    for(i = top; i > 0; i--)
    {
        printf("%d -> ", stack[i]);
    }
    printf("%d\n", stack[i]);

    return 0;
}
