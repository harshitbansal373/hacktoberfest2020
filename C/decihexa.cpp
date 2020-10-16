#include<stdio.h>
main()
{
	printf("Enter a no : ");
	scanf("%d",&n);
	q=n;
	while(q!=0)
	{
		t=q%16;
		if(t<10)
		t+=48;
		else
		t+=55;
		n[i++]=t;
		q/=16;
	}
	printf("Hexadecimal equivalent of %d is %c",
	

