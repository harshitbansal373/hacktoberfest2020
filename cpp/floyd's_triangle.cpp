#include <iostream>
using namespace std;

int main()
{
    int n, i,  c, a = 1;
    
    cout << "Enter the number of rows of Floyd's triangle to print: "; cin >> n;
    
    for (i = 1; i <= n; i++)
    {
        for (c = 1; c <= i; c++)
        {        
            cout << a; 
            a++; 
        }
        cout << endl;
    }    
    return 0;
}
