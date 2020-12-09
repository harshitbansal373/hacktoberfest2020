#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n,a,b;
  cin >> n >> a >> b;
  lli count = 0;
  floop(i,0,n-a){
    if(i < b+1) count++;
  }
  cout << count;
  return 0;
}
