#include <iostream>
using namespace std;

int main() {

	int i,j,n,ping,u,loop;
	cout << "Masukkan angka loop :";
	cin >> loop;

	for(i = 0; i <= loop; i++) {
		for(j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "Masukkan nilai loop :";
	cin >> ping; 


	cin.get();
	return 0;
}
