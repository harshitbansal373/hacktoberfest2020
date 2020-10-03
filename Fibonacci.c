#include <stdio.h>
#include <stdlib.h>
void fibonacci(int num)
{	int f=0;		//first element
	int s=1;		//second element		
	int t;			//third element
	printf("\n Fibonacci series : %d %d ",f,s);
	for( int i=2;i<num;i++)
		{t=f+s;		//third element is the sum of first and second element
		 printf("%d ",t);
		 f=s;		//now assigning second elment to first
		 s=t;		//now assigning third elment to second
		}
}
int main()
{
	printf("Enter Number of Elements : ");
	int num;
	scanf("%d" , &num);
	fibonacci(num);
	return 0;
}
