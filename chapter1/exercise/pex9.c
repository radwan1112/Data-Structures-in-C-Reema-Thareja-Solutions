#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Item
{
    char name[20];
    int quantity;
    float price;
    float amount;
};

int main()
{

    char continue_shopping, confirm_purchase;
    struct Item item[100];
    int i = 0;
    double total = 0;

    do
    {
        printf("Do you want to continue shopping?\n");
        printf("Enter y/Y for Yes to add new items and n/N to view your bill: \n");
        scanf(" %c", &continue_shopping);
        if(continue_shopping == 'y' || continue_shopping == 'Y')
        {
            printf("Enter the item name: \n");
            scanf("%s", &item[i].name);
            printf("Enter item quantity: \n");
            scanf("%d", &item[i].quantity);
            printf("Enter the price per item: \n");
            scanf("%f", &item[i].price);
            item[i].amount = item[i].quantity * item[i].price;
            total += item[i].amount;
        }
        else
        {
            if(i == 0)
            {
                printf("You have 0 items, thank you for your visit");
            }

            else
            {
                printf("************************ B I L L ************************\n");
                printf("No.   Item         Quantity       Price       Amount\n");
                printf("_______________________________________________________\n\n");

                for(int l = 0; l < i; l++)
                {
                    printf("%d    %s           %d             %.2f        %.2lf    \n", l+1, item[l].name, item[l].quantity, item[l].price, item[l].amount);

                }
                printf("_______________________________________________________\n");
                printf("                Total Amount to be paid\n                ");
                printf("%0.2lf USD\n\n", total);
                printf("_______________________________________________________\n");

                printf("Here is your Bill, to confirm purchase type Y/y or N/n to cancel the purchase: \n");
                scanf(" %c", &confirm_purchase);
                if(confirm_purchase == 'y' || confirm_purchase == 'Y')
                {
                    printf("Thank you for buying from us, see again you later\n");
                }
                else
                {
                    printf("Goodbye!\n");
                }
            }

        }
        i++;
    }
    while(continue_shopping == 'y' || continue_shopping == 'Y');




    return 0;
}
