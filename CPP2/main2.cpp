#include <iostream>
#include <math.h>

using namespace std;

int main(){

	int n, pencacah,nilaiPi, total;

	cout << "Masukkan nilai : ";
	cin >> n;

	total = 1;
	pencacah = 2;

	total = total + 0.1 / (pencacah ^ 2);
	nilaiPi = sqrt(6*total);
	
	cout << "nilai Pi : " << nilaiPi << endl;

	cin.get();
	return 0;
}