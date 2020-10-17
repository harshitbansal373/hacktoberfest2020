//Minimum number of operation to convert a to b
//LONGEST COMMON SUBSEQUENCE
#include<bits/stdc++.h>
int t[102][10002];
using namespace std;
int getlength(string x,string y,int m,int n)
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j] = 0;
			}
		}
	}
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
	if(x[i-1]==y[j-1])
		t[i][j] = 1+t[i-1][j];
	else
		t[i][j] = max(t[i][j-1],t[i-1][j]);}}
		
		cout<<t[m][n]<<endl;
	cout<<"del"<<" "<<m-t[m][n]<<endl;
	cout<<"ins"<<" "<<n-t[m][n]<<endl;
}
int main()
{
	string a = "heap";
	string b = "pea";
	getlength(a,b,4,3);
}
