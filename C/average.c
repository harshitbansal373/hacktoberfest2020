#include <stdio.h>
#include <string.h>

void rata_rata()
{
    printf("\n\t Program Menghitung Rata-rata \n");
}

struct a{
    char b[10];
};

main()
{
    float minimal[2]={5.1,10};  // Array
    int banyak, i;
    int *pj, jumlah=0;          // Pointer
    pj = &jumlah;
    float rata;
    int total;

struct a c ;                    // Struct
strcpy(c.b , "Lulus");          // String

rata_rata();                                        // Fungsi
    printf("\nMasukkan banyak nilai = ");
    scanf("%d", &banyak); printf("\n");

    for(i = 0; i < banyak; i++) {                   // For
        printf(" Masukkan nilai ke-%d = ", i+1);
        scanf("%d", &total);
        *pj += total;
    }
    rata = (float) *pj / banyak;

    printf("\n  Jumlah nilai = %d\n  Jumlah data = %d\n  Nilai rata-rata : %.1f\n", *pj, banyak, rata);

    if(rata<=5){                              // If
        printf("\n   Jadi nilai rata-rata Anda %.1f", rata);
        printf("\n   Anda Tidak %s \n", c.b);
        printf("\n   Untuk %s minimal nilai rata-rata harus %.1f \n", c.b, minimal[0]);
    }else if(rata<=10){
        printf("\n   Jadi nilai rata-rata Anda %.1f", rata);
        printf("\n   Anda %s \n", c.b);
    }else{
        printf("\n \t Program ini hanya untuk nilai rata-rata maksimal %.0f \n", minimal[1]);
    }
    return 0;
}
