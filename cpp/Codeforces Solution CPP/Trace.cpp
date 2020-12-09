#include<bits/stdc++.h>
#include<cmath>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a< c; a++)
using namespace std;
double value_pi(){
  return 2*acos(0.0);
}
int main(){
  lli n;
  cin >> n;
  lli input[n];
  floop(i,0,n) cin >> input[i];
  sort(input,input+n);
  lli squared_out = 0;
  lli squared_in = 0;
  for(lli i = n-1; i >= 0; i-=2) squared_out += (input[i])*(input[i]);
  for(lli i = n-2; i >= 0; i-=2) squared_in += (input[i])*(input[i]);
  cout << setprecision(10) << fixed << (squared_out-squared_in)*value_pi() << endl;
  return 0;
}
