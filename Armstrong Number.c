#include <stdio.h>
int Armstrong(int num);             //Function Declaration
int main()
{
    int num,result;
    printf("Enter the number to check whether it is an Armstrong number or not:");
    scanf("%d",&num);
    result = Armstrong(num);
    if(result==1)
        printf("%d is  Armstrong number",num);
    else
        printf("%d is not an Armstrong number",num);
    return 0;
}



// Function Definition
int Armstrong(int num)   
{
    int sum=0,r,n;
    n=num;
    while(n>0)
    {
        r=n%10;
        sum=sum+(r*r*r);
        n=n/10;
    }
    if(sum==num)
        return 1;
    else
        return 0;
}
