#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,k;
    cout<<"Hello "<<endl;
    cout<<"NOTE :- array should be in form nxn (it means no.rows=no.column)"<<endl;
    cout<<"enter the size of the array (nxm)  "<<endl;
    cin>>n;
    int a[n][n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
   cout<<"array transversal"<<endl;

    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"rotating given array 90 degree anticlockwise"<<endl;
     for(int i=0;i<n;i++)
     {
         for(int j=i;j<n;j++)
         {
             int temp=a[i][j];
             a[i][j]=a[j][i];
             a[j][i]=temp;
         }
     }
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<(n/2);j++)
         {
             int temp=a[j][i];
             a[j][i]=a[n-1-j][i];
             a[n-1-j][i]=temp;
         }
     }
    for(int i=0;i<n;i++ )
        {
    for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
        }


 return 0;
}
