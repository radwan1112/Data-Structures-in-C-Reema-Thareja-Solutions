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
    new_node->next = NULL;

    if(q->front == NULL && q->rear == NULL)
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
    struct node *ptr;
    if(q->front == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else
    {
        ptr = q->front;
        q->front = ptr->next;
        free(ptr);
    }
    return q;
}

int peek(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n QUEUE IS EMPTY");
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
        printf("\n QUEUE US EMPTY");
        return;
    }
    struct node *ptr;
    ptr = q->front;

    while(ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

int main()
{
    int option, val;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display Queue");
        printf("\n 5. EXIT\n");

        printf("\n Enter Option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter a number: ");
            scanf(" %d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            val = peek(q);
            q = dequeue(q);
            if(val != -1)
            {
                printf("\n The value deleted is %d", val);
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
