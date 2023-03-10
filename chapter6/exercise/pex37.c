#include <stdio.h>
#include <stdlib.h>

struct node
{
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

int main()
{

    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a Circular header linked list");
        printf("\n 2: Display the list");
        printf("\n 3: EXIT");
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
        default:
            option = 3;
            break;
        }
    }
    while(option != 3);

    return 0;
}
