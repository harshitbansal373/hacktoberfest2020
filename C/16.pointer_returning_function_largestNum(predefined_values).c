#include <stdio.h>

int* largest(int*, int*);

int main()
{
	int a, b;
	int* l;

	a = 2;
	b = 10;

	printf("Values: \n");
	printf("A:%d || B:%d\n", a, b);

	l = largest(&a, &b);

	printf("largest number : %d\n", *l);

	return 0;
}


int* largest(int *a, int *b)
{
	if (*a > *b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

/*

Output:

Values: 
A:2 || B:10
largest number : 10

*/