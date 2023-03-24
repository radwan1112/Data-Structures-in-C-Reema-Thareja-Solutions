#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front_a = -1;
int rear_a = -1;
int rear_b = MAX;
int front_b = MAX;

void insertA(int val)
{
    if(rear_a + 1 == rear_b)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        if(front_a <= -1 && rear_a <= -1)
        {
            front_a = rear_a = 0;
            queue[rear_a] = val;
        }
        else
        {
            queue[++rear_a] = val;
        }
    }
}

void insertB(int val)
{
    if(rear_b - 1 == rear_a)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        if(front_b >= MAX && rear_b >= MAX)
        {
            front_b = rear_b = MAX - 1;
            queue[rear_b] = val;
        }
        else
        {
            queue[--rear_b] = val;
        }
    }
}

int deleteA()
{
    if(front_a == -1)
    {
        printf("\n UNDERFLOW\n");
        return -1;
    }
    else
    {
        int val = queue[front_a];
        front_a++;
        if(front_a > rear_b)
        {
            front_a = rear_a = -1;
        }
        return val;
    }
}

int deleteB()
{
    if(front_b == MAX)
    {
        printf("\n UNDERFLOW\n");
        return -1;
    }
    else
    {
        int val = queue[front_b];
        front_b--;
        if(front_b < rear_b)
        {
            front_b = rear_b = MAX;
        }
        return val;
    }
}

void display_queueA()
{
    if(front_a == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    else
    {
        int i;
        printf("\n   ");
        for(i = front_a; i < rear_a; i++)
        {
            printf("%d -> ", queue[i]);
        }
        printf("%d", queue[i]);
    }
}

void display_queueB()
{
    if(front_b == MAX)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    else
    {
        int i;
        printf("\n   ");
        for(i = front_b; i > rear_b; i--)
        {
            printf("%d -> ", queue[i]);
        }
        printf("%d", queue[i]);
    }
}

int main()
{
    int option, val;
    do
    {
        printf("\n *******MENU******");
        printf("\n 1. INSERT IN QUEUE A");
        printf("\n 2. INSERT IN QUEUE B");
        printf("\n 3. DELETE FROM QUEUE A");
        printf("\n 4. DELETE FROM QUEUE B");
        printf("\n 5. DISPLAY QUEUE A");
        printf("\n 6. DISPLAY QUEUE B");
        printf("\n 7. EXIT");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\n Enter the value to be inserted in Queue A : ");
            scanf("%d",&val);
            insertA(val);
            break;
        case 2:
            printf("\n Enter the value to be inserted in Queue B : ");
            scanf("%d",&val);
            insertB(val);
            break;
        case 3:
            val=deleteA();
            if(val > -1)
                printf("\n The value deleted from Queue A = %d",val);
            break;
        case 4 :
            val=deleteB();
            if(val > -1)
                printf("\n The value deleted from Queue B = %d", val);
            break;
        case 5:
            printf("\n The contents of Queue A are: \n");
            display_queueA();
            break;
        case 6:
            printf("\n The contents of Queue B are: \n");
            display_queueB();
            break;
        default:
            option = 7;
            break;
        }
    }
    while(option != 7);
    return 0;
}
