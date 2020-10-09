#include<stdio.h>
main()
{
	int n,fd,ld,sum;
	printf("Enter the number:");
	scanf("%d",&n);
	ld=n%10;
	while(n>=10)
	{
		n=n/10;
	}
	fd=n;
	sum=fd+ld;
	printf("The sum of first and last digit = %d",sum);
	
	
}
