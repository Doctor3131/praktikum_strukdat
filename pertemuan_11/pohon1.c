/* File : pohon1.c */
/* Deskripsi : realisasi ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 22/11/2024*/
#include "pohon1.h"
#include <stdlib.h>
#include <stdio.h>

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E) {
// kamus lokal
    bintree P;

// algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
      
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P) {
// kamus lokal
    

// algoritma
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
// kamus lokal
    bintree P;

// algoritma
    P = Alokasi(akar);
    if (P != NIL) {
        right(P) = right;
        left(P) = left;
    }
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P) {
// kamus lokal
    

// algoritma
    if (P != NIL) {
    return info(P);
    } else {
        return '#';
    }

}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
// kamus lokal
    

// algoritma
    return left(P);   
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
// kamus lokal
    

// algoritma
    return right(P);  
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> Boolean 
   {mengembalikan true bila bintree L kosong} */
Boolean IsEmptyTree (bintree P) {
// kamus lokal
    

// algoritma
    if (GetAkar(P) == '#') {
        return True;
    } else {
        return False;
    }
}

/* function IsDaun (P:BinTree)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
Boolean IsDaun(bintree P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) == NIL && right(P) == NIL) {
            return True;
        } else {
            return False;
        }
    } else {
        return False;
    }
}

/* function IsBiner (P:BinTree)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
Boolean IsBiner(bintree P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (GetRight(P) != NIL && GetLeft(P) != NIL) {
            return True;
        } else {
            return False;
        }
    } else {
        return False;
    }
}

/* function IsUnerLeft(P:BinTree)-> Boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
Boolean IsUnerLeft(bintree P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (GetRight(P) == NIL && GetLeft(P) != NIL) {
            return True;
        } else {
            return False;
        }
    } else {
        return False;
    }   
}

/* function IsUnerRight(P:BinTree)-> Boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
Boolean IsUnerRight(bintree P) {
    if (!IsEmptyTree(P)) {
        if (GetRight(P) != NIL && GetLeft(P) == NIL) {
            return True;
        } else {
            return False;
        }
    } else {
        return False;
    }   
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        printf("( )");
    } else if (IsDaun(P)) {
        printf("%c(( ),( ))", GetAkar(P));
    } else {
        printf("%c(", GetAkar(P));
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        return 1 + NbElm(GetLeft(P)) + NbElm(GetRight(P));
    }

}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }
    if (IsDaun(P)) {
        return 1;
    } else {
        return NbDaun(GetLeft(P)) + NbDaun(GetRight(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
// kamus lokal
    

// algoritma
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else if (IsDaun(P)) {
        return 0;
    } else {
        return 1 + max2(Tinggi(GetLeft(P)),Tinggi(GetRight(P)));
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> Boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
Boolean SearchX(bintree P, infotype X) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return False;
    } else {
        if (GetAkar(P) == X) {
            return True;
        } else {
            return SearchX(GetLeft(P),X) || SearchX(GetRight(P),X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(*P)) {
        return;
    } else {
        if (GetAkar(*P) == X) {
            akar(*P) = Y;
        } else {
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (GetAkar(P) == X) {
            return 1 + CountX(GetLeft(P), X) + CountX(GetRight(P), X);
        } else {
            return CountX(GetLeft(P), X) + CountX(GetRight(P), X);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> Boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
Boolean IsSkewLeft (bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return False;
    } else if (IsDaun(P)) {
        return False;
    } else {
        return Tinggi(GetLeft(P)) > Tinggi(GetRight(P));
    }
}

/*function IsSkewRight (P : BinTree) -> Boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
Boolean IsSkewRight (bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return False;
    } else if (IsDaun(P)) {
        return False;
    } else {
        return Tinggi(GetLeft(P)) < Tinggi(GetRight(P));
    }
}

/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixV2(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        printf("()");
    } else if (IsDaun(P)) {
        printf("%c", GetAkar(P));
    } else {
        printf("%c(", GetAkar(P));
        PrintPrefixV2(GetLeft(P));
        printf(",");
        PrintPrefixV2(GetRight(P));
        printf(")");
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
// kamus lokal
    

// algoritma v1
    // if (IsEmptyTree(P)) {
    //     return -1000;
    // } else if (GetAkar(P) == X) {
    //     return 1;
    // } else {
    //     return 1 + max2(LevelX(GetLeft(P), X),LevelX(GetRight(P), X));
    // }


// algoritma v2
    if (SearchX(P, X)) {
        if (IsEmptyTree(P)) {
            return -1000;
        } else if (GetAkar(P) == X) {
            return 1;
        } else {
            return 1 + max2(LevelX(GetLeft(P), X),LevelX(GetRight(P), X));
        }
    } else {
        return 0;
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else if (T == 1) {
        return 1;
    } else if (T == 0) {
        return 0;
    } else {
        return CountLevelT(GetLeft(P), T-1) + CountLevelT(GetRight(P), T-1);
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return '#';
    } else if (GetAkar(GetLeft(P)) == '#') {
        return GetAkar(P);
    } else {
        return GetDaunTerkiri(GetLeft(P));
    }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X) {
// kamus lokal
    float a;
    float b;

// algoritma
    a = CountX(P, X);
    b = NbElm(P);

    return a/b;
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(L)) {
        return 0;
    } else {
        if (GetAkar(L) == 'a') {
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        } else if (GetAkar(L) == 'i') {
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        } else if (GetAkar(L) == 'u') {
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        } else if (GetAkar(L) == 'e') {
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        } else if (GetAkar(L) == '0') {
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        } else {
            return CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        }
    }
}


/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
// kamus lokal
    infotype temp;
    int count;
    char huruf; 

// algoritma
    if (!IsEmptyTree(P)) {
        temp = GetAkar(P);
        count = CountX(P, temp);
        huruf = temp;
        if (CountX(P, Modus(GetLeft(P))) > count) {
            huruf = Modus(GetLeft(P));
            count = CountX(P, Modus(GetLeft(P)));
        } else {
            if (CountX(P, Modus(GetRight(P))) > count) {
                huruf = Modus(GetRight(P));
                count = CountX(P, Modus(GetRight(P))); 
            }
        }
        return huruf;
    } else {
        return '#';
    }

    
}
