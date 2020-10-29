#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli input[5];
  floop(i,0,5) cin >> input[i];
  lli sum = 0;
  floop(i,0,5) sum += input[i];
  if(sum%5 != 0 || sum == 0) cout << -1;
  else cout << sum/5;
  return 0;
}
