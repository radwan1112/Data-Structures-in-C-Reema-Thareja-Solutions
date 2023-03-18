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

char *infix2prefix(char *infix)
{
    int len = strlen(infix);
    char *prefix = (char *)malloc(sizeof(char) * (len + 2));
    char *rev_infix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX];
    int top = -1;

    int i, j;
    for(i = len - 1, j = 0; i < len; i--, j++)
    {
        if(infix[i] == '(')
        {
            temp[j] = ')';
        }
        else if(infix[i] == ')')
        {
            temp[j] = '(';
        }
        else
        {
            temp[j] = infix[i];
        }
    }
    temp[j] = '\0';

    j = 0;
    for(i = 0; i < len; i++)
    {
        if(temp[i] == ' ')
        {
            continue;
        }
        switch(temp[i])
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
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while((top > -1) && (precedence(stack[top]) >= precedence(temp[i])))
            {
                prefix[j++] = stack[top--];
            }
            stack[++top] = temp[i];
            break;
        default:
            prefix[j++] = temp[i];
            break;
        }
    }

    while(top != -1)
    {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';

    //reverse second time
    len = strlen(prefix);
    for(i = len - 1, j = 0; i < len; i--, j++)
    {
        if(prefix[i] == '(')
        {
            temp[j] = ')';
        }
        else if(infix[i] == ')')
        {
            temp[j] = '(';
        }
        else
        {
            temp[j] = infix[i];
        }
    }
    temp[j] = '\0';

    return temp;
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
