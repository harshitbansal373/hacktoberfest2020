#include<stdio.h>
void series(int);
int fact(int);
int main()
{
	int n;
	printf("Enter the limit of the series :\n");
	scanf("%d",&n);
	series(n);
	return 0;
}
int fact(int n)
{int j,f=1;
	for(j=n;j>=1;j--)
	{
		f*=j;
	}
	return f;
}
void series(int n)
{	int i,f;
float  sum=0.0;
	for(i=1;i<=n;i++)
	{f=fact(i);
		sum+=1/(float)f;
	}
	printf("Sum of the series till %dth term = %0.2f",n,sum);
}

