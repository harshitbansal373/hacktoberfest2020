#include <stdio.h>
void main()
{
	int a,b,t1,t2,q,r;
    printf("Enter 2 numbers whose gcd you want to compute:");
	scanf("%d %d",&a,&b);
	t1=a;
	t2=b;
	while (b > 0)
	{
		q = a / b;
		r = a - (q * b);
		a = b;
		b = r;
	}
	//return a;
	printf("GCD(%d,%d) is %d:",t1,t2,a);
	//return 0;
}
