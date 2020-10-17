#include<bits/stdc++.h>
using namespace std;
int solve(string s,int i,int j,bool isTrue)
{
	if(i>j)
		return 0;
	if(i==j)
		{
			if(isTrue==true)
				return (s[i] == 'T');
			else
				return (s[i] == 'F');
		}
	int ans = 0;
	for(int k = i+1;k<=j-1;k=k+2)
	{
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);
		if(s[k]=='&')
		{
			if(isTrue==true)
			{
				ans = ans+lt*rt;
			}
			else
			{
				ans=ans+lf*rf+lt*rf+rt*lf;
			}
		}
		else if(s[k]=='|')
		{
			if(isTrue==true)
			{
				ans+=lt*rt+lt*rf+rt*lf;
			}
			else
			{
				ans +=lf*rf;
			}
		}
		else
		{
			if(isTrue==true)
			{
				ans+=lf*rt+rt*lf;
			}
			else
			{
				ans+=lt*rt+lf*rf;
			}
		}
	}
	return ans;
}
int main()
{
	string s = "T|F^T|F";
	cout<<solve(s,0,s.length()-1,false)<<endl;
	
}
