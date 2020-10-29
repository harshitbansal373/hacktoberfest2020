#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int check_palindrome(string s){
  lli count = 0;
  floop(i,0,s.length()/2){
      if(s[i] == s[s.length()-1-i]) count++;
    }
  if(count == s.length()/2) return true;
  else return false;
}

int check(string s){
  lli count = 0;
  floop(i,0,s.length()-1){
    if(s[i] == s[i+1]) count++;
  }
  if(count == s.length()-1) return true;
  else return false;
}

int main(){
  string s;
  cin >> s;
  if(check(s) == true) cout << 0;
  else if(check(s) == false){
    if(check_palindrome(s) == true) cout << s.length()-1;
    else cout << s.length();
  }
  return 0;
}
