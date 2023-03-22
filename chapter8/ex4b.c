#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct queue
{
    struct node *left;
    struct node *right;
    int size;
};

void create_queue(struct queue *q)
{
    q->left = NULL;
    q->right = NULL;
    q->size = 0;
}

struct queue *l_push(struct queue *q, int val)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        new_node->data = val;
        new_node->prev = NULL;
        if(q->left == NULL)
        {
            q->left = new_node;
            q->right = new_node;
        }
        else
        {
            new_node->next = q->left;
            q->left->prev = new_node;
            q->left = new_node;
        }
        q->size++;
    }
    return q;
};

struct queue *r_push(struct queue *q, int val)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        new_node->data = val;
        new_node->next = NULL;
        if(q->right == NULL)
        {
            q->left = new_node;
            q->right = new_node;
        }
        else
        {
            new_node->prev = q->right;
            q->right->next = new_node;
            q->right = new_node;
        }
        q->size++;
    }
    return q;
};

struct queue *l_pop(struct queue *q)
{
    if(q->left == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else
    {
        struct node *ptr;
        ptr = q->left;
        q->left = q->left->next;
        if(q->left == NULL)
        {
            q->right == NULL;
        }
        else
        {
            q->left->prev = NULL;
        }
        free(ptr);
        q->size--;
    }
    return q;
};

struct queue *r_pop(struct queue *q)
{
    if(q->left == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else
    {
        struct node *ptr;
        ptr = q->right;
        q->right = q->right->prev;
        if(q->right == NULL)
        {
            q->left = NULL;
        }
        else
        {
            q->right->next = NULL;
        }
        free(ptr);
        q->size--;
    }
};

int l_peek(struct queue *q)
{
    if(q->left == NULL)
    {
        printf("\n EMPTY QUEUE\n");
        return -1;
    }
    else
    {
        return q->left->data;
    }
}

int r_peek(struct queue *q)
{
    if(q->right == NULL)
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        return q->right->data;
    }
}

void display(struct queue *q)
{
    if(q->left == NULL)
    {
        printf("\n EMPTY QUEUE\n");
    }
    else
    {
        struct node *ptr;
        ptr = q->left;
        printf("\n  ");
        while(ptr->next != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
}

struct queue *deque()
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
        printf("\n 4. Display");
        printf("\n 5. EXIT");

        printf("\n Enter option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n 1. Insert element from left");
            printf("\n 2. Insert element from right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                q = l_push(q, val);
                break;
            case 2:
                q = r_push(q, val);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("\n 1. Delete element from left");
            printf("\n 2. Delete element from right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                q = l_pop(q);
                if(val != -1)
                {
                    printf("\n The deleted value is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                q = r_pop(q);
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
            printf("\n 1. Peek left");
            printf("\n 2. Peek right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                if(val != -1)
                {
                    printf("\n The value at left is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                if(val != -1)
                {
                    printf("\n The value at the right is %d", val);
                }
                break;
            default:
                break;
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

struct queue *l_input_deque()
{
    int option, val;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
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
            scanf(" %d", &val);
            q = l_push(q, val);
            break;
        case 2:
            printf("\n 1. Delete left element");
            printf("\n 2. Delete right element");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                q = l_pop(q);
                if(val != -1)
                {
                    printf("\n The value deleted is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                q = r_pop(q);
                if(val != -1)
                {
                    printf("\n The value deleted is %d", val);
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Peek left");
            printf("\n 2. Peek right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                if(val != -1)
                {
                    printf("\n Left value is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                if(val != -1)
                {
                    printf("\n Right value is %d", val);
                }
                break;
            default:
                break;
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

};

struct queue *r_input_deque()
{
    int option, val;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
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
            scanf(" %d", &val);
            q = r_push(q, val);
            break;
        case 2:
            printf("\n 1. Delete left element");
            printf("\n 2. Delete right element");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                q = l_pop(q);
                if(val != -1)
                {
                    printf("\n The value deleted is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                q = r_pop(q);
                if(val != -1)
                {
                    printf("\n The value deleted is %d", val);
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Peek left");
            printf("\n 2. Peek right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                if(val != -1)
                {
                    printf("\n Left value is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                if(val != -1)
                {
                    printf("\n Right value is %d", val);
                }
                break;
            default:
                break;
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
};

struct queue *r_output_deque()
{
    int option, val;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n 1. Insert element from the left");
            printf("\n 2. Insert element from the right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                q = l_push(q, val);
                break;
            case 2:
                q = r_push(q, val);
                break;
            default:
                break;
            }
            break;
        case 2:
            val = r_peek(q);
            q = r_pop(q);
            if(val != -1)
            {
                printf("\n The value deleted is %d", val);
            }
            break;
        case 3:
            printf("\n 1. Peek left");
            printf("\n 2. Peek right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                if(val != -1)
                {
                    printf("\n Left value is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                if(val != -1)
                {
                    printf("\n Right value is %d", val);
                }
                break;
            default:
                break;
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
};

struct queue *l_output_deque()
{
    int option, val;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Insert element");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            printf("\n 1. Insert element from the left");
            printf("\n 2. Insert element from the right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            printf("\n Enter value: ");
            scanf(" %d", &val);
            switch(option)
            {
            case 1:
                q = l_push(q, val);
                break;
            case 2:
                q = r_push(q, val);
                break;
            default:
                break;
            }
            break;
        case 2:
            val = l_peek(q);
            q = l_pop(q);
            if(val != -1)
            {
                printf("\n The value deleted is %d", val);
            }
            break;
        case 3:
            printf("\n 1. Peek left");
            printf("\n 2. Peek right");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                val = l_peek(q);
                if(val != -1)
                {
                    printf("\n Left value is %d", val);
                }
                break;
            case 2:
                val = r_peek(q);
                if(val != -1)
                {
                    printf("\n Right value is %d", val);
                }
                break;
            default:
                break;
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
};


int main()
{
    int option, val;
    struct queue *q;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Create a deque");
        printf("\n 2. Create Input restricted deque");
        printf("\n 3. Create Output restricted deque");
        printf("\n 4. EXIT\n");
        printf("\n Enter option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            q = deque();
            free(q);
            break;
        case 2:
            printf("\n 1. Right input restricted deque");
            printf("\n 2. Left input restricted deque");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                q = l_input_deque();
                free(q);
                break;
            case 2:
                q = r_input_deque();
                free(q);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n 1. Right output restricted deque");
            printf("\n 2. Left input restricted deque");
            printf("\n Enter option: ");
            scanf(" %d", &option);
            switch(option)
            {
            case 1:
                q = r_output_deque();
                free(q);
                break;
            case 2:
                q = l_output_deque();
                free(q);
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
