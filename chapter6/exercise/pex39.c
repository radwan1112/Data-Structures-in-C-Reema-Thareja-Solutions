#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_chll(struct node *start)
{
    struct node *new_node, *ptr;
    printf("\n Enter -1 to end\n");
    printf("\n Enter number: ");
    int num;
    scanf(" %d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->next = new_node;
            start->prev = new_node;
            new_node->next = start;
            new_node->prev = start;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
        }
        printf("\n Enter number: ");
        scanf(" %d", &num);
    }

    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start->next;
    printf("\n Start -> ");
    while(ptr->next != start)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);

    return start;
};

struct node *delete_beg(struct node *start)
{

    struct node *ptr;
    ptr = start->next;
    start->next = ptr->next;
    ptr->next->prev = start;
    free(ptr);

    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start->next;
    preptr = NULL;
    while(ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    start->prev = preptr;
    free(ptr);

    return start;
};

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;

    printf("\n Enter value you wish to delete: ");
    int value;
    scanf(" %d", &value);

    ptr = start->next;
    preptr = NULL;

    while(ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == start->next)
    {
        start = delete_beg(start);
    }
    else
    {
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
    }

    return start;
};

struct node *delete_value(struct node *start, int value)
{
    struct node *ptr, *preptr;

    ptr = start->next;
    preptr = NULL;

    while(ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == start->next)
    {
        start = delete_beg(start);
    }
    else
    {
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
    }

    return start;
};

struct node *delete_all_negatives(struct node *start)
{

    struct node *ptr;

    ptr = start->next;

    while(ptr != start)
    {
        if(ptr->data < 0)
        {
            start = delete_value(start, ptr->data);
        }
        ptr = ptr->next;
    }


    return start;
};

int main()
{

    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a Circular header linked list");
        printf("\n 2: Display the list");
        printf("\n 3: Delete the first node");
        printf("\n 4: Delete the last node");
        printf("\n 5: Delete node by value");
        printf("\n 6: Delete all negative values");
        printf("\n 7: EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_chll(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = delete_beg(start);
            break;
        case 4:
            start = delete_end(start);
            break;
        case 5:
            start = delete_node(start);
            break;
        case 6:
            start = delete_all_negatives(start);
            break;
        default:
            option = 7;
            break;
        }
    }
    while(option != 7);

    return 0;
}
