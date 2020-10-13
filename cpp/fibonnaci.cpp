#include <iostream>

using namespace std;

int main() {

	// rumus = f_n = f_n1 + f_n2

	int n,f_n,f_n1,f_n2; // penentuantipe data

	cout << "Program Deret Fibonnaci \n";
	cout << "Masukkan nilai ke-n :";
	cin >> n;

	f_n2 = 0; // nilai awal 
	f_n1 = 1; // nilai kedua
	cout << "Nilai pertama : " << f_n2 << endl;; 
	cout << "Nilai Kedua : " << f_n1 << endl;
	cout << endl;

	for(int i = 1; i < n; i++){ // looping dimulai dari 1
		f_n = f_n1 + f_n2; // pengaturan nilai awal dan kedua rumus nya c = (a+b)
		f_n2 = f_n1; // lalu a = b
		f_n1 = f_n; // dan terakhir b = c
		cout << "Nilai fibonnaci : " << f_n << endl; // dan ini output nya
	}

	cout << endl;

	system("pause"); // untuk menimbulkan alert

	cin.get();
	return 0;
}
