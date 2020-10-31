#include<iostream>
using namespace std;
int F[10];
int fibonacci(int n)
{
    int fib[10]={-1};
    if(n<=1)
        {
            fib[n]=n;
            return n;
        }
    else
    {
        if(fib[n-2]== -1 )
        {
            fib[n-2] = fibonacci(n-2);
        }
        if(fib[n-1] == -1)
        {
         fib[n-1]= fibonacci(n-1);
        }
        fib[n]= fib[n-1]+fib[n-2];
            return fib[n-2]+fib[n-1];
    }
}
int mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=mfib(n-2);
        if(F[n-1]==-1)
            F[n-1]=mfib(n-1);
        F[n]=F[n-2]+F[n-1];
    return F[n-2]+F[n-1];
}
}

int main()
{
int i;
    for(i=0;i<10;i++)
        F[i]=-1;
    //printf("%d \n",mfib(5));
    cout<<mfib(5);
return 0;
}