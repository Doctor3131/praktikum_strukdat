/* File : List2.c */
/* Deskripsi : Realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 11/11/2024*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
    // kamus lokal
        address P;
    
    // algoritma
        P = (address) malloc(sizeof(Elm));
        if(P != NIL){       
            info(P) = E;
            next(P) = NIL;
        }
        return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    // kamus lokal
    
    // algoritma
        free(*P);
        *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    // kamus lokal

    
    // algoritma
        First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
Boolean IsEmptyList (List2 L){
    // kamus lokal
        
    
    // algoritma
        if(First(L) == NIL){
            return True;
        }
        else{
            return False;
        }
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
Boolean IsOneElm (List2 L){
    // kamus lokal
        
    
    // algoritma
        if(next(First(L)) == First(L)){
            return True;
        }
        else{
            return False;
        }
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    // kamus lokal
        address P, first;
    
    // algoritma
        printf("\nPrintList: ");
        if(!IsEmptyList(L)){
            first = First(L);
            P = First(L);
            do {
                printf(" %c ", info(P));
                P = next(P);
            } while (P != first);
        } else {
            printf("kosong");
        }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    // kamus lokal
        address P, first;
        int count;
    
    // algoritma
        count = 0;
        if(!IsEmptyList(L)){
            first = First(L);
            P = First(L);
            do {
                count++;
                P = next(P);
            } while (P != first);
        }
        return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    // kamus lokal
        address P, first, last;
    
    // algoritma
        first = First(*L);
        P = Alokasi(V);
        if(P != NIL){
            if(IsEmptyList(*L)){
                First(*L) = P;
                next(First(*L)) = P;
            } else {
                First(*L) = P;
                last = first; 
                while(next(last) != first){ // mecari elemen terakhir
                    last = next(last);
                }
                next(First(*L)) = first;
                next(last) = First(*L);
            }
        }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    // kamus lokal
        address P, first, last;
    
    // algoritma
        first = First(*L);
        P = Alokasi(V);
        if(P != NIL){
            if(IsEmptyList(*L)){
                First(*L) = P;
                next(First(*L)) = P;
            } else {
                last = first; 
                while(next(last) != first){ // mecari elemen terakhir
                    last = next(last);
                }
                next(P) = first;
                next(last) = P;
            }
        }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    // kamus lokal
        address P, first, last;
    
    // algoritma
        first = First(*L);
        *V = '#';

        if(!IsEmptyList(*L)){
            if(IsOneElm(*L)){
                *V = info(first);
                Dealokasi(&first);
                First(*L) = NIL;
            } else {
                First(*L) = next(first);
                last = first; 
                while(next(last) != first){ // mecari elemen terakhir
                    last = next(last);
                }
                next(last) = First(*L);
                *V = info(first);
                Dealokasi(&first);
            }
        }

}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    // kamus lokal
        address P, first, last;
    
    // algoritma
        first = First(*L);
        *V = '#';

        if(!IsEmptyList(*L)){
            if(IsOneElm(*L)){
                *V = info(first);
                Dealokasi(&first);
                First(*L) = NIL;
            } else {
                last = first; 
                while(next(next(last)) != first){ // mecari elemen terakhir
                    last = next(last);
                }
                *V = info(next(last));
                Dealokasi(&next(last));
                next(last) = First(*L);
            }
        }

}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
    // kamus lokal
        address P, first, deleted;
        infotype cek;

    // algoritma
        if(!IsEmptyList(*L)){
            first = First(*L);

            if(IsOneElm(*L) || info(first) == X){
                DeleteVFirst(&(*L), &cek);
            }  
            else {
                P = first;
                while(next(P) != first && info(next(P)) != X){ // mecari elemen terakhir
                    P = next(P);
                }
                if(info(next(P)) == X){
                    deleted = next(P);
                    next(P) = next(deleted);
                    Dealokasi(&deleted);
                }
                else {
                    printf("\n\n\t%c tidak ada di list\n", X);
                }
            }
        }
}


/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    // kamus lokal
        address P, first;
    
    // algoritma
        *A = NIL;
        if(!IsEmptyList(L)){
            first = First(L);
            P = first;

            do {
                if(info(P) == X){
                    *A = P;
                }
                P = next(P);
            } while (P != first && *A == NIL);

            if(*A == NIL){
                printf("\n\n\t%c tidak ada di list\n\n", X);
            }
        }
}


/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    // kamus lokal
        address P, first;
    
    // algoritma
        if(!IsEmptyList(*L)){
            first = First(*L);
            P = first;

            do {
                if(info(P) == X){
                    info(P) = Y;
                    P = first;
                }
                else{
                    P = next(P);
                }
            } while (P != first);
        }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
	// kamus lokal
		address tempA;
        address tempB;
        address first;
        address next;
		address delete;
		List2 tempL;


	// algoritma
		if(!IsEmptyList(*L)){
			CreateList(&tempL);
			tempA = First(*L);
			while(next(tempA) != First(*L)){
				InsertVFirst(&tempL, info(tempA));
				delete = tempA;
				tempA = next(tempA);
				Dealokasi(&delete);
			}
            InsertVFirst(&tempL, info(tempA));
			First(*L) = First(tempL);
		}


}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
	// kamus lokal
		int count;
		address temp;
	
	// algoritma
		count = 0;
		if(!IsEmptyList(L)){
			temp = First(L);
			do{
				if(info(temp) == X){
					count++;
				}		
				temp = next(temp);
			} while(temp != First(L));
		}
		return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
	// kamus lokal
		float FX1;
		float FX2;
	
	// algoritma
	 	FX1 =  CountX(L, X);
	 	FX2 =  NbElm(L);
		return FX1 / FX2;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
	// kamus lokal
		int count;
		address temp;
	
	// algoritma
		count = 0;
		if(!IsEmptyList(L)){
			temp = First(L);
			do{
				if(info(temp) == 'a' || info(temp) == 'i' || info(temp) == 'u' || info(temp) == 'e' || info(temp) == 'o'){
					count++;
				}		
				temp = next(temp);
			} while(temp != First(L));
		}
		return count;
}


/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
	// kamus lokal
		int count;
		address temp;
	
	// algoritma
		count = 0;
		if(!IsEmptyList(L)){
			temp = First(L);
			do{
				if(info(temp) == 'n' && info(next(temp)) == 'g'){
					count++;
				}		
				temp = next(temp);
			} while(temp != First(L));
		}
		return count;
}


/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
	// kamus lokal
		address P;
		address basis;

	// algoritma 1 {masukan setelah V yang muncul paling pertama}
		if(!IsEmptyList(*L)){
			SearchX(*L, X, &basis);
			if(basis != NIL){
				P = Alokasi(V);
                if (P != NIL) {
    				next(P) = next(basis);
	    			next(basis) = P;
                }
			}
            else{
                printf("basis nil");
            }
		}
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
	// kamus lokal
		address P;
		address basis;

	// algoritma 1 {masukan setelah V yang muncul paling pertama}
		if(!IsEmptyList(*L)){
            Invers(&(*L));
			SearchX(*L, X, &basis);
			if(basis != NIL){
				P = Alokasi(V);
                if (P != NIL) {
    				next(P) = next(basis);
	    			next(basis) = P;
                }
			}
            else{
                printf("basis nil");
            }
            Invers(&(*L));
		}
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    // kamus lokal
        address P, first, deleted;
        infotype cek;

    // algoritma
        if(!IsEmptyList(*L)){
            first = First(*L);
            *V = '#';

            if(IsOneElm(*L) || info(first) == X){
                DeleteVFirst(&(*L), &cek);
                *V = cek;
            }  
            else {
                P = first;
                while(next(P) != first && info(P) != X){ // mecari elemen terakhir
                    P = next(P);
                }
                if(info(P) == X){
                    if(next(P) == first){
                        DeleteVFirst(&(*L), &(*V));
                    }
                    else{
                        *V = info(next(P));
                        deleted = next(P);
                        next(P) = next(deleted);
                        Dealokasi(&deleted);
                    }
                }
                else {
                    printf("\n\n\t%c tidak ada di list\n", X);
                }
            }
        }
    
    }



/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    // kamus lokal
        address P, first, deleted;
        infotype cek;

    // algoritma
        if(!IsEmptyList(*L)){
            first = First(*L);
            *V = '#';

            if(IsOneElm(*L) || info(next(first)) == X){
                DeleteVFirst(&(*L), &(*V));
            }  
            else {
                P = first;
                while(next(P) != first && info(P) != X){ // mecari elemen terakhir
                    P = next(P);
                }
                if(info(P) == X){
                        First(*L) = P;
                        DeleteVLast(&(*L), &(*V));
                        First(*L) = first;
                    }
                else {
                    printf("\n\n\t%c tidak ada di list\n", X);
                }
            }
        }
    
    }



/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X);

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X);

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L);

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L); 

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2);

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2);
