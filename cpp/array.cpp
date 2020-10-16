#include <iostream>
#include <array>

using namespace std;

int main(){
	
	// membuat array dengan menggunakan std library

	array < int, 5 > nilai;

	for(int i = 0; i <= 4; i++){
		nilai[i] = i;
		cout << "nilai {" << i << "} = " << nilai[i] << endl;
		cout << "Address :" << &nilai[i] << endl; 
	}

	cout << '\n';
	// ukuran array
	cout << "Ukuran :" << nilai.size() << endl;
	// Adress awal array
	cout << "Adsress Awal :" << nilai.begin() << endl;
	// Address akhir array
	cout << "Address Akhir :" << nilai.end() << endl;
	cout << "nilai ke-n :" << nilai.at(3) << endl; 

	cin.get();
	return 0;
}
