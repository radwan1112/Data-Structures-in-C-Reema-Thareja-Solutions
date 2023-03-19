#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;


void insert(int val)
{
    if(rear == MAX - 1)
    {
        printf("\n QUEUE OVERFLOW");
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

int delete_element()
{
    int val;

    if(front == -1 || front > rear)
    {
        printf("\n queue underflow");
    }
    else
    {
        val = queue[front];
        front++;
    }
    return val;
}

int peek()
{
    if(front == -1 || front > rear)
    {
        printf("\n queue underflow");
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
    }
    else
    {
        int i = front;
        printf("\n\t");
        while(i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
}


int main()
{
    int option, val;

    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");

        printf("\n Enter your option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter value to insert: ");
            scanf(" %d", &val);
            insert(val);
            break;
        case 2:
            val = delete_element();
            if(val != -1)
            {
                printf("\n The deleted value is %d", val);
            }
            break;
        case 3:
            val = peek();
            if(val != -1)
            {
                printf("The first value in the queue is %d", val);
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
