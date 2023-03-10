#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Size of the stack

int st[MAX], top = -1;

int main()
{
    int val, option;

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");

        printf("\n\n Enter your option: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf(" %d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if(val != -1)
            {
                printf("\n The value deleted from stack is: %d \n", val);
            }
            break;
        case 3:
            val = peek(st);
            if(val != -1)
            {
                printf("\n The value stored at top of stack is: %d \n", val);
            }
        case 4:
            display(st);
            break;
        default:
            option = 5;
            break;
        }
    }
    while(option != 5);

    return 0;
}

void push(int *st, int val)
{
    if(top == MAX-1)
    {
        printf("\n STACK OVERFLOW \n");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int pop(int *st)
{
    int val;
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW \n");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

int peek(int *st)
{
    if(top == -1)
    {
        printf("\n STACK IS EMPTY\n");
        return -1;
    }
    else
    {
        return st[top];
    }
}

void display(int *st)
{
    if(top == -1)
    {
        printf("\n EMPTY STACK \n");
    }
    else
    {
        int i;
        printf("\n {");
        for(i = top; i >= 0; i--)
        {
            if(i == 0)
            {
                printf("%d}", st[i]);

            }
            else
            {
                printf("%d, ", st[i]);
            }
        }
    }
}
