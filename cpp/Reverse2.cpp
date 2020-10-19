#include <iostream>

using namespace std;

void Reverse2(int *A,int n)
{
    int i,j,temp;
    for(i=0,j=n-1 ; i<j ; ++i,--j)
    {
        temp=A[i];
         A[i]=A[j];
         A[j]=temp;
    }
    return ;
}

int main() {
    int i,k,n,index;
	cout<<"Enter the value of n :";
	cin>>n;
	int A[n];
	for(i=0;i<n;++i)
	{
    	 cout<<"Enter the value : ";
    	 cin>>A[i];
    }
    Reverse2(A,n);
    for(i=0;i<n;++i)
     cout<<A[i]<<endl;
	return 0;
}