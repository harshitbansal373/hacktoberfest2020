#include<stdio.h>
#include<conio.h>
int main()
{
 int a[50],b[50],c[50],i,j,s1,s2;
 printf("Enter how many elements in set 1\n");
 scanf("%d",&s1);
 printf("Enter how many elements in set 2\n");
 scanf("%d",&s2); 
 printf("Enter the elements for set 1\n");
 for(i=0;i<s1;i++)
 {
   scanf("%d",&a[i]);
 }
 printf("Enter the elements for set 2\n");
 for(i=0;i<s2;i++)
 {
   scanf("%d",&b[i]);
 }
 printf("cartesian product=");
 printf("{");
 for(i=0;i<s1;i++)
 {
   for(j=0;j<s2;j++)
   {
      printf("(%d,%d)",a[i],b[j]);
      printf(",");
   }
 }
 printf("}");
 }
