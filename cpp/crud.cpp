#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Karyawan {
	int pk;
	string Archivment;
	string nama;
	string ID;
};
// &data adalah reference

// All Function
int getOption();
void checkDatabase(fstream &data);
void writeData(fstream &data, int posisi, Karyawan &inputKaryawan);
int getDataSize(fstream &data);
Karyawan readData(fstream &data, int posisi);
void addDataKaryawan(fstream &data);
void displayDataKaryawan(fstream &data);
void updateRecord(fstream &data);
void deleteRecord(fstream &data);

int main() {

	// Input data
	fstream data; // nama file eksternal
	checkDatabase(data);

	// pengambilan data 
	int userInput = getOption();
	char isContinue;

	// Choice
	enum option{CREATE = 1,READ,UPDATE,DELETE,FINISH};	

	while(userInput != FINISH){		

		switch(userInput){
			case CREATE:
				cout << "Menambah data karyawan Bank" << endl;
				// untuk menyambungkan ke-fungsi
				addDataKaryawan(data);
				break;
			case READ:
				cout << "Tampilkan data karyawan Bank" << endl;
				// untuk menampilkan data
				displayDataKaryawan(data);
				break;
			case UPDATE:
				cout << "Ubah data karyawan Bank" << endl;
				displayDataKaryawan(data);
				updateRecord(data);
				displayDataKaryawan(data);
				break;
			case DELETE:
				cout << "Hapus data karyawan Bank" << endl;
				displayDataKaryawan(data);
				deleteRecord(data);
				displayDataKaryawan(data);
				break;
			default:
				cout << "Pilihan tidak ada" << endl;
				break;
		}

		// Statemant untuk user ingin lanjut / tidak
		// label_continue untuk mengulang suatu program/controrflow 
		// selain continue & break
		label_continue:

		cout << "Lanjutkan (y/n) :";
		cin >> isContinue;
		if (isContinue == 'y' || isContinue == 'Y'){
			// Untuk mengupdate ulang CRUD
			userInput = getOption();
		} else if (isContinue == 'n' || isContinue == 'N') {
			break;
		} else {
			// untuk mengulang suatu program. ControlFlow
			goto label_continue;
		}

	}

	cout << "Akhir program" << endl;

	cin.get();
	return 0;
}

// Function untuk menampilkan pilihan
int getOption(){
	int input;
	// system disini diambil dari iostream
	system("cls");
	cout << "\nProgram CRUD Data Karyawan Bank" << endl;
	cout << "=================================" << endl;
	cout << "1.Tambah data karyawan Bank" << endl;
	cout << "2.Tampilkan data karyawan Bank" << endl;
	cout << "3.Ubah data karyawan Bank" << endl;
	cout << "4.Hapus data karyawan Bank" << endl;
	cout << "5.SELESAI." << endl;
	cout << "=================================" << endl;
	cout << "Pilih (1-5)?";
	cin >> input;
	// ignore adalah fungsi untuk mereset enter dan untuk menjalankan getline nya
	cin.ignore(1,'\n');
	return input;
}


// Function untuk menambahkan data
void addDataKaryawan(fstream &data) {

	Karyawan inputKaryawan, lastKaryawan;

	int size = getDataSize(data);

	cout << "Ukuran data :" << size << endl;
		
	if (size == 0){
		inputKaryawan.pk = 1;
	} else {
		lastKaryawan = readData(data, size);
		inputKaryawan.pk = lastKaryawan.pk + 1;
	}

	// readData(data,size); 

	cout << "Nama :";
	getline(cin, inputKaryawan.nama);
	cout << "ID :";
	getline(cin, inputKaryawan.ID);
	cout << "Archivment :";
	getline(cin, inputKaryawan.Archivment);
	//fungsi size + 1 adalah untuk meletakkan nya dibawah 
	writeData(data,size + 1,inputKaryawan);
}
	
