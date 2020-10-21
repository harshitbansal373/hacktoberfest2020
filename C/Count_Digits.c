#include<stdio.h>
int countDigit(int n) 
{ 
    if (n == 0) 
        return 0; 
    return 1 + countDigit(n / 10); 
} 
int main()
{
    int number,count;
    printf("Enter a number:");
    scanf("%d",&number);
    count=countDigit(number);
    printf("%d",count);
    return 0;
}
