#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int k) {
	if(k==1) {
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	solve(s,k-1);
	s.push(temp);
}

void print(stack<int> s) {
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

int main() {
	stack<int> s,temp;
	int k;
	s.push(6);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	temp=s;
	cout<<"Before deleting middle element\n";
	print(temp);
	k = s.size()/2 + 1;
	solve(s,k);
	cout<<"After deleting middle element\n";
	print(s);
	return 0;
}
