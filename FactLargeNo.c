#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

int main()
{
	int fact[100000]={0},num=0,length=1,n,i,j,k;
	system("cls");
	fact[0]=1;
	printf("Enter the Number:\n");
	scanf("%d",&n);
	printf("%d ",fact[0]);
	for(i=1;i<=n;i++)
	{
		num=0;
		for(j=0;j<length;j++)
		{
			fact[j]=fact[j]*i;
			fact[j]=fact[j]+num;
			num=fact[j]/10;
			fact[j]=fact[j]%10;
		}
		while(num!=0)
		{
			fact[length]=num%10;
			num=num/10;
			length++;
		}
	}
	printf("\nAnswer:\n\n");
	for(i=(length-1);i>=0;i--)
	{
		printf("%d",fact[i]);
	}
	return 0;
}
