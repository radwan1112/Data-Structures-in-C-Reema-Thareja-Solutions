#include <stdio.h>
#include <stdlib.h>

//Node structre
struct node
{
    int data;
    struct node *next;
};

// Starting Pointer
struct node *start = NULL;

//Preloading functions
struct node *create_chll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n 1: Create a circular header linked list");
        printf("\n 2: Display the list");
        printf("\n 3: Delete first node from the list");
        printf("\n 4: Delete the last node from the list");
        printf("\n 5: Delete the given node");
        printf("\n 6: EXIT \n");

        printf("\n ENTER OPTION: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            start = create_chll(start);
            printf("\n CHLL HAS BEEN CREATED\n");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = delete_beg(start);
            printf("\n ITEM DELETED\n");
            break;
        case 4:
            start = delete_end(start);
            printf("\n ITEM DELETED\n");
            break;
        case 5:
            start = delete_node(start);
            printf("\n ITEM DELETED\n");
            break;
        default:
            option = 6;
            break;
        }

    }
    while(option != 6);


    return 0;
}

struct node *create_chll(struct node *start)
{
    struct node *new_node, *ptr;

    int num;
    printf("\n ENTER -1 TO END\n");
    printf("\n Enter Data: ");
    scanf(" %d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->next = new_node;
            new_node->next = start;
        }
        else
        {
            ptr = start->next;
            while(ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter Data: ");
        scanf(" %d", &num);
    }

    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;

    ptr = start->next;
    printf("\n{");
    while(ptr->next != start)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d}\n", ptr->data);

    return start;
};

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start->next;
    start->next = ptr->next;
    free(ptr);
    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start->next;
    preptr = start;
    while(ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);

    return start;
};

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;

    int num;
    printf("\n Enter the value: ");
    scanf(" %d", &num);
    ptr = start->next;
    preptr = ptr;

    while(ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == start->next)
    {
        start = delete_beg(start);
    }
    else if(ptr->next == start)
    {
        start = delete_end(start);
    }
    else
    {
        preptr->next = ptr->next;
        free(ptr);
    }


    return start;
};
