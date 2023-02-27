#include <stdio.h>


struct fullname
{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
};

struct address
{
    char area[50];
    char city[50];
    char state[50];
};

struct employee
{
    int emp_id;
    struct fullname name;
    struct address add;
    int age;
    int salary;
    char designation[100];
} employe[10];

void rand_firstname(char *name)
{
    char firstnames[100][100] =
    {
        "John",       // Western
        "Mary",       // Western
        "William",    // Western
        "Elizabeth",  // Western
        "James",      // Western
        "Margaret",   // Western
        "George",     // Western
        "Catherine",  // Western
        "Charles",    // Western
        "Anne",       // Western
        "Liu",        // Asian
        "Chen",       // Asian
        "Zhang",      // Asian
        "Wang",       // Asian
        "Li",         // Asian
        "Tan",        // Asian
        "Satoshi",    // Japanese
        "Hiroshi",    // Japanese
        "Yui",        // Japanese
        "Haruka",     // Japanese
        "Akihiko",    // Japanese
        "Arun",       // Indian
        "Ravi",       // Indian
        "Sonia",      // Indian
        "Deepak",     // Indian
        "Shilpa",     // Indian
        "Mehmet",     // Turkish
        "Aylin",      // Turkish
        "Emre",       // Turkish
        "Yasin",      // Turkish
        "Fatma",      // Turkish
        "Ahmed",      // Arabic
        "Mohammed",   // Arabic
        "Ali",        // Arabic
        "Hassan",     // Arabic
        "Nadia",      // Arabic
        "Juan",       // Spanish
        "Maria",      // Spanish
        "Carlos",     // Spanish
        "Carmen",     // Spanish
        "Luis",       // Spanish
        "Alexei",     // Russian
        "Olga",       // Russian
        "Sergei",     // Russian
        "Ivan",       // Russian
        "Natalia",    // Russian
        "Yulia",      // Russian
        "Piotr",      // Polish
        "Anna",       // Polish
        "Krzysztof",  // Polish
        "Tomasz",     // Polish
        "Marta",      // Polish
        "Andrzej",    // Polish
        "Giovanni",   // Italian
        "Lorenzo",    // Italian
        "Marco",      // Italian
        "Francesca",  // Italian
        "Valentina",  // Italian
        "Filippo",    // Italian
        "Javier",     // Mexican
        "Sofia",      // Mexican
        "Jose",       // Mexican
        "Camila",     // Mexican
        "Luisa",      // Mexican
        "Diego",      // Mexican
        "Hector",     // Mexican
        "Cesar",      // Mexican
        "Pedro",      // Mexican
        "Manuel",     // Mexican
        "Jasmine",    // African
        "Mohammed",   // African
        "Fatima",     // African
        "Chiamaka",   // African
        "Kwame",      // African
        "Amaka",      // African
        "Aisha",      // African
        "Isaac",      // African
        "Yasmin",     // African
        "Radwan"    // African
    };

    strcpy(name, firstnames[rand_num(0, 99)]);
}

void rand_middlename(char *name)
{
    char middlenames[100][100] =
    {
        "Lee",
        "Maria",
        "Rose",
        "Raj",
        "Singh",
        "Muhammad",
        "Wei",
        "Fatima",
        "Abdul",
        "David",
        "Chen",
        "Kim",
        "Garcia",
        "Lopez",
        "Martinez",
        "Gonzalez",
        "Rodriguez",
        "Hernandez",
        "Gomez",
        "Abdullah",
        "Brown",
        "Davis",
        "Wilson",
        "Anderson",
        "Thomas",
        "Jackson",
        "Baker",
        "Carter",
        "Green",
        "Clark",
        "Lewis",
        "Hall",
        "Johnson",
        "Jones",
        "Taylor",
        "Williams",
        "Smith",
        "Martin",
        "Moore",
        "Allen",
        "Walker",
        "White",
        "Young",
        "Turner",
        "Wright",
        "King",
        "Scott",
        "Bennett",
        "Cooper",
        "Reed",
        "Bailey",
        "Gray",
        "Murray",
        "Morgan",
        "Simpson",
        "Stewart",
        "Wood",
        "Ward",
        "Foster",
        "Coleman",
        "Hunt",
        "Harrison",
        "Khan",
        "Patel",
        "Choudhary",
        "Kaur",
        "Singh",
        "Wong",
        "Chung",
        "Lam",
        "Cheung",
        "Li",
        "Lin",
        "Kim",
        "Choi",
        "Park",
        "Lee",
        "Nguyen",
        "Tran",
        "Pham",
        "Duong",
        "Ng",
        "Ngai",
        "Cheng",
        "Wu",
        "Chen",
        "Zhao",
        "Xu",
        "Wang",
        "Zhang",
        "Liu",
        "Yang",
        "Feng",
        "Huang",
        "Chen",
        "Zhou",
        "Shen",
        "Qian",
        "Wu",
        "Tang",
        "Xie",
        "Yu",
        "Jiang",
        "Zhu",
        "He",
        "Ma",
        "Li",
        "Guo",
        "Li",
        "Chang",
        "Chu",
        "Hsu",
        "Lin",
        "Chen",
        "Wu",
        "Wang",
        "Kuo",
        "Yeh",
        "Tsai",
        "Chen",
        "Lai",
        "Huang",
        "Lin",
        "Kuo",
        "Chou",
        "Wang",
        "Hsu",
        "Chang",
        "Li",
        "Chen",
        "Liu",
        "Chen",
        "Yang",
        "Liu",
        "Chen",
        "Wang"
    };
    strcpy(name, middlenames[rand_num(0, 99)]);
}

