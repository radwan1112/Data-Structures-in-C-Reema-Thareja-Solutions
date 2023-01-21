#include <stdio.h>
#include <stdbool.h>

bool isvalid(int arr_element, int duplicate_num[], int n)
{

    for(int h = 0; h < n/2; h++)
    {
        if(arr_element == duplicate_num[h])
        {
            return false;
        }
        else
        {
            continue;
        }
    }

    return true;
}

int main()
{

    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int arr[n];
    int full_n;

    // Fill the array
    for(int i = 0; i < n; i++)
    {
        printf("Enter number at pos[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int pos[n];
    int duplicate;
    int repeat[n/2];
    int r = 0;
    int l = 0, p = 0;
    bool is_repeated = false;

    printf("\nThe following numbers are repeated: \n");


    for(int l = 0; l < n; l++)
    {
        if(r == 0 || isvalid(arr[l], repeat, n))
        {
            for(int k = 0; k < n; k++)
            {
                if(k == l)
                {
                    continue;
                }
                else if(arr[l] == arr[k])
                {
                    is_repeated = true;
                    duplicate = arr[l];
                    if(p == 0)
                    {
                        pos[p] = l;
                        p++;
                        pos[p] = k;
                        p++;
                    }
                    else
                    {
                        pos[p] = k;
                        p++;
                    }

                }
                else
                {
                    continue;
                }
            }

            if(is_repeated)
            {
                repeat[r] = arr[l];
                r++;
                printf("\nNumber %d is repeated %d times in position: ", duplicate, (p));

                for(int w = 0; w < p; w++)
                {
                    if(w == p - 1)
                    {
                        printf("%d", pos[w]);

                    }
                    else
                    {
                        printf("%d, ", pos[w]);

                    }
                }

            }

            else
            {
                printf("\nNumber %d is Unique", arr[l]);
            }

        }

        is_repeated = false;
        p = 0;

    }

    return 0;
}
