//QuickSort
//Subhrajyoti Behera
// C2-30

#include "stdio.h"


int partition(int arr[], int left, int right)
{
  int pivot = arr[right];
  int temp = left - 1;
  int i;

  for (i = left; i < right; i++)
  {
    if (arr[i] <= pivot)
    {
      temp += 1;

      int third = arr[temp];
      arr[temp] = arr[i];
      arr[i] = third;
    }
  }

  int third = arr[temp + 1];
  arr[temp + 1] = arr[right];
  arr[right] = third;

  return temp + 1;
}


void sort(int arr[], int left, int right)
{
  if (left < right)
  {
    int pivot = partition(arr, left, right);

    sort(arr, left, pivot - 1);
    sort(arr, pivot + 1, right);
  }
}


void display(int arr[], int size)
{
  int i;

  for (i = 0; i < size; i++)
    printf("%d,\t", arr[i]);

  printf("%d", arr[size]);

  printf("\n");
}


int main()
{
  int size, i;

  printf("\nEnter size of the array - ");
  scanf("%d", &size);

  int arr[size];

  printf("\nEnter elements into array.\n");
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  sort(arr, 0, size - 1);
  display(arr, size - 1);

  return 0;
}
