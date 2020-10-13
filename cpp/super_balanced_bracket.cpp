#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	string s;
	stack<char>stack1;
	stack<char>stack2;
	for(int i=0;i<t;i++)
	{
		cin>>s;
		ll leng=s.length();
		ll cnt=0;
		if(s[0]==')')
		{
			cout<<"0\n";
			
		}
		else
		{
		
		for(int i=0;i<leng/2;i++)
		{
			stack1.push(s[i]);
		}
		for(int i=leng-1;i>=leng/2;i--)
		{
			stack2.push(s[i]);
		}
		while (!stack1.empty()) {
			
			if(stack1.top()=='(' && stack2.top()==')')
			{
				cnt=cnt+2;
				
				stack1.pop();
				stack2.pop();
			}
			else if(stack1.top()==')' && stack2.top()=='(')
			{
				
				stack1.pop();
				stack2.pop();
			}
			else
			{
				stack1.pop();
				stack2.pop();
			}
		}
		cout<<cnt<<"\n";
	}
	}
	return 0;
	
}
