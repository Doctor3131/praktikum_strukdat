/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 13 September 2024*/
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include <stdlib.h>

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    // kamus lokal
    int i;
    int j;

    // algoritma
    for (i = 1; i <= 10;i++){
        for (j = 1; j <= 10; j++){
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return M.nbaris == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return M.nbaris == 10 && M.nkolom == 10;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    // kamus lokal
    int i;
    int j;

    // algoritma
    i = 1;
    j = 1;
    *row = -999;
    *col = -999;

    while (i <= M.nbaris){
        while (j <= M.nkolom){
            if (M.cell[i][j] == X){
                *row = i;
                *col = j;
                j = M.nbaris + 1;
                i = M.nkolom + 1;
            }
            j++;
        }
        i++;
        j = 1;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    // kamus lokal
    int i;
    int j;
    int temp;

    //algoritma 
    temp = 0;
    if (isEmptyMatriks(M)){
        return temp;
    }
    else{
        for (i = 1; i <= getNBaris(M);i++){
            for (j = 1; j <= getNKolom(M); j++){
                if (M.cell[i][j] == X){
                    temp++;
                }    
            }
        }
        return temp;
    }
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    // kamus lokal

    // algoritma
    if (!isFullMatriks(*M)){
        if ((*M).cell[row][col] == -999){
            (*M).cell[row][col] = X;
            if ((*M).nbaris < row){
                (*M).nbaris = row;
            }
            if ((*M).nkolom < col){
                (*M).nkolom = col;
            }
        }
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col){
    if (!isFullMatriks(*M)){
        (*M).cell[row][col] = X;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    // kamus lokal
    int i;
    int j;

    // algoritma versi 1 (memakai delX)
//     searchX(*M, X, &i, &j);
//     (*M).cell[i][j] = -999;

//     (*M).nbaris = 0;
//     (*M).nkolom = 0;
//     for (i = 1; i <= 10; i++){
//         for (j = 1; j <= 10; j++){
//             if ((*M).cell[i][j] != -999){
//                 if((*M).nbaris < i){
//                     (*M).nbaris = i;
//                 }
//                 if((*M).nkolom < j){
//                     (*M).nkolom = j;
//                 }
//             }
//         }
//     }
// }
    // algoritma versi 2 (tanpa delX)
    (*M).nbaris = 0;
    (*M).nkolom = 0;
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            if ((*M).cell[i][j] != -999){
                if((*M).cell[i][j] == X){
                    (*M).cell[i][j] = -999;
                }
                else{
                    if((*M).nbaris < i){
                        (*M).nbaris = i;
                    }
                    if((*M).nkolom < j){
                        (*M).nkolom = j;
                    }
                }
            }
        }
    }
}


/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    // kamus lokal
    int i;
    int j;
    int random;

    // algoritma
    for (i = 1; i <= x; i++){
        for (j = 1; j <= y; j++){
            random = rand() %100 + 1;
            addX(&(*M), random, i, j);
        }
    }
}


/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    // kamus lokal
    int i;
    int j;

    // algoritma
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if(i == j){
                (*M).cell[i][i] = 1;
            }
            else{
                (*M).cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    // kamus lokal
    int i;
    int j;
    int input;

    // algoritma
    i = 1;
    j = 1;

    while (i <= x){
        while (j <= y){
            scanf("%d", &input);
            addX(&(*M), input, i, j);
            j++;
        }
        i++;
        j = 1;
    }
}


/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    // kamus lokal
    int i;
    int j;

    // algoritma
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    // kamus lokal
    int i;
    int j;

    // algoritma
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            if (M.cell[i][j] != -999){
                printf("%d ", M.cell[i][j]);
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    // kamus lokal
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    if(M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nbaris; j++){
                addX(&new, M1.cell[i][j] + M2.cell[i][j], i, j);
            }
        }    
    }
    return new;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    if(M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nbaris; j++){
                addX(&new, M1.cell[i][j] - M2.cell[i][j], i, j);
            }
        }    
    }
    return new;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    if(M1.nkolom == M2.nbaris){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nbaris; j++){
                addX(&new, M1.cell[i][j] * M2.cell[j][i], i, j);
            }
        }    
    }
    new.nbaris = M1.nbaris;
    new.nbaris = M2.nkolom;
    return new;  
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    if(!isEmptyMatriks(M1)){
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nbaris; j++){
                editX(&new, M1.cell[i][j] * x, i, j);
            }
        }   
        new.nbaris = M1.nbaris;
        new.nkolom = M1.nkolom;
    }
    return new;  
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M){
    // kamus lokal
    int i;
    int j;
    int temp;

    // algoritma
    temp = 0;

    for (i = 1; i <= M.nbaris; i++){
        for(j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] != -999){
                temp += M.cell[i][j];
            }
        }
    }
    return temp;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M){
    // kamus lokal
    int i;
    int j;
    float total;

    // algoritma
    total = 0;

    for (i = 1; i <= M.nbaris; i++){
        for(j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] != -999){
                total++;
            }
        }
    }
    
    if (total == 0){
        return 0;
    }
    return getSumMatriks(M)/total;
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M){
    int i;
    int j;
    float max;

    // algoritma
    max = 0;

    for (i = 1; i <= M.nbaris; i++){
        for(j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] != -999){
                if (max == 0){
                    max = M.cell[i][j];
                }
                else{
                    if (M.cell[i][j] > max){
                        max = M.cell[i][j];
                    }

                }
            }
        }
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M){
    int i;
    int j;
    float max;

    // algoritma
    max = 0;

    for (i = 1; i <= M.nbaris; i++){
        for(j = 1; j <= M.nkolom; j++){
            if (M.cell[i][j] != -999){
                if (max == 0){
                    max = M.cell[i][j];
                }
                else{
                    if (M.cell[i][j] > max){
                        max = M.cell[i][j];
                    }

                }
            }
        }
    }
    return max;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    for (i = 1; i <= (*M).nbaris; i++){
        for(j = 1; j <= (*M).nkolom; j++){
            new.cell[j][i] = (*M).cell[i][j];       
        }
    }
    new.nbaris = (*M).nkolom;
    new.nkolom = (*M).nbaris;
    
    *M = new;
}



/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    int i;
    int j;
    Matriks new;

    // algoritma
    initMatriks(&new);

    for (i = 1; i <= (M).nbaris; i++){
        for(j = 1; j <= (M).nkolom; j++){
            new.cell[j][i] = (M).cell[i][j];       
        }
    }
    new.nbaris = (M).nkolom;
    new.nkolom = (M).nbaris;
    
    return new;
}
