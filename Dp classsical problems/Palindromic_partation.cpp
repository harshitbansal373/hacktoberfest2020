//Palindromic Partationing
#include<bits/stdc++.h>
using namespace std;
int static t[101][1001];
bool ispalindrome(string s,int i,int j)
{
	string p="";
	for(int l = i;l<=j;l++)
	{
		p=p+s[l];
	}
	string t = p;
	reverse(p.begin(),p.end());
	if(p.compare(t)==0)
		return true;
	else
		return false;
}
int partation(string s,int i,int j)
{
	if(i>=j)
		return 0;
	if(ispalindrome(s,i,j))
		return 0;
	if(t[i][j]!=-1)
		return t[i][j];
	int mini = INT_MAX;
	for(int k = i;k<=j-1;k++)
	{
		int left,right;
		if(t[i][k]!=-1)
			left = t[i][k];
		else
			left = partation(s,i,k);
			t[i][k]  = left;
			
		if(t[k+1][j]!=-1)
			right= t[k+1][j];
		else
			right = partation(s,k+1,j);
			t[k+1][j]  = right;
		
		int temp = 1+left+right;
		mini = min(mini,temp);
	}
	return t[i][j] = mini;
}
int main()
{
	memset(t,-1,sizeof(t));
	string s = "aaaabbsspoorvibbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbssddasdfas";
	cout<<partation(s,0,s.size()-1)<<endl;
}
