// Naive String matching

// Subhrajyoti Behera
// C2_30

#include <stdio.h>
#include <string.h>


void match(char text[], char str[])
{	
	int l1 = strlen(text);
	int l2 = strlen(str);
	int i, j, flag = 1;

	for (i = 0; i <= l1 - l2; i++)
	{
		for (j = 0; j < l2; j++)
		{
			if (str[j] != text[j + i])
			{
				flag = 0;
			}
		}

		if (flag == 1)
		{
			printf("\nString found at index - %d\n", i);
		}
		flag = 1;
	}
}


int main()
{
	int i, size_1, size_2;
	
	printf("\nEnter the length of first string - ");
	scanf("%d", &size_1);
	
	printf("\nEnter the length of second string - ");
	scanf("%d", &size_2);
	
	char arr_1[size_1], arr_2[22];
	
	printf("\nEnter the first String - ");
	scanf("%s", arr_1);
	
	printf("\nEnter the second String - ");
	scanf("%s", arr_2);
	
	match(arr_1, arr_2);
}































