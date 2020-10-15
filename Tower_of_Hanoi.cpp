#include <iostream>
using namespace std;
void tower(int n, char source, char dest, char aux){
	
	if(n==1)
	{
		cout << n << " from " << source <<" to " << dest << endl;
		return;
	}
	else {
		tower(n-1, source, aux, dest);

		cout << n << " from " << source << " to " << dest << endl;

		tower(n-1, aux, dest, source);
	}
}

int main(){
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;
	tower(n, 'A', 'C', 'B');

	return 0;

}
