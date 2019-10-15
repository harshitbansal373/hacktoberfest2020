#include<stdio.h>    
int factorial(int n)  
{  
  int i,fact=1;
  for(i=1;i<=n;i++)
  {
    fact=fact*i;
  }
  return fact;
}  
   
void main()  
{  
  int number;  
  int fact;  
  printf("Enter a number: ");  
  scanf("%d", &number);   
  fact = factorial(number);  
  printf("Factorial of %d is %ld\n", number, fact);    
}  
