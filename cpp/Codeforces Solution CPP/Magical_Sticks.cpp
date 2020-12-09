#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli t;
  cin >> t;
  floop(i,0,t){
    lli n;
    cin >> n;
    if(n%2 == 0)  cout << n/2 << endl;
    else cout << (n+1)/2 << endl;
  }
  return 0;
}
