#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  floop(i,0,n){
    lli x,y,n;
    cin >> x >> y >> n;
    cout << n-((n-y)%x) << endl;
  }
  return 0;
}
