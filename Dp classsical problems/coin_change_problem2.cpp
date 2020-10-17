//coin change problem
// we are given a no of coins and we want to find the total no ways through whcih we can make the required sum
// Dynamic Programming Unbounded knapsack
#include<bits/stdc++.h>
using namespace std; 
int t[102][10002];
int noofways(int c[],int w,int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0)
				t[i][j] = INT_MAX-1;
			if(j==0)
				t[i][j] = 0;
			if(i==1&&j>0)
			{
				if(j%c[i]==0)
				{
					t[i][j] = j/c[i];
				}
				else
				{
					t[i][j] = INT_MAX-1;
				}
			}
		}
	}
for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(c[i-1]<=j)
			{
				t[i][j] = min(t[i][j-c[i-1]]+1,t[i-1][j]);
			}
			else
			{
				t[i][j] = t[i-1][j];
			}
	}}
	return t[n][w];
}
int main()
{
	int c[3] = {1,2,3};
	int w = 10;
	cout<<noofways(c,w,3);
}
