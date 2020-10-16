#include<stdio.h>
int main()
{	int i,j,n,m;
	printf("Enter no of rows and columns : ");
	scanf("%d%d",&m,&n);
	int a[m][n],b[m][n],c[m][n];
	printf("Enter 1st array elements :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter 2nd array elements :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("Sum of the 2 arrays stored in another array :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
	
	
	
	
