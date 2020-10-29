#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli t;
  cin >> t;
  floop(i,0,t){
    lli n,k;
    cin >> n >> k;
    lli input[n];
    floop(j,0,n) cin >> input[j];
    lli maxm = 0;
    floop(j,0,n) maxm = max(maxm,input[j]);
    lli minm = maxm;
    floop(j,0,n){
      if(input[j] != 0) minm = min(minm,input[j]);
    }
    lli pos = n;
    floop(j,0,n){
      if(input[j] == minm){
        pos = j;
        break;
      }
    }
    lli count = 0;
    floop(j,0,n){
      if(j != pos) count += (k-input[j])/minm;
    }
    cout << count << endl;
  }
  return 0;
}
