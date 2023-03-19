#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int precedence(char c)
{
    switch(c)
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

void reverse_string(char *str)
{
    int stack[MAX];
    int top = -1;
    int i = 0;
    while(str[i] != '\0')
    {
        stack[++top] = str[i];
        i++;
    }
    i = 0;
    while(top > -1)
    {
        if(stack[top] == '(')
        {
            str[i] = ')';
            top--;
        }
        else if(stack[top] == ')')
        {
            str[i] = '(';
            top--;
        }
        else
        {
            str[i] = stack[top--];
        }
        i++;
    }
    str[i] = '\0';
}

char *infix2prefix(char *infix)
{
    int len = strlen(infix);
    char *prefix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX];
    int top = -1;
    int i, j;
    reverse_string(infix);
    printf(" \n Reversed infix string: %s", infix);

    j = 0;
    for(i = 0; i < len; i++)
    {
        if(infix[i] == ' ')
        {
            continue;
        }
        switch(infix[i])
        {
        case '(':
            stack[++top] = '(';
            break;
        case ')':
            while(stack[top] != '(')
            {
                prefix[j++] = stack[top--];
            }
            top--;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while((top > -1) && (precedence(stack[top]) >= precedence(infix[i])))
            {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
            break;
        default:
            prefix[j++] = infix[i];
            break;
        }
    }

    while(top != -1)
    {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';
    printf("\n postfix string %s", prefix);
    reverse_string(prefix);

    printf("\n prefix string: %s", prefix);

    return prefix;
}


int main()
{
    char infix[MAX];
    char *prefix;
    printf("\n *****Infix to prefix converter*****\n");
    printf("\n Enter the infix expression: ");
    gets(infix);
    prefix = infix2prefix(infix);
    printf("\n Converting infix to prefix expression \n");
    printf("\n   %s  <->  %s", infix, prefix);
    free(prefix);
}
