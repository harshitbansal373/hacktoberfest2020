#include <iostream>
#include <array>

using namespace std;

int main(){

	// looping untuk array dic++ 11 keatas
	/*
		for(deklarasi variable : array){
			stateman
		}
	*/
	// array <int, 10> arrayNilai; (sama saja dengan yang dibawah)
	int arrayNilai[10] = {0,1,2,3,4,5,6,7,8,9};

	for(int nilai : arrayNilai){
		cout << "Address : " << &nilai << " Nilainya : " << nilai << endl;
		nilai = 1; //tidak merubah array 
	} 

	cout << endl;
	// memanipulasi array dengan menggunakan referensi
	for(int &nilaiRef : arrayNilai){
		nilaiRef *= 2; // looping mempunyai jarak 2
	}

	cout << endl;

	for(int &nilaiRef : arrayNilai){
		cout << "Address :" << &nilaiRef << " Nilainya :" << nilaiRef << endl; 
	}

	cin.get();
	return 0;
}
