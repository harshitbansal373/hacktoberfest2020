#include<stdio.h>
int main()
{
	int i,j,m,n,sum=0,avg=0;
	printf("Enter Number Of Rows : ");
	scanf("%d",&m);
	printf("Enter Number Of Columns : ");
	scanf("%d",&n);
	int matrix[m][n];
	printf("Enter Matrix Elements : ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);		
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			sum=sum+matrix[i][j];
	avg=sum/(m*n);
	printf("\nSum Of All Elements In Matrix = %d",sum);
	printf("\nAverage Of Matrix = %d",avg);
	return 0;
}
