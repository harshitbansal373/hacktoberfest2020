#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int i,a[10],n;
float sum1=0,sum2=0;
 float mean,sd,sd1;
 clrscr();
 printf("\n enter the limit");
 scanf("%d",&n);
 printf("\n enter the elements");
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
 sum1=sum1+a[i];
 sum2=sum2+a[i]*a[i];
 }
 mean=sum1/n;
 sd1=sum2/n;
 sd=sqrt(sd1-mean*mean);
 printf("\n the mean =%f",mean);
 printf("\n the standard deviation =%f",sd);
 getch();
 }
