#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int num_of_studs = 1000;

struct fullname
{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
    double jaro_dist;
};

struct dob
{

    int day;
    int month;
    int year;
};

struct marks
{
    int num_mark[3];
    char char_grade[3];
};

struct student
{
    int roll_no;
    struct fullname name;
    char sex;
    struct dob birthday;
    struct marks grade;
    char overall_grade;
    float average_grade;
    int id;
};

long int rand_num(long int min, long int max)
{
    return (rand() % (max - min + 1)) + min;
}

int is_leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int check_month(int month)
{

    int month_31_days[] = {1, 3, 5, 7, 8, 10, 12};
    int i;
    for(i = 0; i < 7; i++)
    {
        if(month == month_31_days[i])
        {
            return 1;
        }
    }

    return 0;

}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

double jaro_distance(char *s1, char *s2)
{

    // If the strings are equal
    if(strcasecmp(s1, s2) == 0)
    {
        return 1.0;
    }

    // Length of two strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if(len1 == 0 || len2 == 0)
    {
        return 0;
    }

    //Max distance upto which matching is allowed
    int max_dist = (int)(floor(fmax(len1, len2) / 2.0) - 1);

    //Count of matches
    int match = 0;

    // Hash for matches
    int hash_s1[strlen(s1)];
    int hash_s2[strlen(s2)];
    memset(hash_s1, 0, sizeof(hash_s1));
    memset(hash_s2, 0, sizeof(hash_s2));

    // Traverse through the first string
    for(int i = 0; i < len1; i++)
    {

        //Check if there is any matches
        for(int j = max(0, i - max_dist); j < min(len2, i + max_dist + 1); j++)
        {
            if(s1[i] == s2[j] && hash_s2[j] == 0)
            {
                hash_s1[i] = 1;
                hash_s2[j] = 1;
                match++;
                break;
            }
        }
    }

    //If there is no match
    if(match == 0)
    {
        return 0.0;
    }

    //Number of transpositions
    double t = 0;
    int point = 0;

    // Count number of occurrences
    // where two characters match but
    // There is a third matched character
    // in between the indices

    for(int i = 0; i < len1; i++)
    {
        if(hash_s1[i])
        {
            // Find the next matched character in second string
            while(hash_s2[point] == 0)
            {
                point++;
            }
            if(s1[i] != s2[point++])
            {
                t++;
            }
        }
    }

    t /= 2;

    // Return the Jaro Similarity
    return (((double)match) / ((double)len1) + ((double)match) / ((double)len2) + ((double)match - t) / ((double)match)) / 3.0;

}

double jaro_Winkler(char *s1, char *s2)
{
    double jaro_dist = jaro_distance(s1, s2);

    // If the Jaro similarity is above a threshold
    if(jaro_dist > 0.7)
    {
        // Find the length of common prefix
        int prefix = 0;

        for(int i = 0; i < min(strlen(s1), strlen(s2)); i++)
        {
            // If the character match
            if(s1[i] == s2[i])
            {
                prefix++;
            }
            // Else break
            else
            {
                break;
            }

        }

        // Max of 4 characters are allowed in prefix
        prefix = min(4, prefix);

        // Calculate jaro winkler similarity
        jaro_dist += 0.1 * prefix * (1 - jaro_dist);

    }
    return jaro_dist;
}


