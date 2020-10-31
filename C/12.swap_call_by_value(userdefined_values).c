#include <stdio.h>

void swap(int, int);

int main()
{
	int a, b;

	printf("Enter two numbers: ");
	scanf("%d%d", &a, &b);

	printf("Before swap:\n");
	printf("A = %d || B = %d\n", a, b);

	swap(a, b);

	printf("After swap:\n");
	printf("A = %d || B = %d\n", a, b);

	return 0;
}


void swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	printf("\nInside swap:\n");
	printf("A = %d || B = %d\n\n", a, b);
}


/*

Output:

Enter two numbers: 1 2
Before swap:
A = 1 || B = 2

Inside swap:
A = 2 || B = 1

After swap:
A = 1 || B = 2


*/