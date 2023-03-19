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

char *infix2postfix(char *infix)
{
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX];
    int top = -1;

    int i, j;
    for(i = 0, j = 0; i < len; i++)
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
                postfix[j++] = stack[top--];
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
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
            break;
        default:
            postfix[j++] = infix[i];
            break;
        }
    }

    while(top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    return postfix;
}


int main()
{
    char infix[MAX];
    char *postfix;
    printf("\n *****Infix to postfix converter*****\n");
    printf("\n Enter the infix expression: ");
    gets(infix);
    postfix = infix2postfix(infix);
    printf("\n Converting infix to postfix expression \n");
    printf("\n   %s  <->  %s\n", infix, postfix);
    free(postfix);
}