void search_by_name(struct student *ptr_stud)
{

    char entr_name[300];
    printf("\n Enter the student name: ");
    fgets(entr_name, sizeof(entr_name), stdin);
    entr_name[strcspn(entr_name, "\n")] = '\0';
    char name[300];

    int i;
    for(i = 0; i < num_of_studs; i++)
    {
        strcpy(name, ptr_stud[i].name.first_name);
        strcat(name, ptr_stud[i].name.middle_name);
        strcat(name, ptr_stud[i].name.last_name);
        ptr_stud[i].name.jaro_dist = jaro_Winkler(name, entr_name);
    }

    printf("\nList of Similar Results: \n\n");
    printf("  No. | Student No. | FirstName - MiddleName - LastName| Birthdate | Average\n\n");

    int j = 0;
    int num = 0;
    int num_items = 10;
    int keys[num_items];
    for(double i = 1.0; i > 0.0; i -= 0.1)
    {
        for(j = 0; j < num_of_studs; j++)
        {
            if(ptr_stud[j].name.jaro_dist >= i)
            {
                printf("%4d. | %11d | %10s %10s %10s | %2d/%2d/%4d | %3.2f (%c)\n", num + 1, ptr_stud[j].roll_no, ptr_stud[j].name.first_name, ptr_stud[j].name.middle_name, ptr_stud[j].name.last_name, ptr_stud[j].birthday.day, ptr_stud[j].birthday.month, ptr_stud[j].birthday.year, ptr_stud[j].average_grade, ptr_stud[j].overall_grade);
                keys[num] = ptr_stud[j].id;
                num++;
            }
            if(num == num_items)
            {
                break;
            }
        }
        if(num == num_items)
        {
            break;
        }
    }

    if(num == 0)
    {
        printf("\n No Matches Found \n");
    }
    else
    {
        int option;
        bool invalid;
        do
        {
            printf("\nSelect the student to view his/her record: ");
            int input_count = scanf(" %d", &option);
            if (input_count != 1 || (option < 1 || option > num_items))
            {
                invalid = true;
                scanf("%*[^\n]"); // clear input buffer
                printf("\n invalid input\n");
            }
            else
            {
                option--;
                display_record(ptr_stud[keys[option]]);
                invalid = false;
            }
        }
        while(invalid);
    }
}

void search_by_number(struct student *ptr_stud)
{

    printf("\nEnter student number: ");
    int st_num;
    scanf(" %d", &st_num);
    getchar();

    printf("\nList of Similar Results: \n\n");
    int key;
    int num = 0;
    int found = false;
    printf("  No. | Student No. | FirstName - MiddleName - LastName| Birthdate | Average\n\n");
    for(int i = 0; i < num_of_studs; i++)
    {
        if(ptr_stud[i].roll_no == st_num)
        {
            printf("%4d. | %11d | %10s %10s %10s | %2d/%2d/%4d | %3.2f (%c)\n", num + 1, ptr_stud[i].roll_no, ptr_stud[i].name.first_name, ptr_stud[i].name.middle_name, ptr_stud[i].name.last_name, ptr_stud[i].birthday.day, ptr_stud[i].birthday.month, ptr_stud[i].birthday.year, ptr_stud[i].average_grade, ptr_stud[i].overall_grade);
            key = ptr_stud[i].id;
            found = true;
            num++;
            break;
        }
    }

    if(found)
    {
        int option;
        bool invalid;
        do
        {
            printf("\nSelect the student to view his/her record: ");
            int input_count = scanf(" %d", &option);
            if (input_count != 1 || (option < 1 || option > 1))
            {
                invalid = true;
                scanf("%*[^\n]"); // clear input buffer
                printf("\n invalid input\n");
            }
            else
            {
                option--;
                display_record(ptr_stud[key]);
                invalid = false;
            }
        }
        while(invalid);
    }
    else
    {
        printf("\n No Matches Found \n");
    }
}

void show_all(struct student *ptr_stud)
{

    printf("\nList of Similar Results: \n\n");
    int num_items = num_of_studs;
    int keys[num_items];
    float class_avg = 0.0;
    printf("  No. | Student No. | FirstName - MiddleName - LastName| Birthdate | Average\n\n");
    for(int i = 0; i < num_of_studs; i++)
    {
        printf("%4d. | %11d | %10s %10s %10s | %2d/%2d/%4d | %3.2f (%c)\n", i + 1, ptr_stud[i].roll_no, ptr_stud[i].name.first_name, ptr_stud[i].name.middle_name, ptr_stud[i].name.last_name, ptr_stud[i].birthday.day, ptr_stud[i].birthday.month, ptr_stud[i].birthday.year, ptr_stud[i].average_grade, ptr_stud[i].overall_grade);
        keys[i] = ptr_stud[i].id;
        class_avg += ptr_stud[i].average_grade;
    }

    printf("\n Class Average Grade: %3.2f\n\n", class_avg / (float)num_items);


    int option;
    bool invalid;
    do
    {
        printf("\nSelect the student to view his/her record: ");
        int input_count = scanf(" %d", &option);
        if (input_count != 1 || (option < 1 || option > num_items))
        {
            invalid = true;
            scanf("%*[^\n]"); // clear input buffer
            printf("\n invalid input\n");
        }
        else
        {
            option--;
            display_record(ptr_stud[keys[option]]);
            invalid = false;
        }
    }
    while(invalid);

}

