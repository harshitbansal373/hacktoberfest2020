//job sequencing in CPP

#include<bits/stdc++.h>
using namespace std;

// define the class for the job
class job
{
	public:
		int jobid;
		int deadline;
		int profit;
};
// our compare function to sort
bool mycompare(job *x,job *y)//boolean function
{
	//sort as per decreasing profit
	return x->profit>y->profit; 
}

int maxProfit(job** obj,int n){
	int max=0,profit=0;;
	//find maximum deadline
	for(int i=0;i<n;i++){
		if(i==0){
			max=obj[i]->deadline;
		}
		else{
			if(obj[i]->deadline>max)
				max=obj[i]->deadline;
		}
	}
	
	sort(obj,obj+n,mycompare);
	// create array of max deadline size
	int store[max]={0};	// empty array initially
	bool slot[max]={false}; //all slots empty initially
	for(int i=0;i<n;i++)
	{	
		// now pick the job with max deadline and from 
		// that deadline traverse array back to find an empty slot
		for(int j=(obj[i]->deadline)-1;j>=0;j--)
		{
			if(slot[j]==false)	// slot is empty
			{	
				// count the total profit
				profit+=obj[i]->profit;
				store[j]=obj[i]->jobid;
				slot[j]=true;
				break;
			}
		}
	}
	// printing the job sequence
	cout<<"jobs sequence is:"<<"\t";
	for(int i=0;i<max;i++)
	{	
		if(slot[i])
			cout<<store[i]<<"  ";
	}
	return profit; //return profit
}

int main()
{	
	int n,size,max,totalprofit=0;
	cout<<"enter the no. of jobs:";
	cin>>n;
	job *obj[n]; //array of pointer to jobs(jobs namely) 
	// user input and finding maximum deadline
	for(int i=0;i<n;i++)
	{	
		obj[i]=(job*)malloc(sizeof(struct job));
		cout<<"enter jobid,deadline and profit of job "<<i+1<<endl;

		cin>>obj[i]->jobid;
		cin>>obj[i]->deadline;
		cin>>obj[i]->profit;
	}

	totalprofit=maxProfit(obj,n); //total profit
	cout<<"\ntotal profit is "<<totalprofit<<"\n";
	
	return 0;	
}
