#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  floop(i,0,n){
    lli x,y,a,b;
    cin >> x >> y >> a >> b;
    if((y-x)%(a+b) != 0) cout << -1 << endl;
    else cout << (y-x)/(a+b) << endl;
  }
  return 0;
}
