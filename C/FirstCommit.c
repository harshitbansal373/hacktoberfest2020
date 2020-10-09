//FirstCommit
#include <stdio.h>
int main() 
{
	int n,n1,sum=0,fact=1,rem;
    scanf("%d",&n);
    n1 = n;
    while(n1>0)
    {
      rem = n1%10;
      for(int i=1;i<=rem;i++)
      {
        fact = fact * i;
      }
      sum = sum + fact;
      n1 = n1/10;
      fact = 1;
    }
   if (sum == n)
   printf("Yes");
   else
   printf("No");
  
      
    
	return 0;
}
