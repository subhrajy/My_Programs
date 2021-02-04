#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20

struct stack
{
    int top;
    int arr[MAX];
};

struct stack s;


bool isFull()
{
    if(s.top == MAX)
    {
        return true;
    }

    return false;
}


bool isEmpty()
{
    if (s.top == -1)
    {
        return true;
    }

    return false;
}


void push(int a)
{
    if(isFull())
    {
        printf("Stack is full !!\n");
    }

    s.top = s.top + 1;
    s.arr[s.top] = a;
}


int pop()
{
    int element;
    if(isEmpty())
    {
        printf("Stack empty.\n");
        return;
    }

    element = s.arr[s.top];
    s.top = s.top - 1;

    return element;
}


bool isOperand(char a)
{
    if (a >= 'a' && a <= 'z')
    {
        return true;
    }

    return false;
}


void main()
{
    char arr[10], exp;
    int i, ele2, ele1, result;

    printf("Enter expression - ");
    scanf("%s", &arr);

    for (i = 0; arr[i] != '\0'; i++)
    {
        exp = arr[i];

        if (isOperand(exp))
        {
            int element;

            printf("Enter value of %c\n", exp);
            scanf("%d", &element);

            push(element);
        }

        else
        {
            ele1 = pop();
            ele2 = pop();

            switch(exp)
            {
		case '+': result = ele2 + ele1;
			break;
		
		case '-': result = ele2 - ele1;
			break;

		case '*': result = ele2 * ele1;
		        break;

		case '/': result = ele2 / ele1;
		        break;
			      }
            push(result);
        }
    }
    printf("Result = %d\n", pop());
}
