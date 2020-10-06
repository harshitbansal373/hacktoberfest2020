/*
This problem was asked in Amazon interview.
Given an array of integers and you can jump from index to and index either left or right by the current value of the index. For example - if you have something like [3,2,4,1,5]. So from index[4] i.e val = 1, I can take a left and come to 4 or come to 5 (jumping 1 in either direction). Now, given a start and end point we need to find the smallest number of steps to reach the end point.
*/
// BFS Approach
#include<bits/stdc++.h>
using namespace std;
#define loop1(size) for(int i=0;i<size;i++)
void fun1(vector<int> v,int start,int dst)
{
		int size=v.size();
		vector<int> temp(size,INT_MAX);
		temp[start]=0;
		queue<pair<int,int> > q;
		q.push({start,0});
		int res=INT_MAX;
		temp[start]=0;
		while(!q.empty())
		{
			int s=q.size();
			for(int i=0;i<s;i++)
			{
				pair<int,int> p1=q.front();
				q.pop();
				int pos=p1.first;
				int steps=p1.second;
				cout<<"pos value : "<<v[pos]<<" steps : "<<steps<<"\n";
				if(pos==dst)
				{
					res=min(res,steps);
					continue;
				}
				if(steps>temp[pos]) continue;
				temp[pos]=steps;
				int next_pos1=pos+v[pos];
				int next_pos2=pos-v[pos];
				if(next_pos1<size)
					q.push({next_pos1,steps+1});
				if(next_pos2>=0)
					q.push({next_pos2,steps+1});
			}
		}
		if(res==INT_MAX)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<res<<"\n";
}
int main()
{
		vector<int> v;
		int size,val,start,dst;
		cout<<"ENTER SIZE : ";
		cin>>size;
		loop1(size)
		{
			cin>>val;
			v.push_back(val);
		}
		cout<<"ENTER START POS : ";
		cin>>start;
		cout<<"ENTER DESTINATION : ";
		cin>>dst;
		fun1(v,start,dst);
		int in;
		cin>>in;
}
