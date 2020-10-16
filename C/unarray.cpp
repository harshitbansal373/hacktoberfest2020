#include<stdio.h>
int main()
{
	int n,i;
	int a[n];
	printf("Enter size of array");
	scanf("%d",&n);
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
}
printf("array elements are : ");
for(i=0;i<n;i++)
{
	printf("%d",a[i]);
}return 0;
}
