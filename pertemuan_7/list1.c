/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal :1 Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "boolean.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address *P) {
	//kamus lokal
	
	//algoritma
	// if ( P != NIL ) {
	// 	next(P) = NIL;
	// }
	// P = NIL;
	free(*P);
	*P = NIL;
}
/*********** OPERATORS ***********/

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
	// kamus lokal

	// algoritma
	L->First = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
	// kamus lokal

	// algoritma
	if(L.First == NIL){
		return true;
	}
	else{
		return false;
	}
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L){
	// kamus lokal
	address P;
	// algoritma
	if(!IsEmptyList(L)){
		P = First(L);
		while (P != NIL) {
			printf(" %c ", info(P));
			P = next(P);
		}
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
	// kamus lokal
	address P;
	int count;

	// algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		count++;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
// kamus lokal
	address P;
	address temp;

// algoritma 1
	P = Alokasi(V);

	if(IsEmptyList(*L)){
		First(*L) = P;
		next(P) = NIL;
	}
	else{
		temp = First(*L);
		First(*L) = P;
		next(P) = temp;
	}

// algoritma 2
	// P = Alokasi(V);

	// if(P != NIL) {
	// 	next(P) = First(*L);
	// 	First(*L) = P;
	// }
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
// kamus lokal
	address P;
	address temp;

// algoritma
	P = Alokasi(V);
	next(P) = NIL;

	if(IsEmptyList(*L)){
		First(*L) = P;
	}
	else{
		temp = First(*L);
		while (next(temp) != NIL) {
			temp = next(temp);
		}
		next(temp) = P;
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	// kamus lokal
		address temp;
	
	// algoritma
		*V = '#';
		if(!IsEmptyList(*L)){
			*V = info(First(*L));
			temp = next(First(*L));
			Dealokasi(&(First(*L)));
			First(*L) = temp;
		}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	// kamus lokal
		address temp;
	
	// algoritma
		*V = '#';
		if(!IsEmptyList(*L)){
			if(next(First(*L)) == NIL){
				*V = info(First(*L));
				Dealokasi(&First(*L));
			}
			else{
				temp = First(*L);
				while(next(next(temp)) != NIL){
					temp = next(temp);
				}
				*V = info(next(temp));
				Dealokasi(&next(temp));
				// next(temp) = NIL;
			}
		}

}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
	// kamus lokal
		address temp;
		int count;

	// algoritma 
		*A = NIL;
		if(!IsEmptyList(L)){
			temp = First(L);
			count = NbElm(L);
			while(count > 0){
				if(info(temp) == X){
					*A = temp;
					count = 0;
				}
				temp = next(temp);
				count--;
			}
		}

}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
	// kamus lokal
		address P;
	
	// algoritma
		if(!IsEmptyList(*L)){
			SearchX(*L, X, &P);
			if(P != NIL){
				info(P) = Y;
			}
		}

}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L){
	// kamus lokal
		address tempA;
		address delete;
		List1 tempL;


	// algoritma
		if(!IsEmptyList(*L)){
			CreateList(&tempL);
			tempA = First(*L);
			while(tempA != NIL){
				InsertVFirst(&tempL, info(tempA));
				delete = tempA;
				tempA = next(tempA);
				Dealokasi(&delete);
			}
			First(*L) = First(tempL);
			First(tempL) = NIL;
		}
	
	// // kamus lokal 2
	// 	address first;
	// 	address next;
	// 	address temp;

	// // algoritma 2
	// 	temp = NIL;
	// 	first = First(*L);

	// 	while(first != NIL){
	// 		next = next(first);
	// 		next(first) = temp;
	// 		temp = first;
	// 		first = next;
	// 	}
	// 	First(*L) = temp;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
	// kamus lokal
		int count;
		address temp;
	
	// algoritma
		count = 0;
		if(!IsEmptyList(L)){
			temp = First(L);
			while(temp != NIL){
				if(info(temp) == X){
					count++;
				}		
				temp = next(temp);
			}
		}
		return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
	// kamus lokal
		float FX1;
		float FX2;
	
	// algoritma
	 	FX1 =  CountX(L, X);
	 	FX2 =  NbElm(L);
		return FX1 / FX2;
		
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
	// kamus lokal
	address P;
	int count;
	int basis;

	// algoritma
	if(!IsEmptyList(L)){
		P = First(L);
		count = 0;
		basis = CountX(L, X);
		while (basis > 0) {
			count++;
			if(info(P) == X){
				printf("%d ", count);
				basis--;
			}
			P = next(P);
		}
	}

	// algoritma 2
	// if(!IsEmptyList(L)){
	// 	P = First(L);
	// 	count = 0;
	// 	while (P != NIL) {
	// 		count++;
	// 		if(info(P) == X){
	// 			printf("%d ", count);
	// 		}
	// 		P = next(P);
	// 	}
	// }
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y){
	// kamus lokal
		address temp;
		int basis;

	// algoritma 1
		if(!IsEmptyList(*L)){
			temp = First(*L);
			basis = CountX(*L, X);
			while(basis > 0){
				if(info(temp) == X){
					UpdateX(&(*L), X, Y);
					basis--;
				}
				temp = next(temp);
			}
		}

	// algoritma 2
		// if(!IsEmptyList(*L)){
		// 	temp = First(*L);
		// 	while(temp != NIL){
		// 		if(info(temp) == X){
		// 			info(temp) = Y;
		// 		}
		// 		temp = next(temp);
		// 	}
		// }
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
	// kamus lokal
		address P;
		address basis;

	// algoritma 1 {masukan setelah V yang muncul paling pertama}
		if(!IsEmptyList(*L)){
			SearchX(*L, V, &basis);
			if(basis != NIL){
				P = Alokasi(V);
				info(P) = VA;
				next(P) = next(basis);
				next(basis) = P;
			}
		}

	// algoritma 2 {memasukkan setelah V jika V berdempet banyak}
		// if(!IsEmptyList(*L)){
		// 	SearchX(*L, V, &basis);
		// 	if(basis != NIL){
		// 		while(next(basis) != NIL && info(next(basis)) == V ){
		// 			basis = next(basis);
		// 		}	
				// P = Alokasi(V);
		// 		info(P) = VA;
		// 		next(P) = next(basis);
		// 		next(basis) = P;
		// 	}
		// }

	// algoritma 3 {masukan setelah V yang muncul paling akhir}
		// if(!IsEmptyList(*L)){
		// 	P = First(*L);
		// 	while(P != NIL){
		// 		if(info(P) == V){
		// 			basis = P;
		// 		}
		// 		P = next(P);
		// 	}	
		// 	if(basis != NIL){
		// 		P = Alokasi(V);
		// 		info(P) = VA;
		// 		next(P) = next(basis);
		// 		next(basis) = P;
		// 	}
		// }

}


