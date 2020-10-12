#include <iostream>

using namespace std;
int main(){
int a;
cout<<"Enter total no. of values e.g 10,20,30 etc"<<endl;
cin>>a;
float n[a];
cout<<"Enter values"<<endl;
for(int i=0;i<a;i++){
	cin>>n[i];
	cout<<endl;
	
}
cout<<"Same values with Voltage unit. Copy and paste in word table"<<endl;
for(int i=0;i<a;i++){
	cout<<n[i]<<"V"<<endl;}

for(int i=0;i<a;i++){
	
	n[i]*=0.707;
}
cout<<"RMS values with Voltage unit. Copy and paste in word table"<<endl;

for(int i=0;i<a;i++){
	cout<<n[i]<<"V"<<endl;
}


return 0;
}
