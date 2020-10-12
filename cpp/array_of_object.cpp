#include<iostream>
using namespace std;

class Employee
{
 int Id;
 char Name[25];

 public:
	
	void GetData()//Statement 1 : Defining GetData()
	{
 		cout<<"\n\tEnter Employee Id : ";
 		cin>>Id;
		cout<<"\n\tEnter Employee Name : ";
 		cin>>Name;
	}

	void PutData()//Statement 2 : Defining PutData()
	{
		cout<<"\n"<<Id<<"\t"<<Name;
	}

};

int main()
{
 int i;
 Employee E[3];//Statement 3 : Creating Array of 3 Employees

for(i=0;i<2;i++)
{
   cout<<"\nEnter details of "<<i+1<<" Employee";
   E[i].GetData();
}
 cout<<"\nDetails of Employees";
 for(i=0;i<2;i++)
 E[i].PutData();
 return 0;

}
