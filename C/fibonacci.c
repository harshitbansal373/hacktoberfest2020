#include <stdio.h>
//fib(0)=0 and fib(1)=1
//using recursion
int fib1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib1(n - 1) + fib1(n - 2);
    }
}
//using dynamic programming
int fib2(int n)
{
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
//dynamic, space optimised
int fib3(int n)
{
    int a, b, c;
    a = 0;
    b = 1;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return c;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int res;
    res = fib3(N);
    printf("%d\n", res);
    return 0;
}
