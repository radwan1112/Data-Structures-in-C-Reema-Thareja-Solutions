// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

float stack2[MAX];
int top2 = -1;

char infix[MAX];
char postfix[MAX];
char prefix[MAX];
char temp[MAX];

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

float pop2()
{
    float val = -1;
    if(top2 == -1)
    {
        printf("\n STACK UNDERFLOW");
    }
    else
    {
        val = stack2[top2--];
    }
    return val;
}

void push2(float symbol)
{
    if(top2 == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top2++;
        stack2[top2] = symbol;
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
void infixToPostfix(char *source, char *target)
{
    int i, j;
    int len = strlen(source);

    printf("\n Infix Char Scanned | Stack               | Postfix Expression");
    for (i = 0, j = 0; i < len; i++)
    {
        if (source[i] == ' ' || source[i] == '\t')
        {
            continue;
        }

        // If the scanned character is operand add it to the postfix expression
        if (isalnum(source[i]))
        {
            target[j++] = source[i];
        }

        // if the scanned character is '(' push it in the stack
        else if (source[i] == '(')
        {
            push(source[i]);
        }

        // if the scanned character is ')'pop the stack
        // and add it to the output string until empty or '(' found
        else if (source[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                target[j++] = pop();
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                pop();
        }

        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(source[i]))
        {
            while (top > -1&& precedence(stack[top]) >= precedence(source[i]))
            {
                target[j++] = pop();
            }
            push(source[i]);
        }
        else
        {
            printf("\n Error");
            return;
        }
        printf("\n\t%c\t    |", source[i]);
        int k = 0;
        for(k = top; k >-1; k--)
        {
            printf("%c ", stack[k]);
        }
        printf("\t\t\t  | %s", target);
    }
    // Pop all remaining elements from the stack
    while (top > -1)
    {
        if (stack[top] == '(')
        {
            return "Invalid Expression";
        }
        printf("\n\t%c\t    |", source[i]);
        int k = 0;
        for(k = top; k >-1; k--)
        {
            printf("%c ", stack[k]);
        }
        printf("\t\t\t  | %s", target);
        target[j++] = pop();
    }
    target[j] = '\0';
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

float eval_post()
{
    int len = strlen(postfix);
    char symbol;
    float total, a, b;

    printf("\n Character Scanned | Stack");
    int i, j;
    for(i = 0; i < len; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            push2((float)(symbol - '0'));
        }
        else if(isOperator(symbol))
        {
            total = 0;
            a = pop2();
            b = pop2();

            switch(symbol)
            {
            case '+':
                total = b + a;
                break;
            case '-':
                total = b - a;
                break;
            case '*':
                total = b * a;
                break;
            case '/':
                total = b / a;
                break;
            case '%':
                total = (int)b % (int)a;
                break;
            case '^':
                total = pow(b, a);
                break;
            default:
                printf("\n Invalid Operator!");
                break;
            }
            push2(total);
        }
        printf("\n\t%c\t     ", symbol);
        for(j = top2; j > -1; j--)
        {
            printf("%.2f, ", stack2[j]);
        }
    }
    return pop2();
}

void reverse_string(char *str)
{
    int i, j;
    int len = strlen(str);

    for(i = 0, j = len - 1; i < len; i++, j--)
    {
        if(str[j] == '(')
        {
            temp[i] = ')';
        }
        else if(str[j] == ')')
        {
            temp[i] = '(';
        }
        else
        {
            temp[i] = str[j];
        }
    }
    temp[i] = '\0';
}

// Driver code
int main()
{
    int option;
    float result;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. Convert Infix to Postfix");
        printf("\n 2. Convert Infix to Prefix");
        printf("\n 3. Evaluate an Infix expression");
        printf("\n 4. Evaluate a postfix expression");
        printf("\n 5. EXIT\n");

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
                infixToPostfix(infix, postfix);
                printf("\n The postfix expression is: %s\n", postfix);
            }
            else
            {
                printf("\n Hence, Expression is invalid\n");
            }
            break;
        case 2:
            printf("\n Enter the infix expression: ");
            gets(infix);
            if(check_balanced(infix))
            {
                reverse_string(infix);
                printf("\n Step 1: Reverse String %s -> %s\n", infix, temp);
                infixToPostfix(temp, prefix);
                printf("\n Step 2: Obtain Postfix exp of string: %s", prefix);
                reverse_string(prefix);
                printf("\n Step 3: Reverse postfix to get prefix: %s -> %s", prefix, temp);
            }
            else
            {
                printf("\n Hence, Expression is invalid\n");
            }
            break;
        case 3:
            printf("\n Enter the infix expression: ");
            gets(infix);
            if(check_balanced(infix))
            {
                infixToPostfix(infix, postfix);
                result = eval_post();
                printf("\n\n Summary: ");
                printf("\n\n Infix\n\t %s = %.2f", infix, result);
                printf("\n Postfix\n\t %s = %.2f\n", postfix, result);
            }
            else
            {
                printf("\n Hence, Expression is invalid\n");
            }
            break;
        case 4:
            printf("\n Enter the postfix expression: ");
            gets(postfix);
            result = eval_post();
            printf("\n Postfix\n\t %s = %.2f\n", postfix, result);
        default:
            option = 5;
            break;
        }
    }
    while(option != 5);

    return 0;
}
