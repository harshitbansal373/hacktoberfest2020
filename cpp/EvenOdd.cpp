#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    if ( n % 2 == 0) //function to check even
        cout << n << " is even.";
    else//function to check odd
        cout << n << " is odd.";
    return 0;
}
