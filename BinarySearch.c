#include "stdio.h"

void main()
{
  int arr[5], i, element, size, check;

  printf("Enter 5 elements.\n");
  for (i = 0; i < 5;i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element you want to find\n");
  scanf("%d", &element);

  size = sizeof(arr) / sizeof(arr[0]);
  sort(arr, size);

  check = search(arr, 0, size, element);

  check >= 0 ? printf("Element found.\n") : printf("Element not found !!\n");
}


void sort(int arr[], int size)
{
  int i, j, min;

  for (i = 0; i < size - 1; i++)
  {
    min = i;

    for (j = i + 1; j < size; j++)
      if (arr[j] < arr[min])
        min = j;

    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}


int search(int arr[], int left, int right, int element)
{
  while (left < right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == element)
      return element;

    if (arr[mid] < element)
      left = mid + 1;

    else
      right = mid - 1;
  }

  return -1;
}
