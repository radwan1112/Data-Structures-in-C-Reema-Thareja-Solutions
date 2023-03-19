#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[100];
    struct node *next;
};
struct node *top = NULL;

struct node *push(struct node *top, char *n)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->name, n);
    ptr = top;
    if(top == NULL)
    {
        new_node->next = NULL;
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
    return top;
};

void display(struct node *top)
{
    struct node *ptr;
    ptr = top;
    int i = 1;
    while(ptr != NULL)
    {
        printf("\n %d. %s", i, ptr->name);
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    int option;
    char name[100];

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Add a new student to stack");
        printf("\n 2. Display Stack");
        printf("\n 3. EXIT\n");

        printf("\n Enter Option: ");
        scanf(" %d", &option);
        getchar();

        switch(option)
        {
        case 1:
            printf("\n Enter student name: ");
            gets(name);
            top = push(top, name);
            break;
        case 2:
            printf("\n Students Names List \n");
            display(top);
            break;
        default:
            option = 3;
            break;
        }
    }
    while(option != 3);

    return 0;
}
