#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    int priority;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    return q;
}

struct queue *enqueue(struct queue *q, char val, int p)
{
    struct node *new_node, *ptr, *preptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        new_node->data = val;
        new_node->priority = p;
        if(q->front == NULL)
        {
            q->front = new_node;
            q->rear = new_node;
            new_node->next = NULL;
        }
        else
        {
            preptr = NULL;
            ptr = q->front;
            while(ptr != NULL)
            {
                if(new_node->priority < ptr->priority)
                {
                    break;
                }
                preptr = ptr;
                ptr = ptr->next;
            }
            if(ptr == q->front)
            {
                new_node->next = q->front;
                q->front = new_node;
            }
            else if(ptr == NULL)
            {
                q->rear->next = new_node;
                new_node->next = NULL;
                q->rear = new_node;
            }
            else
            {
                preptr->next = new_node;
                new_node->next = ptr;
            }
        }
    }
    return q;
};

struct queue *dequeue(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else
    {
        struct node *ptr;
        ptr = q->front;
        q->front = ptr->next;
        free(ptr);
    }
    return q;
};

char peek(struct queue *q)
{
    if(q->front == NULL)
    {
        printf("\n QUEUE IS EMPTY\n");
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
        return;
    }
    struct node *ptr;
    ptr = q->front;
    printf("\n  ");
    while(ptr->next != NULL)
    {
        printf("%c|%d -> ", ptr->data, ptr->priority);
        ptr = ptr->next;
    }
    printf("%c|%d\n", ptr->data, ptr->priority);
}

int main()
{
    int option;
    char val;
    int p;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q = create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert new element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter value: ");
            scanf(" %c", &val);
            printf("\n 1. Highest priority");
            printf("\n 2. High priority");
            printf("\n 3. Medium priority");
            printf("\n 4. Low priority");
            printf("\n Select priority: ");
            scanf(" %d", &p);
            if(p > 0 && p < 5)
            {
                q = enqueue(q, val, p);
            }
            else
            {
                printf("\n Invalid input");
            }
            break;
        case 2:
            val = peek(q);
            q = dequeue(q);
            if(val != '\0')
            {
                printf("\n The deleted value is %c", val);
            }
            break;
        case 3:
            val = peek(q);
            if(val != '\0')
            {
                printf("\n The next value inline is %c", val);
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
    free(q);
    return 0;
}
