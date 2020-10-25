#include<stdio.h>
#include<conio.h>
int main()
{
char str[30];
int i=0;
clrscr();
printf("\n\n\n\t\t\t ****** ACROMATIC STRING ****** ");
printf("\n\n\n\t Enter the string = ");
gets(str);
printf("\n\n\n\t%c",str[0]);
while(str[i]!='\0')
{
if(str[i]==' '||str[i]==' ')
{
if(isupper(str[i+1])!=0)
{
printf("\t%c",str[i+1]);
}
}
i++;
}
return 0;
}
