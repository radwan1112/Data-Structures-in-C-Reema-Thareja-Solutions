#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *start2 = NULL;

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf(" %d", &num);
    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf(" %d", &num);
    }
    return start;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start ;
    printf("\n {");
    while(ptr != NULL)
    {
        if(ptr->next == NULL)
        {
            printf("%d}", ptr->data);
        }
        else
        {
            printf("%d, ", ptr->data);
        }
        ptr = ptr->next;
    }
    return start;
};

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf(" %d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;

};

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data: ");
    scanf(" %d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->data = num;
    new_node->next = NULL;
    return start;
};

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, node_pos;
    int i = 0;
    printf("\n Enter the data: ");
    scanf(" %d", &num);
    printf("\n Insert before which node: ");
    scanf(" %d", &node_pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr != NULL)
    {
        if(i == node_pos)
        {
            if(i == 0)
            {
                new_node->next = ptr;
                start = new_node;
            }
            else
            {
                new_node->next = ptr;
                preptr->next = new_node;
            }
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }
    return start;
};

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int num, node_pos;
    int i = 0;
    printf("\n Enter the data: ");
    scanf(" %d", &num);
    printf("\n Insert after which node: ");
    scanf(" %d", &node_pos);
    new_node->data = num;
    ptr = start;

    while(ptr != NULL)
    {
        if(i == node_pos)
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        ptr = ptr->next;
        i++;
    }
    return start;
};

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
};

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
};

struct node *delete_node(struct node *start)
{
    printf("\n Enter the index pos of the node you wish to delete: ");
    int pos;
    scanf(" %d", &pos);
    struct node *ptr, *preptr;

    ptr = start;
    int i = 0;
    while(ptr != NULL)
    {
        if(i == pos)
        {
            if(i == 0)
            {
                start = ptr->next;
                free(ptr);
            }
            else if(ptr->next == NULL)
            {
                preptr->next = NULL;
                free(ptr);
            }
            else
            {
                preptr->next = ptr->next;
                free(ptr);
            }
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }
    return start;
};

struct node *delete_after(struct node *start)
{
    printf("\n Enter the index position to delete a node after a given node: ");
    int pos;
    scanf(" %d", &pos);
    pos++;
    struct node *ptr, *preptr;
    ptr = start;
    int i = 0;
    while(ptr != NULL)
    {
        if(i == pos)
        {
            if(ptr->next == NULL)
            {
                preptr->next = NULL;
                free(ptr);
            }
            else
            {
                preptr->next = ptr->next;
                free(ptr);
            }
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }
    return start;
};

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\n %d is to be deleted next", ptr -> data);
        start = delete_beg(ptr);
        ptr = start;
    }
    return start;
};

struct node *sort_list(struct node *start)
{
    int temp;
    struct node *ptr, *ptr2;
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr2 = ptr->next;
        while(ptr2 != NULL)
        {
            if(ptr->data > ptr2->data)
            {
                temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    return start;
};

struct node *alt_list(struct node *start, struct node *start2)
{
    struct node *new_node, *ptr, *ptr2;
    ptr = start;

    while(ptr != NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->next = NULL;
        new_node->data = ptr->data;
        if(start2 == NULL)
        {
            start2 = new_node;
        }
        else
        {
            ptr2 = start2;
            while(ptr2->next != NULL)
            {
                ptr2 = ptr2->next;
            }
            ptr2->next = new_node;
        }
        if(ptr->next == NULL)
        {
            ptr = ptr->next;
        }
        else
        {
            ptr = ptr->next->next;
        }
    }

    return start2;
};

int main()
{

    int option;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a new list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: Create a link list with alternate elements");
        printf("\n 14: Print alternating linked list");
        printf("\n 15: EXIT");
        printf("\n\n Enter your option: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            start = create_ll(start);
            printf("\n LINK LIST CREATED");
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
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
        case 12:
            start = sort_list(start);
            break;
        case 13:
            start2 = alt_list(start, start2);
            printf("\n ALTERNATING LIST CREATED");
            break;
        case 14:
            printf("\n\n Printing alternate linked list");
            start2 = display(start2);
            break;
        default:
            option = 15;
            break;
        }
    }
    while(option != 15);

    return 0;
}
