#include<bits/stdc++.h>
using namespace std;
int t[102][1002];
int knapsack(int w[],int v[],int C,int ind)
{
	if(C==0||ind==0)
	{
		return 0;
	}
	else if(t[ind][C]!=-1)
	{
		return t[ind][C];
	}
	else
	{
		if(w[ind-1]<=C)
		{
			return(t[ind][C] = max(v[ind-1]+knapsack(w,v,C-w[ind-1],ind-1),knapsack(w,v,C,ind-1)));
		}
		else
		{
			return (t[ind][C] = knapsack(w,v,C,ind-1));
		}
	}
}
int main()
{
		int c,n;
	cin>>c>>n;
		memset(t,-1,sizeof(t));

	int crr[n],cost[n];
	for(int i=0;i<n;i++)
	{
		cin>>crr[i]>>cost[i];
	}
	int k = knapsack(crr,cost,c,n);
	cout<<k<<endl;
	int mass=0;
	for(int i=0;i<=100;i++)
	{
		if(t[n+1][i]==k)
		{
			mass=i;
		}
	}
	cout<<mass<<" "<<k;
}
