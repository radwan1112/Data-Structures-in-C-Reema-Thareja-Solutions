#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

struct queue *enqueue(struct queue *q, int val)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = q->front;

    if(q->front == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    return q;
};

struct queue *dequeue(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        struct node *ptr;
        ptr = q->front;
        if(q->front == q->rear)
        {
            q->front = NULL;
            q->rear = NULL;
            free(ptr);
        }
        else
        {
            q->front = q->front->next;
            q->rear->next = q->front;
            free(ptr);
        }
    }
    return q;
};

int peek(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n EMPTY QUEUE");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}

void display(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n QUEUE IS EMPTY\n");
    }
    else
    {
        struct node *ptr;
        ptr = q->front;

        printf("\n  ");
        while(ptr->next != q->front)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
}

int main()
{
    int option, val;

    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert a new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter number to insert: ");
            scanf(" %d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            val = peek(q);
            q = dequeue(q);
            if(val != -1)
            {
                printf("\n The deleted value %d", val);
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

    return 0;
}
