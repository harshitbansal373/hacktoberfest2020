#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ll t;
cin>>t;
while(t--)

{
	ll n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	int max_far=0,max_end=0,tr=-10000000;
	for(int i=0;i<n;i++)
	{
		max_end+=a[i];
		if(max_end<0)
		{
		if(max_end>tr)
		tr=max_end;
		max_end=0;
	}
		if(max_far<max_end)
		max_far=max_end;
	}
	if(max_far==0)
	cout<<tr<<"\n";
	else
	cout<<max_far<<"\n";
	}	return 0;
}
