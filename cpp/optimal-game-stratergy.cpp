#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  
  // for fast input/output
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll A[n];
	    for(ll i=0;i<n;i++){
	        cin>>A[i];
	    }
	    vector< vector<ll> > dp(n, vector<ll>(n));
      
      // if we only have length one then the maximum sum possible will be the given value at that index
	    for(ll i=0;i<n;i++){
	        dp[i][i] = A[i];
	    }
      
      // now we will check for the remaining length
	    for(ll i=2;i<=n;i++){
	        for(ll j=0;j<=(n-i);j++){
          
              // if we only have length 2 then maximum possible sum will be the max value at the extremes
	            if(i==2){
	                dp[j][j+i-1] = max(A[j],A[j+i-1]);
	            }
              
              // if length is more than 2 then we will have 2 choices
              // 1.) if we put the first value then we will get next turn to pick from the remaining elements which are 
              // either (A[i+1]......A[n-1]) or (A[i+2]......A[n]). As both players play optimally so we will get minimum of these two
              // 2.) if we put the last value then we will get next turn to pick from the remaining elements which are
              // either (A[i].....A[n-2]) or (A[i+1].....A[n-1]). As both players play optimally so we will get minimum of these two
              // and we will choose maximum of these two choices.
              // As both players are playing optimally, they will try to take such value which will maximise their sum and minimize the other player sum.
              // So thats why if we pick any element, and on the next turn we will get the min of what remains to choose from.
              else{
	                dp[j][j+i-1] = max(A[j]+min(dp[j+2][j+i-1], dp[j+1][j+i-2]), A[j+i-1]+min(dp[j][j+i-3], dp[j+1][j+i-2]));
	            }
	        }
	    }
	    cout<<dp[0][n-1]<<endl;
	}
	
	return 0;
}
