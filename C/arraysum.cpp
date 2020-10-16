#include<stdio.h>
int main()
{
	int a[10],i;
	printf("Enter array elements : ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	float avg=0;
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	avg=sum/10;
	printf("Sum and average of the array elements are %d and %f respectively ",sum,avg);
	return 0;
}
