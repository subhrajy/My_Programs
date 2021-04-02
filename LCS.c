// LCS

// Subhrajyoti Behera
// C2_30


#include "stdio.h"
#include "string.h"

int i, j, size_1, size_2, c[22][22];
char arr_1[22], arr_2[22], b[22][22];


void display(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (b[i][j] == 'c')
    {
        display(i - 1, j - 1);
        printf("%c", arr_1[i - 1]);
    }

    else if (b[i][j] == 'u')
    {
        display(i - 1, j);
    }

    else
    {
        display(i, j - 1);
    }
}


void LCS()
{
    size_1 = strlen(arr_1);
    size_2 = strlen(arr_2);

    for (i = 0; i <= size_1; i++)
    {
        c[i][0] = 0;
    }

    for (i = 0; i <= size_2; i++)
    {
        c[0][i] = 0;
    }


/*----------------------------------------------------*/
    int i = 0, j = 0;

    while (i != '\n')
    {
        while (j != '\n')
        {
            printf("%d,\t", c[i][j]);
            j++;
        }

        printf("\n");
        i++;
    }
/*----------------------------------------------------*/


    for (i = 1; i <= size_1; i++)
    {
        for (j = 1; j <= size_2; j++)
        {
            if (arr_1[i - 1] == arr_2[j - 1])
            {
                c[i][j] = c[i - 1][j] + 1;
                b[i][j] = 'c';
            }

            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }

            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}


int main()
{
    printf("\nEnter the 1st sequence - ");
    scanf(" %s", arr_1);

    printf("\nEnter the 2nd sequence - ");
    scanf(" %s", arr_2);

    LCS();

    printf("\nLongest common sequence is - ");
    display(size_1, size_2);

    return 0;
}
