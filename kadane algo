#include<iostream>
using namespace std;
int kadane(int[],int);
int kadane(int a[],int n)
{
    int max_global=a[0];
    int max_tillnow=a[0];
    for(int i=0;i<n;i++)
    {
        max_tillnow=max(a[i],max_tillnow+a[i]);
        if(max_tillnow>max_global)
            max_global=max_tillnow;
    }

    return max_global;
}
int main()
{
    cout<<"hello world"<<endl;
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=kadane(a,n);
    cout<<"maximum sum of sub array is "<< sum<<endl;
    cout<<"# kadane algo is done "<<endl;
    return 0;
}
