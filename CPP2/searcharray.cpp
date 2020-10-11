#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

const size_t arraySize = 10;

void printArray(array < int, arraySize> &angka){ // fungsi array
	cout << "Array :";
	for(int &a : angka){ // pengulangan untuk array
		cout << a << " ";
	}
	cout << endl;
}

int main() {

	array <int, arraySize> angka = {9,8,7,6,5,4,3,2,1,0}; // isi dari array
	printArray(angka); // fungsi print array

	int angkaCari; // tipe data untuk mencari array 
	bool ketemu; //tipe data untuk memberi tahu angka ketemu atau tidak
	// sort terlebih dahulu
	// search -> binary_search

	cout << "Mencari angka dalam array :";
	cin >> angkaCari;
	sort(angka.begin(), angka.end()); // untuk mensorting agka di array
	ketemu = binary_search(angka.begin(), angka.end(), angkaCari); // untuk mencari angka yang dicari

	if(ketemu){ // fungsinya jika angka yg dicari ketemu maka akan menampilkan angka ketemu
		cout << "Angka yang anda cari ketemu, apakah ini hasil nya? : " << angkaCari << endl;
	}else{ // fungsi jika angka tidak ketemu maka akan menampilkan angka tidak ketemu
		cout << "Angka yang anda cari tidak ada disini!" << endl;
	}

	cin.get();
	return 0;
}