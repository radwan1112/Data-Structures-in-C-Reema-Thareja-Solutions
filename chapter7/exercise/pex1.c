#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *push(struct node *top, int value)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
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
}

struct node *pop(struct node *top)
{
    struct node *ptr;
    ptr = top;
    if(top == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        top = top->next;
        free(ptr);
    }
    return top;
}

int peek(struct node *top)
{
    if(top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

void display(struct node *top)
{
    struct node *ptr;
    ptr = top;

    printf("\n");
    while(ptr->next != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

int main()
{
    int option;
    int val;

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");

        printf("\n 5. EXIT\n");

        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            val = peek(top);
            top = pop(top);
            printf("\n The value popped from the stack is: %d", val);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
                printf("\n The value at the top of stack is: %d", val);
            else
                printf("\n STACK IS EMPTY");
            break;
        case 4:
            display(top);
            break;
        default:
            option = 5;
            break;
        }
    }
    while(option != 5);
    return 0;
}
