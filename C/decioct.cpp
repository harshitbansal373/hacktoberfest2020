#include<stdio.h>
main()
{
	int a,n,t=1,b=0,r;
	printf("Enter a no : ");
	scanf("%d",&n);
	a=n;
	while(a!=0)
	{
		r=a%8;
		a/=8;
		b=b+r*t;
		t*=10;
	}
	printf("Binary equivalent of %d = %d",n,b);
}