void rand_lastname(char *name)
{
    char lastnames[100][100] =
    {
        "Smith",
        "Johnson",
        "Williams",
        "Jones",
        "Brown",
        "Garcia",
        "Miller",
        "Davis",
        "Rodriguez",
        "Martinez",
        "Hernandez",
        "Lopez",
        "Gonzalez",
        "AlShawesh",
        "Gomez",
        "Martin",
        "Moore",
        "Jackson",
        "Lee",
        "Taylor",
        "Anderson",
        "Thomas",
        "Wilson",
        "Baker",
        "Carter",
        "Green",
        "Clark",
        "Lewis",
        "Hall",
        "Walker",
        "White",
        "Young",
        "Turner",
        "Wright",
        "King",
        "Scott",
        "Allen",
        "Bailey",
        "Cooper",
        "Reed",
        "Gray",
        "Murray",
        "Morgan",
        "Simpson",
        "Stewart",
        "Wood",
        "Ward",
        "Foster",
        "Coleman",
        "Hunt",
        "Harrison",
        "Khan",
        "Patel",
        "Choudhary",
        "Kaur",
        "Singh",
        "Wong",
        "Chung",
        "Lam",
        "Cheung",
        "Li",
        "Lin",
        "Kim",
        "Choi",
        "Park",
        "Nguyen",
        "Tran",
        "Pham",
        "Duong",
        "Ng",
        "Ngai",
        "Cheng",
        "Wu",
        "Chen",
        "Zhao",
        "Xu",
        "Wang",
        "Zhang",
        "Liu",
        "Yang",
        "Feng",
        "Huang",
        "Zhou",
        "Shen",
        "Qian",
        "Tang",
        "Xie",
        "Yu",
        "Jiang",
        "Zhu",
        "He",
        "Ma",
        "Guo",
        "Chang",
        "Chu",
        "Hsu",
        "Lai",
        "Chou",
        "Kuo",
        "Yeh",
        "Tsai",
        "Wu"
    };

    strcpy(name, lastnames[rand_num(0, 99)]);

}


int rand_num(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        printf(" \nEmployee %d\n\n", i+1);
        employe[i].emp_id = rand_num(10000000, 99999999);
        rand_firstname(employe[i].name.first_name);
        rand_firstname(employe[i].name.middle_name);
        rand_firstname(employe[i].name.last_name);
        printf(" Address \n");
        printf("Area: ");
        scanf(" %s", employe[i].add.area);
        printf("City: ");
        scanf(" %s", employe[i].add.city);
        printf("State: ");
        scanf(" %s", employe[i].add.state);
        employe[i].age = rand_num(20, 80);
        employe[i].salary = rand_num(10000, 100000);
        printf("Designation: ");
        scanf(" %s", employe[i].designation);
    }

    printf("\n\n-- Employees Record Summary -- \n\n");
    printf("No. | ID Number | Name                    | Address           | Age | Salary | Designation");
    // Printing data
    for(int i = 0; i < 10; i++)
    {
        printf("\n%2d", i+1);
        printf("%8d", employe[i].emp_id);
        printf("%8s %8s %8s", employe[i].name.first_name, employe[i].name.middle_name, employe[i].name.last_name);
        printf("%8s %8s %8s", employe[i].add.area, employe[i].add.city, employe[i].add.state);
        printf("%2d", employe[i].age);
        printf("%6d", employe[i].salary);
        printf("%8s", employe[i].designation);
    }


    return 0;
}
