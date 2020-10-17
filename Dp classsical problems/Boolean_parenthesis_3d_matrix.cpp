#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001][2];
int bp(string s,int i,int j,bool istrue)
{
	if(i>j)
		return dp[i][j][istrue]=0;
		
	if(i==j)
	{
		if(istrue==true)
		{
			return dp[i][j][istrue]=(s[i]=='T');
		}
		else{
			return dp[i][j][istrue]=(s[i]=='F');
		}
	}
	if(dp[i][j][istrue]!=-1)
	{
		return dp[i][j][istrue];
	}
	int ans = 0;
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lf,lt,rf,rt;
		if(dp[i][k-1][0]!=-1)
			lf=dp[i][k-1][0];
		else
			lf=bp(s,i,k-1,true);
			dp[i][k-1][0]=lf;
			
		if(dp[i][k-1][1]!=-1)
			lf=dp[i][k-1][1];
		else
			lf=bp(s,i,k-1,false);
			dp[i][k-1][1]=lf;
			
		if(dp[k+1][j][0]!=-1)
			lf=dp[k+1][j][0];
		else
			lf=bp(s,k+1,j,true);
			dp[k+1][j][0]=lf;
			
		if(dp[k+1][j][1]!=-1)
			lf=dp[k+1][j][1];
		else
			lf=bp(s,k+1,j,false);
			dp[k+1][j][1]=lf;
			
		if(s[k]=='^')
		{
			if(istrue==true)
			{
				ans+=lf*rt+lt*rf;
			}
			else
			{
				ans+=lf*rf+rt*lt;
			}
		}
		else if(s[k]=='|')
		{
			if(istrue==true)
			{
				ans+=lt*rt+lt*rf+rt*lf;
			}
			else
			{
				ans+=lf*rf;
			}
		}
		else if(s[k]=='&')
		{
			if(istrue==true)
			{
				ans+=lt*rt;
			}
			else
			{
				ans+=lf*rf+lt*rf+rt*lf;
			}
		}
	}
	return dp[i][j][istrue]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	int t;
//	cin>>t;
//	while(t--)
//	{
//		int n;
//		cin>>n;
		memset(dp,-1,sizeof(dp));
		string s = "T|F^T|F^F^T^T^F";
//		cin>>s;
		cout<<bp(s,0,s.size()-1,true);
		cout<<endl;
//	}
}
