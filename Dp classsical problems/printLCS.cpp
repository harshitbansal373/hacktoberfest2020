//Printig the Longest Common Susequence
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
		
	string s;
	int i=m;
	int j = n;
	while(i!=0&&j!=0)
	{		
		if(x[i]==y[j])
			{
				s = s+x[i-1];
				i = i-1;
				j = j-1;
			}
			else
			{
				if(t[i-1][j]>t[i][j-1])
				{
					i = i-1;
				}
				else
				{
					j = j-1;
				}
			}
	}
	reverse(s.begin(),s.end());
	cout<<s;
	return t[n][m];
}
int main()
{
	string a = "Prabal";
	string b = "bansal";
	cout<<getlength(a,b,6,6);
}
