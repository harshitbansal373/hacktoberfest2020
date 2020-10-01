#include<bits/stdc++.h>
#define ll long long

int findMinXor(vector<int> &A) 
{
    sort(A.begin(),A.end());
    ll mini=A[0]^A[1];
    for(ll i=1;i<A.size()-1;i++)
    {
        ll p=A[i]^A[i+1];
        mini=min(mini,p);
    }
    return int(mini);
}

int main()
{
  vector<int> A{5,2,7,3,1,4,9};
  cout<<findMinXor(A);
  return 0;
}
