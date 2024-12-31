#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : Tabel.c*/
/* NIM/Nama : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal : 6, September 2024*/

 
/*KONSTRUKTOR*/				 
/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    // kamus lokal
    int i; //iterasi looping

    // algoritma
    (*T).size = 0;
    for (i = 1; i <= 10; i++){
        (*T).wadah[i] = -999;
    }
}

/*SELEKTOR*/
/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    // algoritma
    return T.size;
}

/*PREDIKAT*/
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    // algoritma
    return T.size == 0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    // algoritma
    return T.size == 10;
}

/*OPERASI PENCARIAN*/
/*function searchX (T:Tabel, X: integer) -> boolean
	{mencari elemen bernilai X dalam T.wadah dan mengembalikan index terkecilnya}*/
int searchX (Tabel T, int X){
    // kamus lokal
    int i; //iterasi loop

    // algoritma
    for(i = 1; i <= getSize(T); i++){
        if (T.wadah[i] == X){
            return i;
        } 
    }
    return 0;
}

/*function countX (T:Tabel, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah}*/
int countX (Tabel T, int X){
    // kamus lokal
    int i; //iterasi loop
    int temp; //menyimpan banyak elemen x

    // algoritma
    temp = 0;
    for(i = 1; i <= getSize(T); i++){
        if (T.wadah[i] == X){
            temp++;
        } 
    }
    return temp;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    //algoritma
    return 10 - getSize(T); 
}

/*MUTATOR*/
/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    if (!isFullTable(*T)){
        //algoritma
        (*T).wadah[getSize(*T) + 1] = X;
        (*T).size++;
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    // kamus lokal
    int found; //banyak elemen x dalam tabel

    // algoritma
    if(!isEmptyTable(*T)){
        found = searchX(*T, X);
        if (found != 0){
            for(found; found < getSize(*T); found++){
                (*T).wadah[found] = (*T).wadah[found + 1];
            }
            (*T).wadah[found] = -999;
            (*T).size--;
        }
    }   
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    // kamus lokal
    int basis; //menyimpan banyak elemen x
    int found; //mencari index elemen x

    // algoritma
    if(!isEmptyTable(*T)){
        basis = countX(*T, X);

        while (basis > 0){
            found = searchX(*T, X);
            if (found != 0){
                delXTable(T, X);
                basis--;
            }
        }
    }
}

/*OPERASI BACA/TULIS*/
/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    // kamus lokal
    int i; //iterasi loop

    // algoritma
    for (i = 1; i <= 10; i++){
        printf("%d\n", T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    int i; //iterasi loop

    // algoritma
    for (i = 1; i <= getSize(T); i++){
        printf("%d\n", T.wadah[i]);
    }
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    // kamus lokal
    int i; //iterasi loop
    int input; //input nilai dari keyboard

    // algoritma
    while(N > 0){
        scanf("%d", &input);
        addXTable(T, input);
        N--;
    }
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    // kamus lokal
    int N; //basis break while loop
    int input;

    // algoritma
    N = 1;
    while(N == 1){
        scanf("%d", &input);
        if(input > 0){
            addXTable(T, input);
        }
        else{
            N = 0;
        }
    }
}

/*OPERASI STATISTIK*/
/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    // kamus lokal
    int i; //iterasi loop
    int sum; //menyimpan jumlah elemen

    // algoritma
    sum = 0;
    for(i = 1; i <= getSize(T); i++){
        if(T.wadah[i]){
            sum += T.wadah[i];
        }
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
float AverageEl (Tabel T){
    // kamus lokal
    float max; //total semua elemen
    float size; //banyak elemen yang ada
    float x; //menyimpan hasil pembagian

    // algoritma
    x = 0;
    max = SumEl(T);
    size = getSize(T);
    if(!isEmptyTable(T)){
        x =  max / size;
    }
    return x;
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    // kamus lokal
    int max; //menyimpan nilai maksimal
    int i; //iterasi loop
 
    // algoritma
    max = 0;
    for(i = 1; i <= getSize(T); i++){
        if(T.wadah[i] > max){
            max = T.wadah[i];
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){
    // kamus lokal
    int min; //menyimpan nilai terkecil
    int i; //menyimpan iterasi loop

    // algoritma
    min = T.wadah[1];
    for(i = 2; i <= getSize(T); i++){
        if(T.wadah[i] < min){
            min = T.wadah[i];
        }
    }
    return min;
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    // kamus lokal
    int max; //banyak elemen x muncul
    int temp; //elemen x
    int i; //iterasi loop 

    // algoritma
    max = 0;
    temp = 0;
    for(i = 1; i <= getSize(T); i++){
        if(countX(T ,T.wadah[i]) > max){
            max = countX(T ,T.wadah[i]);
            temp = T.wadah[i];
        }
    }
    return temp;
}

/*OPERASI PENGURUTAN*/
/*procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terkecil hingga nilai terbesar}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terkecil hingga nilai terbesar}*/
void sortAsc (Tabel *T){
    // kamus lokal
    int i;
    int j;
    int temp;
    //algoritma
    for(i = 1; i <= (getSize(*T) - 1); i++){
        for(j = (i + 1); j <= getSize(*T); j++){
            if((*T).wadah[i] > (*T).wadah[j]){
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            } 
        }
    }
}

/*procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari nilai terbesar hingga nilai terkecil}
	{Proses: mengurutkan elemen dalam T.wadah dari nilai terbesar hingga nilai terkecil}*/
void sortDesc (Tabel *T){
    // kamus lokal
    int i;
    int j;
    int temp;
    //algoritma
    for(i = 1; i <= (getSize(*T) - 1); i++){
        for(j = (i + 1); j <= getSize(*T); j++){
            if((*T).wadah[i] < (*T).wadah[j]){
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            } 
        }
    }
}

#endif