void avg_upove_90(struct student *ptr_stud)
{

    printf("\nList of Similar Results: \n\n");
    int num = 0;
    int num_items = num_of_studs;
    int keys[num_items];
    printf("  No. | Student No. | FirstName - MiddleName - LastName| Birthdate | Average\n\n");
    for(int i = 0; i < num_of_studs; i++)
    {
        if(ptr_stud[i].average_grade >= 90)
        {
            printf("%4d. | %11d | %10s %10s %10s | %2d/%2d/%4d | %3.2f (%c)\n", num + 1, ptr_stud[i].roll_no, ptr_stud[i].name.first_name, ptr_stud[i].name.middle_name, ptr_stud[i].name.last_name, ptr_stud[i].birthday.day, ptr_stud[i].birthday.month, ptr_stud[i].birthday.year, ptr_stud[i].average_grade, ptr_stud[i].overall_grade);
            keys[num] = ptr_stud[i].id;
            num++;
        }
    }

    if(num == 0)
    {
        printf("\n No Records Found \n");
    }
    else
    {
        int option;
        bool invalid;
        do
        {
            printf("\nSelect the student to view his/her record: ");
            int input_count = scanf(" %d", &option);
            if (input_count != 1 || (option < 1 || option > num))
            {
                invalid = true;
                scanf("%*[^\n]"); // clear input buffer
                printf("\n invalid input\n");
            }
            else
            {
                option--;
                display_record(ptr_stud[keys[option]]);
                invalid = false;
            }
        }
        while(invalid);
    }

}

void avg_below_40(struct student *ptr_stud)
{

    printf("\nList of Similar Results: \n\n");
    int num = 0;
    int num_items = num_of_studs;
    int keys[num_items];
    printf("  No. | Student No. | FirstName - MiddleName - LastName| Birthdate | Average\n\n");
    for(int i = 0; i < num_of_studs; i++)
    {
        if(ptr_stud[i].average_grade <= 40)
        {
            printf("%4d. | %11d | %10s %10s %10s | %2d/%2d/%4d | %3.2f (%c)\n", num + 1, ptr_stud[i].roll_no, ptr_stud[i].name.first_name, ptr_stud[i].name.middle_name, ptr_stud[i].name.last_name, ptr_stud[i].birthday.day, ptr_stud[i].birthday.month, ptr_stud[i].birthday.year, ptr_stud[i].average_grade, ptr_stud[i].overall_grade);
            keys[num] = ptr_stud[i].id;
            num++;
        }
    }

    if(num == 0)
    {
        printf("\n No Records Found \n");
    }
    else
    {
        int option;
        bool invalid;
        do
        {
            printf("\nSelect the student to view his/her record: ");
            int input_count = scanf(" %d", &option);
            if (input_count != 1 || (option < 1 || option > num))
            {
                invalid = true;
                scanf("%*[^\n]"); // clear input buffer
                printf("\n invalid input\n");
            }
            else
            {
                option--;
                display_record(ptr_stud[keys[option]]);
                invalid = false;
            }
        }
        while(invalid);
    }
}

