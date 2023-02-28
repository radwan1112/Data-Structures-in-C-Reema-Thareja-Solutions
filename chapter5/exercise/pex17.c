#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int num_of_hotels = 10;

struct hotels
{
    char name[100];
    char address[100];
    int grade;
    int rooms;
    int charges;
};

void rand_hotel_name(char *name, struct  hotels *ptr_hotel)
{
    char hotels[10][50] = {"Marriott", "Hilton", "Holiday Inn", "Hyatt", "Sheraton", "Ritz-Carlton", "Four Seasons", "Westin", "InterContinental", "Mandarin Oriental"};
    int i = 0;

    strcpy(name, hotels[rand_num(0, 9)]);

}

void rand_hotel_address(char *address, struct hotels *ptr_hotel)
{
    char addresses[10][100] =
    {
        "123 Main St, Anytown, USA",
        "456 Park Ave, Somewhereville, USA",
        "789 Broadway, Big City, USA",
        "1010 Ocean Blvd, Seaside, USA",
        "1111 Mountain Rd, Mountainville, USA",
        "1212 Lakeshore Dr, Lakeview, USA",
        "1313 River Rd, Riverdale, USA",
        "1414 Forest Ave, Forestville, USA",
        "1515 Hilltop Rd, Hillside, USA",
        "1616 Valley View Blvd, Valleyview, USA"
    };
    strcpy(address, addresses[rand_num(0, 9)]);
}

int rand_num(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void display_record(struct hotels *ptr_hotel)
{
    for(int i = 0; i < num_of_hotels; i++)
    {
        printf("%2d | %17s | %40s | %5d | %5d | %4d \n", i + 1, ptr_hotel[i].name, ptr_hotel[i].address, ptr_hotel[i].grade, ptr_hotel[i].rooms, ptr_hotel[i].charges);
    }
}

void sort_grade(struct hotels *ptr_hotel)
{
    int i, j;
    struct hotels temp;

    for(i = 0; i < num_of_hotels; i++)
    {
        for(j = 0; j < num_of_hotels; j++)
        {
            if(i == j)
            {
                continue;
            }
            else
            {
                if(ptr_hotel[i].grade > ptr_hotel[j].grade)
                {
                    temp = ptr_hotel[i];
                    ptr_hotel[i] = ptr_hotel[j];
                    ptr_hotel[j] = temp;
                }
            }
        }
    }
    display_record(ptr_hotel);
}

void filter_price(struct hotels *ptr_hotel)
{
    int i, j;
    struct hotels temp;

    for(i = 0; i < num_of_hotels; i++)
    {
        for(j = 0; j < num_of_hotels; j++)
        {
            if(i == j)
            {
                continue;
            }
            else
            {
                if(ptr_hotel[i].charges < ptr_hotel[j].charges)
                {
                    temp = ptr_hotel[i];
                    ptr_hotel[i] = ptr_hotel[j];
                    ptr_hotel[j] = temp;
                }
            }
        }
    }
    display_record(ptr_hotel);

}


int main()
{
    srand(time(NULL));
    struct hotels hotel[num_of_hotels];
    struct hotels *ptr_hotel;

    ptr_hotel = &hotel;

    printf(" *** Hotel in the USA *** \n\n");
    printf("No.| Name              |            Address                       | Stars | Rooms | Cost \n");
    for(int i = 0; i < num_of_hotels; i++)
    {
        rand_hotel_name(hotel[i].name, hotel);
        rand_hotel_address(hotel[i].address, hotel);
        hotel[i].grade = rand_num(1, 5);
        hotel[i].rooms = rand_num(100, 1000);
        hotel[i].charges = rand_num(100, 5000);
    }
    display_record(hotel);

    printf("-- Menu -- \n\n");
    printf("1. Sort hotels from highest to lowest grade\n");
    printf("2. Filter hotels based on their price\n");
    printf("3. Exit\n");

    int option;
    do
    {
        printf(" \nChoose from menu: ");
        scanf(" %d", &option);
        switch(option)
        {
        case 1:
            sort_grade(hotel);
            break;
        case 2:
            filter_price(hotel);
            break;
        case 3:
            printf("\nSee you again next time \n");
            option = 3;
            break;
        default:
            option = 0;
            printf("Invalid input\n");
        }
    }
    while(option != 3);



    return 0;
}
