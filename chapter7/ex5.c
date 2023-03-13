#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;

void push(char bracket)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = bracket;

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
}

char pop()
{
    struct node *ptr;
    char bracket;

    if(top == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        ptr = top;
        top = top->next;
        bracket = ptr->data;
        free(ptr);
    }

    return bracket;
}

int match_char(char a, char b)
{
    if(a == '[' && b == ']')
    {
        return 1;
    }
    if(a == '{' && b == '}')
    {
        return 1;
    }
    if(a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int check_balanced(char *exp)
{

    int i;
    char temp;

    for(i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == NULL)
            {
                printf("\n right brackets are more than left brackets");
                return 0;
            }
            else
            {
                temp = pop();
                if(!match_char(temp, exp[i]))
                {
                    printf("\n Mismatched brackets");
                    return 0;
                }
            }
        }
    }

    if(top != NULL)
    {
        printf("\n Stack not Empty left brackets are more than right brackets");
        return 0;
    }
    else
    {
        return 1;
    }
}


int main()
{
    char exp[100];
    int option;
    int balanced;

    do
    {
        printf("\n ****MENU*****");
        printf("\n 1. Input A new Expression");
        printf("\n 2. Print Expression");
        printf("\n 3. Validate the Expression");
        printf("\n 4. EXIT\n");

        printf("\n Enter option: ");
        scanf(" %d", &option);
        getchar();

        switch(option)
        {
        case 1:
            printf("\n Enter Expression: ");
            gets(exp);
            break;
        case 2:
            printf("\n The expression you entered is: %s\n", exp);
            break;
        case 3:
            balanced = check_balanced(exp);
            if(balanced)
            {
                printf("\n Expression is valid\n");
            }
            else
            {
                printf("\n Hence, Expression is invalid\n");
            }
            break;
        default:
            option = 4;
            break;
        }
    }
    while(option != 4);
}
