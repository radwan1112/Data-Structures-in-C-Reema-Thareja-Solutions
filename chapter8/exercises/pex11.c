#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int front = 0;
int rear = 9;

int main()
{
    printf("\n Reversing queue...\n");

    int i, j;
    int temp;
    for(i = front, j = rear; i < j; i++, j--)
    {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }

    printf("\n Reversed Queue: Front -> Rear\n   ");
    for(i = 0; i < rear; i++)
    {
        printf("%d -> ", queue[i]);
    }
    printf("%d\n", queue[i]);

    return 0;
}
