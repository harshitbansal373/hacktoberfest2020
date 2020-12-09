#include <stdio.h>

int main()
{
	int a, b, c, ch;

	// Declaration
	a=10,b=20;

	// Print the values
	printf("A = %d and B = %d\n", a, b);

	// Take choice
	printf("Press 1(add)\n");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1:
			c = a+b;
			printf("Addition = %d\n", c);
			break;
		
		default:
			printf("Wrong choice!\n");
			break;
	}

	return 0;
}

/*

Output:

A = 10 and B = 20
Press 1(add)
1
Addition = 30

*/