// Function membuat data
void writeData(fstream &data, int posisi, Karyawan &inputKaryawan) {
	// untuk mencari posisi
	data.seekp((posisi - 1)*sizeof(Karyawan),ios::beg); 
	data.write(reinterpret_cast<char*>(&inputKaryawan),sizeof(Karyawan));
}

// Fungsi untuk memeriksa data agar bisa ditampilkan
int getDataSize(fstream &data) {
	int start,end;
	// seek gunanya untuk membaca saja kalau seekg utk mengetahui posisi
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0, ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Karyawan);
}
	
// Function untuk membaca data dari write data
Karyawan readData(fstream &data, int posisi){
	Karyawan readKaryawan;
	data.seekg((posisi - 1)*sizeof(Karyawan),ios::beg);
	data.read(reinterpret_cast<char*>(&readKaryawan),sizeof(Karyawan));
	return readKaryawan;
}

// Function untuk menampilkan hasil
void displayDataKaryawan(fstream &data) {
	int size = getDataSize(data);
	Karyawan showKaryawan;
	cout << "No.\tPK.\tNama.\tID.\tArchivment." << endl; 
	for(int i = 1; i <= size; i++){
	showKaryawan = readData(data,i);
	cout << i << "\t";
	cout <<	showKaryawan.pk << "\t";
	cout <<	showKaryawan.nama << "\t";
	cout <<	showKaryawan.ID << "\t";
	cout <<	showKaryawan.Archivment << endl;
	}
}

// function untuk membuat data 
void checkDatabase(fstream &data){

	// memanggil isi data sebelum diisi
	data.open("data.bin", ios::out | ios::in | ios::binary);

	// cek/alur file data ada atau tidak is_open adalan method yang ada di fstream
	if (data.is_open()) {
		cout << "Database tidak ditemukan" << endl;
	} else {
		cout << "database tidak ditemukan, buat database baru" << endl;
		data.close();
		// menambahkan data baru 
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

void updateRecord(fstream &data){
	int nomor;
	Karyawan updateKaryawan;
	cout << "Pilih Nomor :";
	cin >> nomor;
	cin.ignore(1,'\n');

	updateKaryawan = readData(data,nomor);
	
	cout << "\nPilihan Data :" << endl;
	cout << "Nama :" << updateKaryawan.nama << endl;
	cout << "ID :" << updateKaryawan.ID << endl;
	cout << "Archivment :" << updateKaryawan.Archivment << endl;

	cout << "\nMerubah data" << endl;
	cout << "Nama :";
	getline(cin,updateKaryawan.nama);
	cout << "ID :";
	getline(cin,updateKaryawan.ID);
	cout << "Archivment :";
	getline(cin,updateKaryawan.Archivment); 

	writeData(data,nomor,updateKaryawan);
}

void deleteRecord(fstream &data){	
	int nomor,size,offset;
	Karyawan blankKaryawan, tempKaryawan;
	fstream dataSementara;

	size = getDataSize(data);
	// 1.pilih nomor
	cout << "Pilih nomor :";
	cin >> nomor;
	// 2.diisi data kosong
	writeData(data,nomor,blankKaryawan);
	// 3.cek data yang ada dari data.bin, 
	// kalau ada data kita pindahkan ke file sementara
	dataSementara.open("temp.dat",ios::trunc|ios::out|ios::in|ios::binary);

	offset = 0;

	for(int i=1; i <=size ; i++){
		tempKaryawan = readData(data,i);

		if(!tempKaryawan.Archivment.empty()){
			writeData(dataSementara,i - offset,tempKaryawan);
		} else {
			offset++;
			cout << "Deleted data :" << endl;
		}
	}

	// 4. kita pindahkan dari file sementara ke data.bin
	size = getDataSize(dataSementara);
	data.close();
	data.open("data.bin", ios::trunc|ios::out|ios::binary);
	data.close();
	data.open("data.bin",ios::out|ios::in|ios::binary);

	for(int i = 1; i <= size; i++) {
		tempKaryawan = readData(dataSementara,i);
		writeData(data,i,tempKaryawan);
	}	
}



