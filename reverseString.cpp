//A simple program to reverse a given string.

#include<iostream>
#include<string>
using namespace std;
string revStr(string s) {
	for (int i=0;i<s.size()/2;i++) {
  	char c = s[i];
    s[i] = s[s.size()-1-i];
    s[s.size()-1-i] = c;
  }
  return s;
}

int main() {
	cout << "Enter a string you wish to reverse." << endl;
  string s;
  cin >> s;
  string t = revStr(s);
  cout << "The reversed string is " << t << endl;
}
