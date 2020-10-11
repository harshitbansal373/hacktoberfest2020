#include <iostream>//ini merupakan perintah preprocessor directive
using namespace std;

int main()//Script ini menjadi awal dan akhir dari eksekusi program
{

	int i,j,n,c;/*int atau integer Variable jumlah digunakan untuk menampung nilai.
               i,j,n,c. Digunakan dalam melakukan perulangan agar bisa terbentuk pola bintang yang diinginkan*/
    //melakukan input untuk looping
    cout << "Masukkan panjang segitiga: ";//cout ini berfungsi untuk menampilkan sebuah data/statment pada saat program dijalankan
    cin >> n;//memasukan yg telah di input ke variabel

    //Melakukan Looping untuk pola 1
  	cout << "\nPola 1\n";
    for (i=1;i<=n;i++) {
        for (j=1;j<=i;j++) {
            cout << "*";
        }
        cout << endl;//endl ini berfungsi untuk berpindah baris ( enter ) saat program di jalankan
  }
 //Melakukan Looping untuk pola2
    cout << "\nPola 2\n";
    for (i=1;i<=n;i++) {
        for (j=i;j<=n;j++) {
            cout << "*";
        }
        cout << endl;
    }
     //Melakukan Looping untuk pola 3
  cout <<"\nPola 3\n";
  for (i=1;i<=n;i++) {
        for (j=i;j<n;j++) {
            cout << " "; // Looping segitiga kiri atau spasi
        }
         
        for (j=1;j<=i;j++) {
            cout << "*"; // Looping segitiga kanan
        }
        cout << endl;
    }
    //Melakukan Looping untuk pola4
 cout <<"\nPola 4\n";
  for (i=1;i<=n;i++) {
        for (j=i;j<n;j++) {
            cout << " "; 
        }
         
        for (j=1;j<=i;j++) {
            cout << "*"; 
        }
        for (j=2;j<=i;j++) {
            cout << "*";
        }
        cout << endl;

}


     //Melakukan Looping untuk pola 5
    cout << "\nPola 5\n";
  for (i=1;i<=n;i++)
 {
  j=1;
  for (j=1;j<=n;j++)
  {
   if(j<=i)
   {
    cout<<"*";
   }else{
    cout<<" ";
   }
  }
  for (c=n-1;c>0;c--)
   {
   if(c<=i){
    cout<<"*";
   }else{
    cout<<" ";
   }
    }
  cout<<endl;
 }
cout << "\n";
cout << "KOTAK\n";
for (i = 1; i <= n; i++){
  for (j = 1; j <= n; j++)
  {
   cout << "*";
  }
cout << " " << endl;
}
 //Copyright wkwkwk
  cout << "Habieb Fathur Rahman"<<endl;
  cin.get();
	return 0;
  }
    	
    