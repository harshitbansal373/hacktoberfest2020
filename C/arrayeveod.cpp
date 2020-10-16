#include<stdio.h>
main()
{
	int i,m,n;
	printf("Enter starting and end of array :");
	scanf("%d%d",&m,&n);
	for(i=m;i<n+1;i++)
	{
		if(i%2==0)
		printf("%d is even\n",i);
		else
		printf("%d is odd\n",i);
	}
}

