#include <stdio.h>

int main(){

    char country[20], city[20], area[20], street[40];

    printf("Enter your Address: \n");
    printf("Country:\n");
    gets(country);
    printf("City:\n");
    gets(city);
    printf("Area:\n");
    gets(area);
    printf("Street:\n");
    gets(street);

    printf("%s, %s\n%s area %s street", country, city, area, street);

    return 0;

}
