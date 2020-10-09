#include<stdio.h>
void main()
{
int n,a[100],i,j,miniindex,t;
printf("Program to implement selection sort");
printf("Enter the number of elements");
scanf("%d",&n);
printf("Enter the elements one by one");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)

{
miniindex=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[miniindex])
{
miniindex=j;
}
}
if(miniindex!=i)
{
t=a[i];
a[i]=a[miniindex];
a[miniindex]=t;

}
}
for(i=0;i<n;i++)
{
printf("%d",a[i]);
printf(" ");
}
}

   
   
