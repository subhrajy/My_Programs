// MergeSort
// Subhrajyoti Behera
// C2_30

#include "stdio.h"


void display(int arr[], int size)
{
  int i;

  for (i = 0; i < size - 1; i++)
  {
    printf("%d, ", arr[i]);
  }

  printf("%d", arr[size - 1]);
  printf("\n");
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
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

    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}


int main()
{
  int arr[] = {43, 233, 56, 12, 65, 22, 11, 345};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array is.\n");
  display(arr, size);

  sort(arr, 0, size - 1);

  printf("\n\nSorted array is : ");
  display(arr, size);

  return 0;
}
