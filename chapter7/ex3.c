#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA(int val)
{
    if(topA == topB - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        topA++;
        stack[topA] = val;
    }
}

void pushB(int val)
{
    if(topB - 1 == topA)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        topB--;
        stack[topB] = val;
    }
}

int popA()
{
    int val;
    if(topA == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = stack[topA];
        topA--;
    }
    return val;
}

int popB()
{
    int val;
    if(topB == MAX)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = stack[topB];
        topB++;
    }
    return val;
}

void displayA()
{
    printf("\n *****Top A*****");
    for(int i = topA; i >= 0; i--)
    {
        printf("\n %3d", stack[i]);
    }
}

void displayB()
{
    printf("\n *****Top B*****");
    for(int i = topB; i < MAX; i++)
    {
        printf("\n %3d", stack[i]);
    }
}


int main()
{
    int option, val;

    do
    {
        printf("\n *****MENU*****");
        printf("\n 1. PUSH IN STACK A");
        printf("\n 2. PUSH IN STACK B");
        printf("\n 3. POP FROM STACK A");
        printf("\n 4. POP FROM STACK B");
        printf("\n 5. DISPLAY STACK A");
        printf("\n 6. DISPLAY STACK B");
        printf("\n 7. EXIT\n");
        printf("\n Enter your choice: ");
        scanf(" %d", &option);

        switch(option)
        {
        case 1:
            printf("\n Enter number: ");
            scanf(" %d", &val);
            pushA(val);
            printf("\n New element added in stack A\n");
            break;
        case 2:
            printf("\n Enter number: ");
            scanf(" %d", &val);
            pushB(val);
            printf("\n New element added in stack B\n");
            break;
        case 3:
            val = popA();
            if(val != -1)
            {
                printf("\n The value popped from stack A = %d\n", val);
            }
            break;
        case 4:
            val = popB();
            if(val != -1)
            {
                printf("\n The value popped from stack B = %d\n", val);
            }
            break;
        case 5:
            displayA();
            break;
        case 6:
            displayB();
            break;
        default:
            option = 7;
            break;
        }
    }
    while(option != 7);
    return 0;
}
