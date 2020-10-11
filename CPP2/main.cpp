#include <iostream>
using namespace std;

// prototype
void title(void);

int main(){

	title();

	int n,pencacah,nilaiSuku; // tipe data yang digunakan

	cout << "Masukkan nilai : "; // user melakukan inputan
	cin >> n;

	nilaiSuku = 1;

	for(pencacah = 1; pencacah < n; pencacah++){ // looping
		if(pencacah % 2 == 0){ // stateman output bilangan negatif positif
			cout << "Nilai Suku Negatif : " << -nilaiSuku << endl;
		}else{
			cout << "Nilai Suku Positif : " << nilaiSuku << endl;
		} 
		nilaiSuku += 3; // menambah 2 agar bilangan mempunyai 2 selisih
	}

	cin.get();
	return 0;
}

void title(void) {
	cout << "=============================\n";
	cout << "Program Deret Positif Negatif\n";
	cout << "=============================\n" << endl;
}
