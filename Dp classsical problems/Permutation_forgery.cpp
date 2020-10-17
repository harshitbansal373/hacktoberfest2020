#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int n,a;
    cin>>n;
    vector<ll int>v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
   	int count=0;
   	int i=0,j=1;
   	while(j<=n)
   	{
   		
   		if(v[i]>0&&v[j]<0&&i<j)
   		{
   			 if(abs(v[j])<v[i])
                    {
                        v[i]=v[i]-abs(v[j]);
                        v[j]=0;
                        j++;
                        
                    }
                    else
                    {
                        v[j] = v[j]+v[i];
                        v[i]=0;
                        i++;
                    }
		}
		else
		{
			if(v[i]<0)
			{i++;
			}
			else if(v[j]>0)
			{
				j++;
			}
			else{
				i++;
				j=i+1;
			}
		}
	cout<<i<<" "<<j<<endl;
	}
    ll int sum=0;
    for(int i=0;i<n;i++)
    {
    	
        if(v[i]>0)
        {
            sum = sum+v[i];
        }
    }
    cout<<sum<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
        solve();
    }
    
}
