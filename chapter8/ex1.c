#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[5];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if(rear == MAX - 1)
    {
        printf("\n OVERFLOW \n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = val;
}

int dequeue()
{
    int val;
    if(front == -1 || front > rear)
    {
        printf("\n Underflow");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
        return val;
    }
}

int peek()
{
    if(front == -1 || front > rear)
    {
        printf("\n Underflow");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    int i;
    printf("\n  ");
    for(i = front; i < rear; i++)
    {
        printf("%d -> ", queue[i]);
    }
    printf("%d", queue[i]);
}

int main()
{
    int option, val;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display queue");
        printf("\n 5. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter number to insert: ");
            scanf(" %d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if(val != -1)
            {
                printf("\n The value deleted is %d", val);
            }
            break;
        case 3:
            val = peek();
            if(val != -1)
            {
                printf("\n The front value is %d", val);
            }
            break;
        case 4:
            display();
            break;
        default:
            option = 5;
            break;
        }
    }
    while(option != 5);

    return 0;
}