void display_record(struct student ptr_stud)
{
    printf("\n ---Student Record--- \n\n");
    printf("Student Number: %d\n", ptr_stud.roll_no);
    printf("Student Name: %s %s %s\n", ptr_stud.name.first_name, ptr_stud.name.middle_name, ptr_stud.name.last_name);
    printf("Date of birth: %d /%d /%d\n", ptr_stud.birthday.day, ptr_stud.birthday.month, ptr_stud.birthday.year);
    printf("Sex: %c\n\n", ptr_stud.sex);
    printf("Grades: \n\n");
    printf("English: %d (%c)\n", ptr_stud.grade.num_mark[0], ptr_stud.grade.char_grade[0]);
    printf("Mathematics: %d (%c)\n", ptr_stud.grade.num_mark[1], ptr_stud.grade.char_grade[1]);
    printf("Computer Science: %d (%c)\n", ptr_stud.grade.num_mark[2], ptr_stud.grade.char_grade[2]);
    printf("\n Overall Average is %2.2f (%c)", ptr_stud.average_grade, ptr_stud.overall_grade);
}

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

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    struct student stud[num_of_studs];
    int i, j;
    int total;
    float average;

    for(i = 0; i < num_of_studs; i++)
    {
        average = 0;
        total = 0;
        stud[i].id = i;

        if(i == num_of_studs -1)
        {
            stud[i].roll_no = 130521998;
            strcpy(stud[i].name.first_name, "Radwan");
            strcpy(stud[i].name.middle_name, "Abdullah");
            strcpy(stud[i].name.last_name, "Al Shawesh");
        }
        else
        {
            stud[i].roll_no = rand_num(100000000, 999999999);
            rand_firstname(stud[i].name.first_name);
            rand_middlename(stud[i].name.middle_name);
            rand_lastname(stud[i].name.last_name);
        }

        stud[i].sex = (rand_num(0, 1)? 'M':'F');
        stud[i].birthday.year = rand_num(1980, 2005);
        stud[i].birthday.month = rand_num(1, 12);
        if(stud[i].birthday.month == 2)
        {
            if(is_leap_year(stud[i].birthday.year))
            {
                stud[i].birthday.day = rand_num(1, 29);
            }
            else
            {
                stud[i].birthday.day = rand_num(1, 28);
            }
        }
        else if(check_month(stud[i].birthday.month))
        {
            stud[i].birthday.day = rand_num(1, 31);
        }
        else
        {
            stud[i].birthday.day = rand_num(1, 30);
        }

        for(j = 0; j < 3; j++)
        {
            stud[i].grade.num_mark[j] = rand_num(0, 100);
            total += stud[i].grade.num_mark[j];
            if(stud[i].grade.num_mark[j] == 100)
            {
                stud[i].grade.char_grade[j] = 'S';
            }
            else if(stud[i].grade.num_mark[j] >= 90 && stud[i].grade.num_mark[j] <100)
            {
                stud[i].grade.char_grade[j] = 'A';
            }
            else if(stud[i].grade.num_mark[j] >= 80 && stud[i].grade.num_mark[j] < 90)
            {
                stud[i].grade.char_grade[j] = 'B';
            }
            else if(stud[i].grade.num_mark[j] >= 70 && stud[i].grade.num_mark[j] < 80)
            {
                stud[i].grade.char_grade[j] = 'C';
            }
            else if(stud[i].grade.num_mark[j] >= 60 && stud[i].grade.num_mark[j] < 70)
            {
                stud[i].grade.char_grade[j] = 'D';
            }
            else if(stud[i].grade.num_mark[j] >= 50 && stud[i].grade.num_mark[j] < 60)
            {
                stud[i].grade.char_grade[j] = 'E';
            }
            else
            {
                stud[i].grade.char_grade[j] = 'F';
            }
        }

        average = (float)total / 3.0;
        stud[i].average_grade = average;

        if(stud[i].average_grade == 100)
        {
            stud[i].overall_grade = 'S';
        }
        else if(stud[i].average_grade >= 90 && stud[i].average_grade <100)
        {
            stud[i].overall_grade = 'A';
        }
        else if(stud[i].average_grade >= 80 && stud[i].average_grade < 90)
        {
            stud[i].overall_grade = 'B';
        }
        else if(stud[i].average_grade >= 70 && stud[i].average_grade < 80)
        {
            stud[i].overall_grade = 'C';
        }
        else if(stud[i].average_grade >= 60 && stud[i].average_grade < 70)
        {
            stud[i].overall_grade = 'D';
        }
        else if(stud[i].average_grade >= 50 && stud[i].average_grade < 60)
        {
            stud[i].overall_grade = 'E';
        }
        else
        {
            stud[i].overall_grade = 'F';
        }
    }

    printf("**** Student Record Query ****\n\n");


    int option;
    struct student (*ptr_stud)[num_of_studs] = &stud;

    do
    {
        printf("\n-----------Main Menu-----------\n\n");
        printf("1. Search for student record by name.\n");
        printf("2. Search for student record by student number.\n");
        printf("3. Show all Grades.\n");
        printf("4. Show all students with less than 40%% aggregate.\n");
        printf("5. Show all students with more than 90%% aggregate.\n");
        printf("6. Exit\n");

        printf("\n Choose an option: ");
        int input_count = scanf(" %d", &option);
        if (input_count != 1)
        {
            scanf("%*[^\n]"); // clear input buffer
        }
        else
        {
            getchar();
        }

        switch(option)
        {
        case 1:
            search_by_name(ptr_stud);
            break;
        case 2:
            search_by_number(ptr_stud);
            break;
        case 3:
            show_all(ptr_stud);
            break;
        case 4:
            avg_below_40(ptr_stud);
            break;
        case 5:
            avg_upove_90(ptr_stud);
            break;
        case 6:
            option = 6;
            break;
        default:
            printf("\n Invalid input. Please enter a valid menu option.\n");
            break;
        }
    }
    while(option != 6);

    return 0;
}
