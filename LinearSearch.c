#include "stdio.h"

void main()
{
  int arr[5], i, element, check;

  printf("Enter 5 elements.\n");
  for (i = 0; i < 5;i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element you want to find\n");
  scanf("%d", &element);

  check = search(arr, element);

  check >= 0 ? printf("Element found at positon %d\n", check + 1) : printf("Element not found !!\n");
}


int search(int arr[], int element)
{
  int i;

  for (i = 0; i < 5; i++)
  {
    if (element == arr[i])
    {
      return i;
    }
  }

  return -1;
}
