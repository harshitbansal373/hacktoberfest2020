#include<stdio.h>
int main()
{
	int i,t,n,min,max,maxpos,minpos;
	printf("Enter size of the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	max=a[0];
	maxpos=0;
	minpos=0;
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			minpos=i;
		}
		if(a[i]>max)
		{
			max=a[i];
			maxpos=i;
		}
			
	}
	t=a[maxpos];
	a[maxpos]=a[minpos];
	a[minpos]=t;
	printf("Array after interchanging the smallest and biggest numbers :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
