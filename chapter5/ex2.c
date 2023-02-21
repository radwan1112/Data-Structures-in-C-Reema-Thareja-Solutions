#include <stdio.h>

int main()
{
    typedef struct complex
    {
        int real;
        int imag;

    } COMPLEX;

    COMPLEX c1, c2, sum_c, sub_c;

    printf("Complex numbers calculator\n\n");
    int option;

    do
    {
        printf("\n ******** MAIN MENU *********");
        printf("\n 1. Add complex numbers");
        printf("\n 2. Subtract complex numbers");
        printf("\n 3. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("Enter the real parts of the first complex number: ");
            scanf(" %d", &c1.real);
            printf("Enter the imaginary parts of the first complex number: ");
            scanf(" %d", &c1.imag);
            printf("\n");
            printf("Enter the real parts of the second complex number: ");
            scanf(" %d", &c2.real);
            printf("Enter the imaginary parts of the second complex number: ");
            scanf(" %d", &c2.imag);
            sum_c.real = c1.real + c2.real;
            sum_c.imag = c1.imag + c2.imag;
            printf("(%d + %di) + (%d + %di) = %d + %di", c1.real, c1.imag, c2.real, c2.imag, sum_c.real, sum_c.imag);

            break;

        case 2:
            printf("Enter the real parts of the first complex number: ");
            scanf(" %d", &c1.real);
            printf("Enter the imaginary parts of the first complex number: ");
            scanf(" %d", &c1.imag);
            printf("\n");
            printf("Enter the real parts of the second complex number: ");
            scanf(" %d", &c2.real);
            printf("Enter the imaginary parts of the second complex number: ");
            scanf(" %d", &c2.imag);
            sub_c.real = c1.real - c2.real;
            sub_c.imag = c1.imag - c2.imag;
            printf("(%d + %di) - (%d + %di) = %d + %di", c1.real, c1.imag, c2.real, c2.imag, sub_c.real, sub_c.imag);
            break;
        }

    }
    while(option != 3);

    return 0;
}
