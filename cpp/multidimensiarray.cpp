#include <iostream>
using namespace std;

void printArray(int *ptrArray, int baris, int kolom){
	int index = 0;
	for(int i = 0; i < baris; i++){
		cout << "[ ";
		for(int j = 0; j < kolom; j++){
			cout << (*ptrArray + index) << " ";
			index++;		
		}
		cout << "]" << endl;
	}
}

int main(){

	// arrayMultidimensi
	// array [baris ][kolom]
	// note : baris dan kolom diarray harus konstan

	const int baris = 5;
	const int kolom = 2;
	int arrayMD[baris][kolom] = {};

	printArray(*arrayMD, baris, kolom);
	cin.get();
	return 0;
}
