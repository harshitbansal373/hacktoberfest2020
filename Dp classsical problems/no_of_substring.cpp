#include<bits/stdc++.h>
using namespace std;
int comp(string &s,string &b,int m,int n)
{
	if(m==0&&n==0||n==0)
		{
			return 1;
		}
	if(m==0)
		return 0;
	
	if(s[m-1]==b[n-1])
	{
		return (comp(s,b,m-1,n-1)+comp(s,b,m-1,n));
	}
	else
	{
		return comp(s,b,m-1,n);
	}
}
int main()
{
	string s;
	cin>>s;
	string b = "QAQ";
	cout<<comp(s,b,s.length(),b.length())<<"\n";
}
