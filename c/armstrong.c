#include<stdio.h>  
int main()    
{    
  int n,r,sum=0,temp;    
  printf("enter the number=");    
  scanf("%d",&n);    
  temp=n;    
  while(n>0)    
  {    
    r=n%10;    
    sum=sum+(r*r*r);    
    n=n/10;    
  }    
  if(temp==sum)    
    printf("Given number is an armstrong  number ");    
  else    
    printf("Given number is not an armstrong number");    
  return 0;  
  }   

/*
Output:
enter the number=153
Given number is an armstrong number
*/
