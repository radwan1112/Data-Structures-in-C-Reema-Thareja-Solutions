#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int top = 9;

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int i;
    for(i = top; i >= 0; i--)
    {
        if(front == -1)
        {
            front = rear = 0;
            queue[rear] = stack[i];
        }
        else
        {
            queue[++rear] = stack[i];
        }
    }

    printf("\n Converting Stack to Queue...\n\n Stack: top -> bottom \n    ");
    for(i = top; i > 0; i--)
    {
        printf("%d -> ", stack[i]);
    }
    printf("%d\n", stack[i]);

    printf("\n Queue: front -> end\n    ");
    for(i = front; i < rear; i++)
    {
        printf("%d -> ", queue[i]);
    }
    printf("%d\n", queue[i]);

    return 0;
}
