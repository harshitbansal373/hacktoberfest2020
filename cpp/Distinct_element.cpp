// program to find the Distinct element and repeated element separately 

#include <bits/stdc++.h>
using namespace std;

void distinct(int arr[],int n)
{
    unordered_set<int>gen;
    unordered_set<int>repeate;

    unordered_set<int>::iterator itr, itr2;

    for(int i=0;i<n;i++)
    {
        if(gen.find(arr[i])==gen.end())
        {
            gen.insert(arr[i]);
        }
        else
        {
            repeate.insert(arr[i]);
        }  
    }
    cout<<"Repeated elements : ";
    for(itr=repeate.begin();itr!=repeate.end();itr++)
    {
        cout<<*itr<<" ";
    }
//For Distinct Element
unordered_set<int>distinct;

    for(itr=gen.begin();itr!=gen.end();itr++)
    {
            if(repeate.find(*itr)==repeate.end())
            {
                distinct.insert(*itr);
            }
    }
    cout<<"\nDistinct element : ";
    for(itr2=distinct.begin();itr2!=distinct.end();itr2++)
    {
        cout<<*itr2<<" ";
    }

}

int main(int argc, char const *argv[])
{
    cout << "Enter the size of array:"<<endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements :"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<"\nYour array : ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    distinct(arr,n);
    return 0;
}
