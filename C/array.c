double *aritmatik(int *data, int panjang) ;



 #include<stdio.h>

 int main( int argc, char *argv[])
 {

    int *baris,i;
    double *hasilHitung;

    int angka[] = {1,2,3,4,6} ;
    printf("Angka : ")   ;
    for (i=0; i < 5; i++) {
        printf("%d ",angka[i]);
    }
    baris = angka;


    hasilHitung = aritmatik(baris,5);
    printf("\nJumlahnya adalah : %.1f \n", *hasilHitung);
    printf("Rata-rata adalah : %.2f \n", *(hasilHitung+1));

 return 0  ;
 }


double *aritmatik(int *data, int panjang)
{
    int i, jum;
    double rata, djum;
    jum = 0; rata = 0;
    for(i=0;i<panjang;i++){
        jum += *(data+i);
    }
    rata = (double)jum/panjang ;
    djum= (double)jum;
    static double hasil[2];
    hasil[0] = djum;
    hasil[1] = rata;
    return hasil ;
    }
