#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>m>>n;
		int arr[m][n];
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>arr[i][j];
			}
		}
		int k=0, l=0, i;
		while(k<m && l<n)
		{
			for(i=l; i<n; i++)
			{
				cout<<arr[k][i]<<" ";
			}
			k++;
			for(i=k; i<m; i++)
			{
				cout<<arr[i][n-1]<<" ";
			}
			n--;
			if(k<m)
			{
				for(i=n-1; i>=l; i--)
				{
					cout<<arr[m-1][i]<<" ";
				}
				m--;
			}
			if(l<n)
			{
				for(i=m-1; i>=k; i--)
				{
					cout<<arr[i][l]<<" ";
				}
				l++;
			}
		}
		cout<<endl;
	}
}
