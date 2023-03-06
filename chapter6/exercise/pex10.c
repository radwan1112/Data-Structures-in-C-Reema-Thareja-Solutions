#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_hll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end\n");
    printf("\n Enter data: ");
    scanf(" %d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if(start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->next = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("\n Enter data: ");
        scanf(" %d", &num);
    }
    return start;
};


struct node *display(struct node *start)
{
    struct node *ptr;

    if(start->next == NULL)
    {
        printf("\ HEADER LINKED LIST IS EMPTY");
        return start;
    }

    ptr = start->next;
    printf("\n {");
    while(ptr->next != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d}", ptr->data);
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

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    return start;
};

struct node *delete_mid(struct node *start)
{
    struct node *ptr, *preptr;
    int i = 0;
    ptr = start->next;
    while(ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }
    int middle = i / 2;
    i = 0;
    ptr = start->next;
    while(ptr != NULL)
    {
        if(i == middle || middle == 0)
        {
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }
    preptr->next = ptr->next;
    free(ptr);

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
        printf("\n 3: Delete the first node");
        printf("\n 4: Delete the last node");
        printf("\n 5: Delete the middle node");
        printf("\n 6: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_hll(start);
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
            start = delete_mid(start);
            break;
        default:
            option = 6;
            break;
        }
    }
    while(option != 6);

    return 0;
}
