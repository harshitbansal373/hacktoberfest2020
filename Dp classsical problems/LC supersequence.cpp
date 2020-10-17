//Shortest Common Supersequence
//In this problem create a supersequence that will give both the sequences.
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
	if(x[i]==y[j])
		t[i][j] = 1+t[i-1][j];
	else
		t[i][j] = max(t[i][j-1],t[i-1][j]);}}
		
	return (m+n-t[n][m]);
}
int main()
{
	string a = "abcdef";
	string b = "abcdel";
	cout<<getlength(a,b,6,6);
}

