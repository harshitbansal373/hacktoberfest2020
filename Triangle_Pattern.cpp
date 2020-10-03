#include <iostream>

using namespace std;

int main() {

    int i,j,n;
    
    cin>>n;
    
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=i;j--)
            cout<<" ";
        cout<<"*";
        
        if(i!=n)
        {
            for(j=i-1;j>=1;j--)
                cout<<" ";
            
            for(j=i-2;j>=1;j--)
                cout<<" ";
        }  
        else
        {
            for(j=n*2-3;j>=1;j--)
                cout<<"*";
        }
        
        if(i!=1)
            cout<<"*";
        
        cout<<endl;
    }
    return 0;
}