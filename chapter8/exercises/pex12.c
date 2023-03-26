#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct queue
{
    int queue[MAX];
    int front;
    int rear;
};

struct queue *enqueue(struct queue *q, int val)
{
    if((q->rear + 1) % MAX == q->front)
    {
        printf("\n OVERFLOW\n");
        return q;
    }
    if(q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else if(q->rear == MAX - 1 && q->front  != 0)
    {
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->queue[q->rear] = val;
    return q;
}

struct queue *dequeue(struct queue *q)
{
    if(q->front == -1 || q->rear == -1)
    {
        printf("\n UNDERFLOW\n");
        return q;
    }
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        if(q->front == MAX - 1)
        {
            q->front = 0;
        }
        else
        {
            q->front++;
        }
    }
    return q;
}

int peek(struct queue *q)
{
    if(q->front == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    return q->queue[q->front];
}

void display(struct queue *q)
{
    if(q->front == -1)
    {
        printf("\n QUEUE IS EMPTY\n");
    }
    else
    {
        int i;
        printf("\n   ");
        if(q->front > q->rear)
        {
            for(i = q->front; i < MAX; i++)
            {
                printf("%d -> ", q->queue[i]);
            }
            for(i = 0; i < q->rear; i++)
            {
                printf("%d -> ", q->queue[i]);
            }
            printf("%d", q->queue[i]);
        }
        else
        {
            for(i = q->front; i < q->rear; i++)
            {
                printf("%d -> ", q->queue[i]);
            }
            printf("%d", q->queue[i]);
        }
    }
}

struct queue *create_q(struct queue *q)
{
    int option, val;
    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert a new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. EXIT\n");

        printf("\n Enter Option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter number: ");
            scanf(" %d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            val = peek(q);
            q = dequeue(q);
            if(val != -1)
            {
                printf("The value deleted is %d", val);
            }
            break;
        case 3:
            val = peek(q);
            if(val != -1)
            {
                printf("\n The front value is %d", val);
            }
            break;
        case 4:
            display(q);
            break;
        default:
            option = 5;
            break;
        }
    }
    while(option != 5);
    return q;
}

int cmp_queue(struct queue *q1, struct queue *q2)
{
    int s1 = abs(abs(MAX - q1->front) - abs(MAX - q1->rear)) + 1;
    int s2 = abs(abs(MAX - q2->front) - abs(MAX - q2->rear)) + 1;
    int i, j, k;

    if(s1 != s2)
    {
        return 0;
    }
    else
    {
        for(i = 0, j = q1->front, k = q2->front; i < s1; i++, j = (j + 1) % MAX, k = (k + 1) % MAX)
        {
            if(q1->queue[j] != q2->queue[k])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int option, val;
    struct queue *q1;
    struct queue *q2;
    q1 = (struct queue *)malloc(sizeof(struct queue));
    q2 = (struct queue *)malloc(sizeof(struct queue));
    if(q1 == NULL || q2 == NULL)
    {
        printf("\n OVERFLOW\n");
        return 0;
    }
    q1->front = -1;
    q1->rear = -1;
    q2->front = -1;
    q2->rear = -1;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Create or modify Queue 1");
        printf("\n 2. Create or modify Queue 2");
        printf("\n 3. Compare Queue 1 and Queue 2");
        printf("\n 4. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            q1 = create_q(q1);
            break;
        case 2:
            q2 = create_q(q2);
            break;
        case 3:
            val = cmp_queue(q1, q2);
            if(val == 1)
            {
                printf("\n Queue 1 and Queue 2 are identical\n");
            }
            else
            {
                printf("\n Queue 1 and 2 are different\n");
            }
            break;
        default:
            option = 4;
            break;
        }
    }
    while(option != 4);
    free(q1);
    free(q2);

    return 0;
}
