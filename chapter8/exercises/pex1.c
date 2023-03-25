#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if((rear + 1) % MAX == front)
    {
        printf("\n OVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == MAX - 1 && front  != 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
}

int dequeue()
{
    if(front == -1)
    {
        printf("\n UNDERFLOW\n");
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
    if(front == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    return queue[front];
}

void display()
{
    if(front == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
    }
    else
    {
        int i;
        printf("\n   ");
        if(front > rear)
        {
            for(i = front; i < MAX; i++)
            {
                printf("%d -> ", queue[i]);
            }
            for(i = 0; i < rear; i++)
            {
                printf("%d -> ", queue[i]);
            }
            printf("%d", queue[i]);
        }
        else
        {
            for(i = front; i < rear; i++)
            {
                printf("%d -> ", queue[i]);
            }
            printf("%d", queue[i]);
        }
    }
}

int find_length()
{
    if(front == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        return abs(abs(MAX - front) - abs(MAX - rear)) + 1;
    }
}

int main()
{
    int option, val, len;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert a new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Length");
        printf("\n 6. EXIT\n");
        printf("\n Enter Option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter number: ");
            scanf(" %d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if(val != -1)
            {
                printf("The value deleted is %d", val);
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
        case 5:
            len = find_length();
            if(len >= 1)
            {
                printf("\n Circular queue have %d elements now", len);
            }
            break;
        default:
            option = 6;
            break;
        }
    }
    while(option != 6);
    return 0;
}