/*function MaxMember(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List1 L){
	// kamus lokal
		address P;
		address basis;
		int max;
	
	// algoritma
		if(!IsEmptyList(L)){
			P = First(L);
			max = CountX(L, info(First(L)));
			basis = next(First(L));
			while(basis != NIL){
				if(info(basis) != info(P)){
					if(CountX(L, info(basis)) > max){
						P = basis;
						max = CountX(L, info(basis));
					}
				}
				basis = next(basis);
			}

		}
		return max;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L){
	// kamus lokal
		address P;
		address basis;
		int max;
	
	// algoritma
		if(!IsEmptyList(L)){
			P = First(L);
			max = CountX(L, info(First(L)));
			basis = next(First(L));
			while(basis != NIL){
				if(info(basis) != info(P)){
					if(CountX(L, info(basis)) > max){
						P = basis;
						max = CountX(L, info(basis));
					}
				}
				basis = next(basis);
			}
		}
		return info(P);
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L){
	// kamus lokal
		address temp;	
		
	// algoritma
		First(*L) = First(L1);
		temp = First(*L);
		while(next(temp) != NIL){
			temp = next(temp);
		}
		next(temp) = First(L2);
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2){
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
	while(temp != NIL){
		if(len <= 0){
			saklar = 1;
		}
		if(saklar == 0){
			InsertVLast(&(*L1), info(temp));
		}
		else{
			InsertVLast(&(*L2), info(temp));
		}
		len--;
		temp = next(temp);
	}

}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2){
	// kamus lokal
		address temp;
	
	// algoritma
		CreateList(&(*L2));
		if(!IsEmptyList(L1)){
			temp = First(L1);
			while (temp != NIL){
				InsertVLast(&(*L2), info(temp));
				temp = next(temp);
			}
		}
}