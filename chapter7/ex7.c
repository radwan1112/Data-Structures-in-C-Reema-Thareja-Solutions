// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

char infix[MAX];
char postfix[MAX];

struct node
{
    char data;
    struct node *next;
};

struct node *head = NULL;

char pop()
{
    char val = -1;
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        val = stack[top--];
    }
    return val;
}

void push(char symbol)
{
    if(top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top++;
        stack[top] = symbol;
    }
}

// Function to return precedence of operators
int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// Function to check if the scanned character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Main function to convert infix expression to postfix expression
void infixToPostfix()
{
    int i, j;
    int len = strlen(infix);

    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
        {
            continue;
        }

        // If the scanned character is operand add it to the postfix expression
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        // if the scanned character is '(' push it in the stack
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }

        // if the scanned character is ')'pop the stack
        // and add it to the output string until empty or '(' found
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                pop();
        }

        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(infix[i]))
        {
            while (top > -1&& precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop all remaining elements from the stack
    while (top > -1)
    {
        if (stack[top] == '(')
        {
            return "Invalid Expression";
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void pushls(char bracket)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = bracket;

    if(head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

char popls()
{
    struct node *ptr;
    char bracket;

    if(head == NULL)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        ptr = head;
        head = head->next;
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
            pushls(exp[i]);
        }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(head == NULL)
            {
                printf("\n right brackets are more than left brackets");
                return 0;
            }
            else
            {
                temp = popls();
                if(!match_char(temp, exp[i]))
                {
                    printf("\n Mismatched brackets");
                    return 0;
                }
            }
        }
    }

    if(head != NULL)
    {
        printf("\n Stack not Empty left brackets are more than right brackets");
        return 0;
    }
    else
    {
        return 1;
    }
}

// Driver code
int main()
{
    int option;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Convert Infix to Postfix");
        printf("\n 2. Evaluate an Infix expression");
        printf("\n 3. Evaluate a postfix expression");
        printf("\n 4. EXIT\n");

        printf("\n Enter Option: ");
        scanf(" %d", &option);
        getchar();

        switch(option)
        {
        case 1:
            printf("\n Enter the infix expression: ");
            gets(infix);
            if(check_balanced(infix))
            {
                infixToPostfix(infix);
                printf("\n The postfix expression is: %s\n", postfix);
            }
            else
            {
                printf("\n Hence, Expression is invalid\n");
            }
            break;
        case 2:
            printf("\n Enter the infix expression: ");
        default:
            option = 2;
            break;
        }
    }
    while(option != 2);

    return 0;
}
