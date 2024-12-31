/* File : list3.c */
/* Deskripsi : Realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 Siriel Wafa Nuriel fahri*/
/* Tanggal : 18/11/2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
// kamus lokal
    address P;

// algoritma
    P = (address)malloc(sizeof(Elm));
    if (P != NIL) {
        info(P) = E;
        next(P) = NIL;
        prev(P) = NIL;
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
// kamus lokal
    

// algoritma
    free(*P);
    *P = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
// kamus lokal
    

// algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) { 
// kamus lokal
    

// algoritma
    if (First(L) == NIL) {
        return true;

    } else {
        return false;
    }
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
// kamus lokal
    address P;

// algoritma
    P = First(L);
    printf("[ ");
    if (!IsEmptyList(L)) {
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != NIL);
    } else {
        printf("kosong ");
    }
    printf("]\n");
    
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
// kamus lokal
    address P;
    int temp;

// algoritma
    temp = 0;
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            temp++;
            P = next(P);
        } while (P != NIL);
    }
    return temp;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
// kamus lokal
    address P;

// algoritma
    P = Alokasi(V);
    if (First(*L) != NIL) {
        next(P) = First(*L);
        prev(First(*L)) = P;
    }
    First(*L) = P;
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
// kamus lokal
    address P;
    address temp;

// algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (First(*L) == NIL) {
            First(*L) = P;
        } else {
            temp = First(*L);
            while(next(temp) != NIL){
                temp = next(temp);
            }
            next(temp) = P;
            prev(P) = temp;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
// kamus lokal
    address P;

// algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (next(P) == NIL && prev(P) == NIL) {
            First(*L) = NIL;
        } else {
            First(*L) = next(P);
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
// kamus lokal
    address P, newLast;

// algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (next(P) == NIL && prev(P) == NIL) {
            First(*L) = NIL;
        } else {
            while(next(P) != NIL){
                P = next(P);
            }
            newLast = prev(P);
            next(newLast) = NIL;
        }
        *V = info(P);
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
// kamus lokal
    address P, temp;

// algoritma 1
    // if (!IsEmptyList(*L)) {
    //     P = First(*L);
        
    //     if (next(P) == NIL && prev(P) == NIL) {
    //         if (info(P) == X) {
    //             Dealokasi(&P);
    //             First(*L) = NIL;
    //         }
    //     } else {
    //         while (next(P) != NIL && info(P) != X) {
    //             P = next(P);
    //         }
    //         if (info(P) == X) {

    //             if (prev(P) == NIL) {
    //                 First(*L) = next(P);
    //                 prev(next(P)) = NIL;

    //             } else if (next(P) == NIL) {
    //                 temp = prev(P);
    //                 next(temp) = NIL;

    //             } else {
    //                 temp = prev(P);
    //                 next(temp) = next(P);
    //                 prev(next(P)) = temp;
    //             }
    //             Dealokasi(&P);            
    //         }
    //     }
    // }

    // algoritma 2
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (next(P) != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            if (prev(P) == NIL) {
                DeleteVFirst(&(*L), &X);
            
            } else if (next(P) == NIL){
                DeleteVLast(&(*L), &X);
            
            } else {
                temp = prev(P);
                next(temp) = next(P);
                prev(next(P)) = temp;
                Dealokasi(&P);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
// kamus lokal
    address temp;
    
    
// algoritma
    *A = NIL;
    if (!IsEmptyList(L)) {
        temp = First(L);
        do {
            if (info(temp) == X) {
                *A = temp;
            }
            temp = next(temp);
        } while (temp != NIL && *A == NIL);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
// kamus lokal
    address temp;

// algoritma
    if (!IsEmptyList(*L)) {
        temp = First(*L);
        while (next(temp) != NIL && info(temp) != X) {
            temp = next(temp);
        }
        if (info(temp) == X) {
            info(temp) = Y;
        }
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
// kamus lokal
    address temp;
    List3 senarai2;

// algoritma
    if (!IsEmptyList(*L)) {
        temp = First(*L);
        CreateList(&senarai2);
        do {
            InsertVFirst(&senarai2, info(temp));
            temp = next(temp);

        } while (temp != NIL);
        First(*L) = First(senarai2);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
// kamus lokal
    address P, temp, nextP;

// algoritma
    SearchX(*L, X, &temp);
    if (temp != NIL) {
        P = Alokasi(V);
        if (P != NIL) {
            if (next(temp) == NIL) {
                next(temp) = P;
                prev(P) = temp;
            } else {
                nextP = next(temp);
                next(temp) = P;
                prev(P) = temp;
                next(P) = nextP;
                prev(nextP) = P; 
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
// kamus lokal
    address P, temp, prevP;

// algoritma
    SearchX(*L, X, &temp);
    if (temp != NIL) {
        P = Alokasi(V);
        if (P != NIL) {
            if (prev(temp) == NIL) {
                prev(temp) = P;
                next(P) = temp;
                First(*L) = P;
            } else {
                prevP = prev(temp);
                prev(temp) = P;
                next(P) = temp;
                prev(P) = prevP;
                next(prevP) = P; 
            }
        }
    }
}


/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
// kamus lokal
    address delete, temp, nextP;

// algoritma
    *V = '#';
    SearchX(*L, X, &temp);
    if (temp != NIL) {
        if (next(temp) != NIL) {
            delete = next(temp);
            *V = info(delete);
            if (next(delete) == NIL) {
                next(temp) = NIL;
            } else {
                nextP = next(delete);
                next(temp) = nextP;
                prev(nextP) = temp; 
            }
            Dealokasi(&delete);
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
// kamus lokal
    address delete, temp, prevP;

// algoritma
    *V = '#';
    SearchX(*L, X, &temp);
    if (temp != NIL) {
        if (prev(temp) != NIL) {
            delete = prev(temp);
            *V = info(delete);
            if (prev(delete) == NIL) {
                prev(temp) = NIL;
                First(*L) = temp;
            } else {
                prevP = prev(delete);
                prev(temp) = prevP;
                next(prevP) = temp; 
            }
            Dealokasi(&delete);
        }
    }

}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
// kamus lokal
    address P;
    int temp;

// algoritma
    temp = 0;
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            if (info(P) == X) {
                temp++;
            }
            P = next(P);
        } while (!(P == NIL));
    }
    return temp;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
// kamus lokal
    float totalAll;
    float totalX;

// algoritma
    totalAll = NbElm(L);
    totalX = CountX(L, X);
    return  totalX/totalAll; 
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
// kamus lokal
    address P;
    address basis;
    int max;

// algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        max = CountX(L, info(First(L)));
        basis = next(First(L));
        while (basis != NIL) {
            if (info(basis) != info(P)) {
                if (CountX(L, info(basis)) > max) {
                    P = basis;
                    max = CountX(L, info(basis));
                }
            }
            basis = next(basis);
        }

    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
// kamus lokal
    address P;
    address basis;
    int max;

// algoritma
    if (!IsEmptyList(L)) {
        P = First(L);
        max = CountX(L, info(First(L)));
        basis = next(First(L));
        while (basis != NIL) {
            if (info(basis) != info(P)) {
                if (CountX(L, info(basis)) > max) {
                    P = basis;
                    max = CountX(L, info(basis));
                }
            }
            basis = next(basis);
        }

    }
    return info(P);
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
// kamus lokal 
    address P;
    int temp;

// algoritma
    temp = 0;
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            if (info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
                temp++;
            }
            P = next(P);
        } while (!(P == NIL));
    }
    return temp;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
// kamus lokal 
    address P;
    int temp;

// algoritma
    temp = 0;
    P = First(L);
    if (!IsEmptyList(L)) {
        do {
            if (info(P) == 'n') {
                if (next(P) != NIL) {
                    if (info(next(P)) == 'g') {
                        temp++;
                    }
                }
            }
            P = next(P);
        } while (!(P == NIL));
    }
    return temp;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
	// kamus lokal
	address P;
	int count;
    boolean found;

	// algoritma
	if(!IsEmptyList(L)){
		P = First(L);
		count = 0;
        found = false;
		while (P != NIL) {
			count++;
			if(info(P) == X){
                found = true;
				printf("%d ", count);
			}
			P = next(P);
		}
        if (!found) {
            count = 0;
            printf("%d ", count);
        }
        printf("\n");
	}
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
// kamus lokal
    address temp;
    int basis;

// algoritma 1
    if(!IsEmptyList(*L)){
        temp = First(*L);
        basis = CountX(*L, X);
        while(basis > 0){
            if(info(temp) == X){
                DeleteX(&(*L), X);
                basis--;
            }
            temp = next(temp);
        }
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
// kamus lokal
    address temp;	
    
// algoritma
    temp = First(L1);
    while (temp != NIL) {
        InsertVLast(&(*L), info(temp));
        temp = next(temp);
    }
    temp = First(*L);
    while (next(temp) != NIL) {
        temp = next(temp);
    }

    next(temp) = First(L2);
    prev(First(L2)) = temp;
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
// kamus lokal
    address temp;	
    int len;
    int saklar;

// algoritma
    CreateList(&(*L1));
    CreateList(&(*L2));
    len = NbElm(L)/2;
    saklar = 0;

    temp = First(L);
    while (temp != NIL) {
        if (len <= 0) {
            saklar = 1;
        }
        if (saklar == 0) {
            InsertVLast(&(*L1), info(temp));
        } else {
            InsertVLast(&(*L2), info(temp));
        }
        len--;
        temp = next(temp);
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
// kamus lokal
    address temp;	
    
// algoritma
    temp = First(L1);
    while (temp != NIL) {
        InsertVLast(&(*L2), info(temp));
        temp = next(temp);
    }
}