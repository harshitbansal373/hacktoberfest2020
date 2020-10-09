#include<iostream>
using namespace std;
int A[25];
//int SelectionSort(int high,int low);
int main()
{
    int i, n;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"\n Enter elements:";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    //SelectionSort(0,n-1);

     int  j=0,minindex,temp=0;
    for(i=0;i<=n-1;i++)
    {
        minindex=i;
        for(j=i+1;j<=n-1;j++)
    
        {
            if(A[j]<A[minindex])
            {
                minindex=j;
            }
        }
        temp=A[i];
        A[i]=A[minindex];
        A[minindex]=temp;
    }
   
    cout<<"\n After Sorting \n";
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

