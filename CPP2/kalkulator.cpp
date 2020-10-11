#include <iostream>
using namespace std;

int main ()
{
	float a,b,hasil;
	char aritmatika;

	cout << "Selamat Datang Di Kalkulator Saya \n \n";
	
	//Memasukan input dari user
	cout << "Masukan Nilai Pertama = ";
	cin >> a;
	cout << "Pilih Operator = +,-,/,x = ";
	cin >> aritmatika;
	cout << "Masukan Nilai Kedua = ";
	cin >>b;

	cout << "\n Hasil Perhitungan  = ";
	cout << a << aritmatika << b;

	if (aritmatika == '+'){
	  hasil = a + b;
	} else if (aritmatika == '-'){
	  hasil = a - b;
	}else if (aritmatika == '/'){
	  hasil = a / b;
	}else if (aritmatika == 'x'){
	  hasil = a * b;
	} else {
		cout << "operator tidak ditemukan" << endl;
	}

	cout << '=' << hasil << endl;


	cin.get();
	return 0;
}cout << "Ingin Menghitung"<<endl;
		cout << "1. Diameter Lingkaran"<<endl;
		cout << "2. Keliling Lingkaran"<<endl;
		cout << "Masukan kode Pilihan Anda = ";
		cin >>pilih;
		if (pilih == 1)
		{
			a = 2;
			
		}