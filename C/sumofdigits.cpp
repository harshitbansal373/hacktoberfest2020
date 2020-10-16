#include<stdio.h>
main()
{
	int a,r,t,sum=0;
	printf("Enter a no : ");
	scanf("%d",&a);
	t=a;
	while(t>0)
	{
		r=t%10;
		sum+=r;
		t/=10;
	}
	printf("Sum of digits of %d is %d",a,sum);
}
		
