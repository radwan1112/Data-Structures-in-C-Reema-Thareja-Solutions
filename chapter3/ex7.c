#include <stdio.h>
#include <stdbool.h>

void show_array(int arr[], int n)
{
    printf("\nFinal Result: \n");

    for(int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int insert(int *data[], int insert_n, int pos, int n)
{

    for(int i = n; i >= pos ; i--)
    {
        data[i+1] = data[i];
    }
    data[pos] = insert_n;
}

bool check_response(char answer)
{

    if(answer == 'Y' || answer == 'y')
    {
        return true;
    }
    else if(answer == 'N' || answer == 'n')
    {
        return false;
    }
    else
    {
        return false;
    }
}

int main()
{

    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int arr[100];

    // Fill the array
    for(int i = 0; i < n; i++)
    {
        printf("Enter number at pos[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    show_array(arr, n);

    int insert_num, pos;
    char response;


    printf("Do You wish to insert new elements to the array? \nType 'Y' or 'y' for yes or 'N' or 'n' for no: ");
    scanf(" %c", &response);

    do
    {
        printf("Enter the number you wish to insert: ");
        scanf(" %d", &insert_num);
        printf("Enter the position you which to insert the number in: ");
        scanf(" %d", &pos);
        n++;
        insert(&arr, insert_num, pos, n);
        show_array(arr, n);

        printf("Do You wish to insert new elements to the array? \nType 'Y' or 'y' for yes or 'N' or 'n' for no: ");
        scanf(" %c", &response);
    }
    while(check_response(response));


    return 0;
}
