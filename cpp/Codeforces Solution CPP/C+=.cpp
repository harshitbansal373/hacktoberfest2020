#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli t;
  cin >> t;
  floop(i,0,t){
    lli a, b, n;
    cin >> a >> b >> n;
    lli sum = a+b;
    lli count = 1;
    while(sum <= n){
      sum += max(a,b);
      if(min(a,b) == a) a += b;
      else b += a;
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
