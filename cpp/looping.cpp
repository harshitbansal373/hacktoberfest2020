#include <iostream>
using namespace std;

int main() {

	int a;

	cout << "Masukkan Nilai : ";
	cin >> a;

	for( int i = 0; i <= a; ++i ){

		for ( int b = 0; b < i; b++ ){

			cout << "*" << endl;
		}

		cout << " " << endl;
	}



	return 0;
	cin.get();

}
