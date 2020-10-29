#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli t;
  cin >> t;
  floop(i,0,t){
    lli a, b;
    cin >> a >> b;
    if(max(a,b) > 2*min(a,b)) cout << max(a,b)*max(a,b) << endl;
    else cout << 4*min(a,b)*min(a,b) << endl; 
  }
  return 0;
}
