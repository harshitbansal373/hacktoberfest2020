#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main() { string s1,s2;
 cout<<"Enter the string 1 \n";
 cin>>s1;
 cout<<"Enter the string 2 \n";
 cin>>s2;
 sort(s1.begin(), s1.end()); 
        sort(s2.begin(), s2.end()); 
        if(s1==s2)
            cout<<"string 2 is an anagram of string 2 \n";
        else
        cout<<"string 2 is not an anagram of string 1 \n";
	return 0;
}
