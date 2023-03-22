#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void push_front(int val)
{
    if((front == 0 && rear == MAX - 1) || front == rear + 1)
    {
        printf("\n OVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    queue[front] = val;
}

void push_rear(int val)
{
    if((front == 0 && rear == MAX - 1) || front == rear + 1)
    {
        printf("\n OVERFLOW\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = val;
}

int pop_front()
{
    if(front == -1 && rear == -1)
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
    else if(front == (MAX - 1))
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return val;
}

int pop_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("\n UNDERFLOW\n");
        return -1;
    }
    int val = queue[rear];
    if(rear == front)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
    return val;
}

int peek_front()
{
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int peek_rear()
{
    if(rear == -1 && front == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[rear];
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        int i;
        printf("\n   ");
        i = front;
        while(i != rear)
        {
            printf("%d -> ", queue[i]);
            i = (i+1) % MAX;
        }
        printf("%d", queue[i]);
    }
}

void deque()
{
    int option, val;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n 1. Insert new element at the front");
            printf("\n 2. Insert new element from the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value to add: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                push_front(val);
                break;
            case 2:
                push_rear(val);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("\n 1. Pop element at the front");
            printf("\n 2. Pop element at the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = pop_front();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            case 2:
                val = pop_rear();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Peek value at front");
            printf("\n 2. Peek value at rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = peek_front();
                if(val != -1)
                {
                    printf("\n The value at front is %d", val);
                }
                break;
            case 2:
                val = peek_rear();
                if(val != -1)
                {
                    printf("\n The value at rear is %d", val);
                }
                break;
            default:
                break;
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
}

void l_input_deque()
{
    int option, val;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter value: ");
            scanf(" %d", &val);
            push_front(val);
            break;
        case 2:
            printf("\n 1. Delete element from the front");
            printf("\n 2. Delete element from the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = pop_front();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            case 2:
                val = pop_rear();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Peek front");
            printf("\n 2. Peek back");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = peek_front();
                if(val != -1)
                {
                    printf("\n Front value is %d", val);
                }
                break;
            case 2:
                val = peek_rear();
                if(val != -1)
                {
                    printf("\n Rear value is %d", val);
                }
                break;
            default:
                break;
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
}

void r_input_deque()
{
    int option, val;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter value: ");
            scanf(" %d", &val);
            push_rear(val);
            break;
        case 2:
            printf("\n 1. Delete element from the front");
            printf("\n 2. Delete element from the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = pop_front();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            case 2:
                val = pop_rear();
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Peek front");
            printf("\n 2. Peek back");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = peek_front();
                if(val != -1)
                {
                    printf("\n Front value is %d", val);
                }
                break;
            case 2:
                val = peek_rear();
                if(val != -1)
                {
                    printf("\n Rear value is %d", val);
                }
                break;
            default:
                break;
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
}

void l_output_deque()
{
    int option, val;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n 1. Insert element from the front");
            printf("\n 2. Insert element from the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                push_front(val);
                break;
            case 2:
                push_rear(val);
                break;
            default:
                break;
            }
            break;
        case 2:
            val = pop_front();
            if(val != -1)
            {
                printf("\n The deleted value is %d", val);
            }
            break;
        case 3:
            printf("\n 1. Peek front");
            printf("\n 2. Peek back");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = peek_front();
                if(val != -1)
                {
                    printf("\n Front value is %d", val);
                }
                break;
            case 2:
                val = peek_rear();
                if(val != -1)
                {
                    printf("\n Rear value is %d", val);
                }
                break;
            default:
                break;
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
}

void r_output_deque()
{
    int option, val;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n 1. Insert element from the front");
            printf("\n 2. Insert element from the rear");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                push_front(val);
                break;
            case 2:
                push_rear(val);
                break;
            default:
                break;
            }
            break;
        case 2:
            val = pop_rear();
            if(val != -1)
            {
                printf("\n The deleted value is %d", val);
            }
            break;
        case 3:
            printf("\n 1. Peek front");
            printf("\n 2. Peek back");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = peek_front();
                if(val != -1)
                {
                    printf("\n Front value is %d", val);
                }
                break;
            case 2:
                val = peek_rear();
                if(val != -1)
                {
                    printf("\n Rear value is %d", val);
                }
                break;
            default:
                break;
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
}

int main()
{
    int option, val;
    do
    {
        printf("\n *****MENU****");
        printf("\n 1. Create a double ended deque");
        printf("\n 2. Create an Input restricted deque");
        printf("\n 3. Create an output restricted deque");
        printf("\n 4. EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            deque();
            break;
        case 2:
            printf("\n 1. Right input restricted deque");
            printf("\n 2. Left input restricted deque");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                l_input_deque();
                break;
            case 2:
                r_input_deque();
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Right output restricted deque");
            printf("\n 2. Left output restricted deque");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                l_output_deque();
                break;
            case 2:
                r_output_deque();
                break;
            default:
                break;
            }
            break;
        default:
            option = 4;
            break;
        }
    }
    while(option != 4);
    return 0;
}
