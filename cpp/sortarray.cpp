#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const size_t arraySize = 10; // menentukan berapa banyak isi dari array

// mensortir array angka
void printArray(array < int, arraySize> &angka){ // mengambil adress dari angka
	cout << "Array : ";
	for(int &a : angka){ // menyamakan adress a dengan angka / looping untuk array
		cout << a << " ";
	}
	cout << endl;
}

// mensortir array huruf
void printArray(array < char, arraySize> &huruf){ // mengambil adress dari huruf 
	cout << "Array : ";
	for(char &a : huruf){ // menyamakan adress a dengan huruf / looping untuk array
		cout << a << " "; 
	}  
	cout << endl;
}

int main(){

	array <int, arraySize> angka = {9,8,7,6,5,4,3,2,1,0};
	array <char, arraySize> huruf = {'c','f','g','h','i','a','b','k','l','m'};

	// nilai sebelum disortir
	printArray(angka); 
	printArray(huruf);

	cout << endl;

	// nilai setelah disortir
	sort(angka.begin(), angka.end());
	printArray(angka);

	sort(huruf.begin(), huruf.end());
	printArray(huruf);
	
	cin.get(); 
	return 0;
}
