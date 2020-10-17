#include<bits/stdc++.h>
using namespace std;
int static t[101][1001];
int solve(int arr[],int i,int j)
{
	if(i>=j)
		return 0;
	int minn = INT_MAX;
	if(t[i][j]!=-1)
		return t[i][j];
	for(int k=i;k<=j-1;k++)
	{
		int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		minn = min(minn,temp);
	}
	return t[i][j]=minn;
}
int main()
{
	int arr[5] = {40,20,30,10,30};
	memset(t,-1,sizeof(t));
	cout<<solve(arr,1,4);
}
