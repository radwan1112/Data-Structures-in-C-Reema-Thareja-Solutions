#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stk[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("\n STACK OVERFLOW\n");
    }
    else
    {
        top++;
        stk[top] = value;
    }
}

int pop()
{
    int value;
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        value = stk[top];
        top--;
        return value;
    }
}

int main()
{
    int val, n, i;
    int arr[MAX];
    printf("\n Enter the number of elements in the array : ");
    scanf(" %d", &n);
    printf("\n Enter the elements of the array\n");
    for(i = 0; i < n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf(" %d", &arr[i]);
    }
    printf("\n\n");
    for(i = 0; i < n; i++)
    {
        push(arr[i]);
    }
    printf("\n Printing the reverse array\n");
    for(i = 0; i < n; i++)
    {
        val = pop();
        arr[i] = val;
        printf("\n arr[%d] = %d", i, arr[i]);
    }

    return 0;
}
