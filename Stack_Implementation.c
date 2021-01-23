// Subhrajyoti Behera
// Roll - 30 | Section - C2

#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

int stack[10], size = 10, top = -1;

bool isEmpty()
{
  if (top <= -1)
  {
    return true;
  }

  return false;
}


bool isFull()
{
  if (top >= size - 1)
  {
    return true;
  }

  return false;
}


void push(int element)
{
  if (isFull())
  {
    printf("Stack is full !!\n");
    return;
  }

  stack[++top] = element;
}


int pop()
{
  if (isEmpty())
  {
    return -1;
  }

  int popped = stack[top];
  --top;

  return popped;
}


void display()
{
  int i;

  if (top >= 0)
  {
    for (i = 0; i <= top; i++)
    {
      printf("%d,\t", stack[i]);
    }

    printf("\n");
  }

  else
  {
    printf("Stack is empty\n");
  }
}


void main()
{
  int choice, element;
  printf("1) push\n2) pop\n3) display\n0) Exit");

  do
  {
    printf("\nEnter choice - ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        printf("Enter the element you want to push.\n");
        scanf("%d", &element);
        push(element);
        break;

      case 2:
        element = pop();
        element == -1 ? printf("Stack is empty !!\n") : printf("Element %d is popped.\n", element);
        break;

      case 3:
        display();
        break;

      case 0:
        exit(0);

      default:
        printf("\nwrong choice\n");
    }
  }
  while(choice != 0);
}
