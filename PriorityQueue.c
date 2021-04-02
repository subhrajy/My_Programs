// priority Queue

// Subhrajyoti Behera
// C2_30


#include <stdio.h>
#include <stdlib.h>
#define max 20

int h_size;


void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void heapify(int a[], int i)
{
    int l, r, largest = i;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < h_size && a[l] > a[i])
    {
        largest = l;
    }

    if (r < h_size && a[r] > a[i])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, largest);
    }
}


void increase_Key(int a[], int n, int k)
{
    int p;

    if (n > k)
    {
        printf("\nSomething went wrong!!");
        return;
    }

    a[n] = k;
    p = n / 2;

    while ((n > 1) && (a[p] < n))
    {
        swap(&a[n], &a[p]);
        n = n / 2;
    }
}


void display(int a[])
{
    int i;

    for (i = 0; i <= h_size; i++)
    {
        printf("%d,\t", a[i]);
    }

    printf("\n");
}


void insert(int a[], int n)
{
    h_size += 1;

    a[h_size] = -1;
    increase_Key(a, h_size, n);
}


int extract_Max(int a[])
{
    if (h_size < 0)
    {
        printf("\nNo elements in queue!!");
        return -1;
    }

    int t, max_element = a[0];
    swap(&a[0], &a[h_size]);

    h_size -= 1;
    heapify(a, 0);

    return max_element;
}


int main()
{
    int n, k, ch;
    int a[max];

    h_size = -1;

    while (1)
    {
        printf("\n1) Insert\n2) Increase key\n3) Extract max\n4) Display elements\n0) Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter the element - ");
                scanf("%d", &n);

                insert(a, n);

                break;

            case 2:
                printf("\nEnter the key's index - ");
                scanf("%d", &n);

                printf("\nEnter the new key - ");
                scanf("%d", &k);

                increase_Key(a, n, k);

                break;

            case 3:
                n = extract_Max(a);
                printf("\nExtracted element is - %d", n);

                break;

            case 4:
                display(a);

                break;

            case 0:
                exit(0);

            default:
                printf("\nInvalid entry!! \nEnter again.");
        }
    }
}
