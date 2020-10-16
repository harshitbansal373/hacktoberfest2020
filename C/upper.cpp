#include<stdio.h>
#include<conio.h>
int main()
{
	char h;
	printf("enter a char:");
	scanf("%c",&h);
	int u=h;
	if (u>=65 && u<=90)
	printf("this is a upper case word");
	else if(u>=97 && u<=122)
	printf("this is a lower case word");
	else if(u>=48 && u<=57)
	printf("this is a digit");
	else if(u>=0 && u<=47 || u>=58 && u<=64 || u>=91 && u<=96 || u>=123 && u<=127)
	printf("this is a special char");
	return 0;
}
	
