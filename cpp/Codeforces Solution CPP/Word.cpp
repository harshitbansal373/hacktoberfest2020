#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  string s;
  cin >> s;
  lli num_upper = 0;
  floop(i,0,s.length()){
    floop(j,65,91){
      if(s[i] == j) num_upper++;
    }
  }
  if(num_upper > s.length()-num_upper){
    floop(i,0,s.length()){
      floop(j,97,123){
        if(s[i]==j) s[i] -= 32;
      }
    }
  }
  else{
    floop(i,0,s.length()){
      floop(j,65,91){
        if(s[i] == j) s[i] += 32;
      }
    }
  }
  cout << s;
  return 0;
}
