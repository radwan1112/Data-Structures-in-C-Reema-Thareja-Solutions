#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if(front == 0 && rear == MAX - 1)
    {
        printf("\n OVERFLOW");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else if(rear == MAX - 1 && front != 0)
    {
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
    if(front == -1 && rear == -1)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    int val = queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}

int peek()
{
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    return queue[front];
}

void display()
{
    int i;
    printf("\n  ");
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        if(front<rear)
        {
            for(i=front; i<=rear; i++)
                printf("\t %d", queue[i]);
        }
        else
        {
            for(i=front; i<MAX; i++)
                printf("\t %d", queue[i]);
            for(i=0; i<=rear; i++)
                printf("\t %d", queue[i]);
        }
    }
}

int main()
{
    int option, val;

    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT\n");
        printf("\n Enter your option : ");

        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter number to add: ");
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
