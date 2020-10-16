#include<stdio.h>
void add(int *n);
int main()
{
	int num=2;
	printf("The value of num before calling the function = %d", num);
	add(&num);
	printf("\n");
	printf("The value of num after calling the function = %d", num);
	return 0;
}
void add(int *n)
{
	*n= *n +10;
	
}
	
