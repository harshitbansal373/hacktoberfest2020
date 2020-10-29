#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  floop(i,0,n){
    lli x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(y2-y1 != 0 && x2-x1 != 0) cout << abs(y2-y1) + abs(x2-x1) + 2 << endl;
    else cout << abs(y2-y1) + abs(x2-x1) << endl;
  }
  return 0;
}
