#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_dll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter data: ");
    scanf(" %d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\n Enter data: ");
        scanf(" %d", &num);
    }

    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("{");
    while(ptr->next != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d}", ptr->data);
    return start;
};

struct node *insert_beg(struct node *start)
{
    printf("\n Enter data: ");
    int num;
    scanf(" %d", &num);
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
};

struct node *insert_end(struct node *start)
{
    printf("\n Enter data: ");
    int num;
    scanf(" %d", &num);
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;

    return start;
};

struct node *insert_before(struct node *start)
{
    printf("\n Enter data: ");
    int num, value;
    scanf(" %d", &num);
    printf("\n Enter value: ");
    scanf(" %d", &value);
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != value)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return start;
};

struct node *insert_after(struct node *start)
{
    printf("\n Enter data: ");
    int num, value;
    scanf(" %d", &num);
    printf("\n Enter value: ");
    scanf(" %d", &value);
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    while(ptr->data != value)
    {
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;

    return start;
};

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = ptr->next;
    start->prev = NULL;
    free(ptr);
    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
};

struct node *delete_before(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    int num;
    printf("\n Enter data: ");
    scanf(" %d", &num);
    while(ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(preptr == start)
    {
        start = delete_beg(start);
    }
    else
    {
        ptr->prev = preptr->prev;
        preptr->prev->next = ptr;
    }
    free(preptr);
    return start;
};


struct node *delete_after(struct node *start)
{
    struct node *ptr, *nextptr;
    ptr = start;
    int num;
    printf("\n Enter data: ");
    scanf(" %d", &num);

    while(ptr->data != num)
    {
        ptr = ptr->next;
    }
    nextptr = ptr->next;

    ptr->next = nextptr->next;
    nextptr->next->prev = ptr;
    free(nextptr);

    return start;
};

struct node *delete_list(struct node *start)
{
    while(start != NULL)
    {
        start = delete_beg(start);
    }
    return start;
};

struct node *move_mid2beg(struct node *start)
{
    struct node *fastptr, *slowptr;

    if(start == NULL || start->next == NULL || start->next->next == NULL)
    {
        return start;
    }

    fastptr = start;
    slowptr = start;

    while(fastptr != NULL && fastptr->next != NULL)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }

    if(slowptr == start)
    {
        return start;
    }
    else
    {
        slowptr->prev->next = slowptr->next;
        slowptr->next->prev = slowptr->prev;
        slowptr->next = start;
        start->prev = slowptr;
        slowptr->prev = NULL;
        start = slowptr;
    }

    return start;
};

int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Move middle node to the beginning of the list");
        printf("\n 13: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_dll(start);
            printf("\n DOUBLY LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_before(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n Doubly linked list deleted");
            break;
        case 12:
            start = move_mid2beg(start);
            printf("\n NODE HAS BEEN MOVED");
            break;
        default:
            option = 13;
            break;
        }
    }
    while(option != 13);



    return 0;
}
