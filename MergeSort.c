// Subhrajyoti Behera
// C2_30

#include "stdio.h"


void display(int arr[], int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]);
  }

  printf("\n");
}


/*void merge(int arr[], int p, int q, int r)
{
  int i = p, j = q + 1, k = p, res[r];

  while (i <= q && j <= r)
  {
    if (arr[i] <= arr[j])
    {
      res[k] = arr[i];
      i += 1;
    }

    else
    {
      res[k] = arr[j];
      j += 1;
    }

    k += 1;
  }

  if (i > q)
  {
    int l;
    for (l = j; l <= r; l++)
    {
      res[k] = arr[l];
      k += 1;
      j += 1;
    }
  }

  else
  {
    int l;
    for (l = i; l <= q; l++)
    {
      res[k] = arr[l];
      k += 1;
      l += 1;
    }
  }

  k = 0;

  for (k = p; k <= r; k++)
  {
    arr[k] = res[k];
  }
}*/


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    printf("n1 is %d\n", n1);

    int n2 = r - m;
    printf("n2 is %d\n", n2);

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void sort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    printf("Mid is %d\n", mid);

    printf("calling 1st sort\n");
    sort(arr, left, mid);

    printf("calling 2nd sort\n");
    sort(arr, mid + 1, right);

    printf("calling merge\n");
    merge(arr, left, mid, right);
  }
}


void main()
{
  int arr[] = {43, 233, 56, 12, 65, 22, 11, 345};
  int size = sizeof(arr) / sizeof(arr[0]);

  sort(arr, 0, size - 1);

  printf("Sorted array is : ");
  display(arr, size);
}
