#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_cdll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter data: ");
    scanf(" %d", &num);
    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL)
        {
            start = new_node;
            new_node->prev = start;
            new_node->next = start;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
            {
                ptr = ptr->next;
            }
            new_node->prev = ptr;
            ptr->next = new_node;
            new_node->next = start;
            start->prev = new_node;
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
    printf("\n {");
    while(ptr->next != start)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d}", ptr->data);
    return start;
};

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter data: ");
    scanf(" %d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
};

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    printf("\n Enter data: ");
    int num;
    scanf(" %d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = start;
    start->prev = new_node;
    return start;
};

struct node *delete_beg(struct node *start)
{
    struct node *ptr, *temp;
    ptr = start;

    while(ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    temp = start;
    start = start->next;
    start->prev = ptr;
    free(temp);
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
    start->prev = preptr;
    free(ptr);
    return start;
};

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int value;
    printf("\n Enter the value: ");
    scanf(" %d", &value);
    ptr = start;
    preptr = start->prev;
    while(ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    ptr->next->prev = preptr;
    free(ptr);

    return start;
};

struct node *delete_list(struct node *start)
{

    struct node *ptr;
    ptr = start;
    while(ptr->next != start)
    {
        start = delete_end(start);
    }
    free(start);
    return start;
};

struct node *swap_kth(struct node *start)
{
    struct node *ptr, *nxtptr;
    ptr = start;
    printf("\n Enter position: ");
    int k;
    scanf(" %d", &k);

    if(start == NULL || k <= 0)
    {
        printf("\n Invalid input or linked list is empty");
        return start;
    }

    int count = 1;
    while(ptr->next != start && count != k)
    {
        ptr = ptr->next;
        count++;
    }
    nxtptr = ptr->next;

    if(count != k || ptr->next == start)
    {
        printf("\n Invalid input");
        return start;
    }
    else
    {
        ptr->prev->next = nxtptr;
        nxtptr->next->prev = ptr;
        nxtptr->prev = ptr->prev;
        ptr->prev = nxtptr;
        ptr->next = nxtptr->next;
        nxtptr->next = ptr;
        if(k == 1)
        {
            start = nxtptr;
        }
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
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: Interchange the kth and k+1 node");
        printf("\n 10: EXIT");

        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_cdll(start);
            printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
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
            start = delete_node(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
            break;
        case 9:
            start = swap_kth(start);
            break;
        default:
            option = 10;
            break;
        }
    }
    while(option != 10);

    return 0;
}
