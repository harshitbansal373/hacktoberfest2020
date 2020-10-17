//Longest Common Substring Length
//LONGEST COMMON SUBSEQUENCE
#include<bits/stdc++.h>
int t[102][10002];
using namespace std;
int getlength(string x,string y,int m,int n)
{
	int result = INT_MIN;;
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
		{
		t[i][j] = 1+t[i-1][j-1];
		result = max(result,t[i][j]);
		}
	else
		t[i][j] = 0;}}
		
	return result;
}
int main()
{
	string a = "abcdef";
	string b = "cdelab";
	cout<<getlength(a,b,6,6);
}
