#include<iostream>
using namespace std;
int main()
{
    int n;
    int temp;
    cout<<"enter the size of the array"<<"\n";
    cin>>n;
    int a[n];
    cout<<"enter the elements of the array"<"\n";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for (int i=0;i<n;i=i+2)
    {
        if(i>0&&a[i-1]>a[i])
        {
            swap(a[i],a[i-1]);
        }

        if(i<=n-2&&a[i+1]>a[i])
        {
            swap(a[i],a[i+1]);
        }
    }



        cout<<"array after wave sort"<<"\n";
        for (int i=0;i<n;i++)
        {
            cout<<a[i]<<"\n";
        }

        return 0;

    }


