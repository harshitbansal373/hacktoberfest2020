#include<stdio.h>
int main()
{
	int n,i,l;
	printf("Enter size of the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the location from which element is to be deleted : ");
	scanf("%d",&l);
	if(l<0||l>= n)
		printf("Deletion not possible.");
	else
	{
		for(i=l;i<=n-1;i++)
			a[i]=a[i+1];
		n--;
	}
	printf("Resultant array :\n");
	for(i=0;i<=n-1;i++)
		printf("\n%d",a[i]);
		
	return 0;
}
