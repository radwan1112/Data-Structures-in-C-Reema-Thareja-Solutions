#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *start_backup = NULL;

struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    int num;
    scanf(" %d", &num);
    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            start = new_node;
            new_node->next = start;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter the data : ");
        scanf(" %d", &num);
    }

    return start;
};

struct node *display(struct node *start)
{

    struct node *ptr;
    ptr = start;

    printf("[");
    while(ptr->next != start)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d]", ptr->data);
    return start;
};

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    printf("\n Enter data to add at the beginning: ");
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    scanf(" %d", &num);
    new_node->data = num;
    ptr = start;

    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;

    return start;
};

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter data to insert at the end: ");
    int num;
    scanf(" %d", &num);
    new_node->data = num;
    ptr = start;

    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;

    return start;
};

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;

    while(ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);

    return start;
};

struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int value;
    ptr = start;

    while(preptr != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

    return start;
};

struct node *delete_list(struct node *start)
{
    if(start == NULL)
    {
        return start;
    }
    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
    {
        start = delete_end(start);
        ptr = ptr->next;
    }
    free(start);
    return start;
};

struct node *backup_list(struct node *start, struct node *start_backup)
{
    struct node *new_node, *ptr, *ptr2;
    ptr = start;
    ptr2 = start_backup;

    do
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->next = start_backup;
        new_node->data = ptr->data;

        if(start_backup == NULL)
        {
            start_backup = new_node;
            ptr2 = start_backup;
        }
        else
        {
            ptr2->next = new_node;
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    while(ptr != start);


    return start_backup;
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
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: Back up the list");
        printf("\n 10: EXIT");
        printf("\n\n Enter your option : ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            start = create_cll(start);
            printf("\n CIRCULAR LINKED LIST CREATED");
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
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n CIRCULAR LINKED LIST DELETED");
            break;
        case 9:
            start_backup = delete_list(start_backup);
            start_backup = backup_list(start, start_backup);
            start_backup = display(start_backup);
            break;
        default:
            option = 10;
            break;
        }
    }
    while(option !=10);

    return 0;
}
