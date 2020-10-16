#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter order of square matrix : ");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter array elements :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
			}
			else if(i>j)
			{
				a[i][j]=-1;
			}
			else
				a[i][j]=1;
		}
	}
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		}
		return 0;
	}
				
	
