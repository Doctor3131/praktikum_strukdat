/* File : pohon3.c */
/* Deskripsi : Realisasi ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 6 Desember 2024*/

#include "pohon3.h"
#include "stdlib.h"
#include "stdio.h"

/* DEFINISI bintree3 kosong = NIL = ( ) ))*/

/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
// kamus lokal
    bintree3 P;

// algoritma
    P = (bintree3) malloc(sizeof(node3));
    if (P != NIL) {
        parent(P) = A;
        akar(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
        return P;
    } else {
        return NIL;
    }
}
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
// kamus lokal
    

// algoritma
    if (P != NIL) {
        visited(P) = False;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
// kamus lokal
    

// algoritma
    if (P == NIL) {
        return True;
    } else {
        return False;
    }
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
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

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) != NIL && right(P) != NIL) {
            return True;
        } else {
            return False;
        }
    } return False;
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) != NIL && right(P) == NIL) {
            return True;
        } else {
            return False;
        }
    } return False;
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) == NIL && right(P) != NIL) {
            return True;
        } else {
            return False;
        }
    } return False;
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
// kamus lokal

// algoritma v1
    if (!IsEmptyTree(P)) {
        // printf("%c {visited: %d}(", akar(P), visited(P));
        printf("%c(", akar(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    } else {
        printf("( )");
    }
// algoritma v2
    // if (!IsEmptyTree(P)) {
    //     printf("%c ", akar(P));
    //     printDFS(left(P));
    //     printDFS(right(P));
    // }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
// kamus lokal
    bintree3 temp;
    bintree3 kiri;
    bintree3 kanan;

// algoritma
    if (!IsEmptyTree(P)) {
        if (akar(P) != X){
            printPathX(left(P), X);
            printPathX(right(P), X);
        } else {
            temp = P;
            visited(temp) = True;
            while (parent(temp) != NIL) {
                temp = parent(temp);
                visited(temp) = True;
            }
            do {
                printf("%c ", akar(temp));
                if (left(temp) != NIL && visited(left(temp))) {
                    temp = left(temp);
                } else if (right(temp) != NIL && visited(right(temp))) {
                    temp = right(temp);
                } else {
                    temp = NIL;
                }
            } while (temp != NIL);
        } 
    }
    resetVisited(P);
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
// kamus lokal
    bintree3 temp;
    bintree3 kiri;
    bintree3 kanan;

// algoritma
    if (!IsEmptyTree(P)) {
        if (!IsDaun(P)){
            printPathDaunX(left(P), X);
            printPathDaunX(right(P), X);
        } else {
            if (akar(P) == X) {
                    temp = P;
                visited(temp) = True;
                while (parent(temp) != NIL) {
                    temp = parent(temp);
                    visited(temp) = True;
                }
                do {
                    printf("%c ", akar(temp));
                    if (left(temp) != NIL && visited(left(temp))) {
                        temp = left(temp);
                    } else if (right(temp) != NIL && visited(right(temp))) {
                        temp = right(temp);
                    } else {
                        temp = NIL;
                    }
                } while (temp != NIL);
            } 
        }
    }
    resetVisited(P);
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
// kamus lokal
    bintree3 temp;
    bintree3 kiri;
    bintree3 kanan;

// algoritma
    if (!IsEmptyTree(P)) {
        if (!IsDaun(P)){
            printAllPaths(left(P));
            printAllPaths(right(P));
        } else {
            printf("\n");
            printf("\n");
            temp = P;
            visited(temp) = True;
            while (parent(temp) != NIL) {
                temp = parent(temp);
                visited(temp) = True;
            }
            do {
                printf("%c ", akar(temp));
                if (left(temp) != NIL && visited(left(temp))) {
                    temp = left(temp);
                } else if (right(temp) != NIL && visited(right(temp))) {
                    temp = right(temp);
                } else {
                    temp = NIL;
                }
            } while (temp != NIL);
        } 
    }
    resetVisited(P);
}


/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    } else {
        return 0;
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (IsDaun(P)) {
            return 1;
        } else {
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    } else {
        return 0;
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (parent(P) == NIL) {
            return Max2(Tinggi(left(P)),Tinggi(right(P)));
        } else {
            return 1 + Max2(Tinggi(left(P)),Tinggi(right(P)));
        }
    } else { 
        return 0;
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        return 1 + Max2(Level(left(P)),Level(right(P)));
    } else {
        return 0;
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (T > 0) {
            return 1 + CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (N > 0) {
            if (visited(P) == False)
                printf("%c ", akar(P));
                visited(P) = True;
                PrintLevel(left(P),N-1); 
                PrintLevel(right(P),N-1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
// kamus lokal
    int basis;
    int i;

// algoritma v2
    for (i = 1; i <= Level(P); i++){
        PrintLevel(P, i);
    }

// algoritma v1
    // if (!IsEmptyTree(P)) {
    //     if (visited(P) == False) {
    //         printf("%c ", akar(P));
    //         visited(P) = True;
    //     }
    //     if (parent(P) != NIL) {
    //         if (right(parent(P)) != NIL) {
    //             if (visited(right(parent(P))) == False) {
    //                 printf("%c ", akar(right(parent(P))));
    //                 visited(right(parent(P))) = True;
    //             }
    //         } 
    //     }
    //     PrintBFS(left(P));
    //     PrintBFS(right(P));
    // }

}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {
// kamus lokal
    address temp;

// // algoritma
//     temp = First(*Asli);
//     while (next(temp) != NIL) {
//         temp = next(temp);
//     }
//     next(temp) = First(Tambahan);

// algoritma v2
    temp = First(Tambahan);
    do {
        InsertVLast(&(*Asli), info(temp));
        temp = next(temp);
    } while (temp != NIL);
    
} 

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan) {
// kamus lokal
    address temp;
    List1 dummy;

// algoritma
    CopyList(Asli, &dummy);
    temp = First(dummy);
    while (next(temp) != NIL) {
        temp = next(temp);
    }
    next(temp) = First(Tambahan);
    return dummy;
} 

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix(bintree3 P) {
    // Kamus lokal
    List1 hasil, kiri, kanan; 
    address temp;

    // Algoritma
    CreateList(&hasil); 

    if (!IsEmptyTree(P)) {
        // Allocate a new node for the root and insert it into the list
        // temp = Alokasi(akar(P)); 
        // printf("\naku ada disini %c\n", info(First(hasil)));

        if (visited(P) == False) {
            InsertVLast(&hasil, akar(P));
            visited(P) = True;
        }

            kiri = Fconcat(hasil,LinearPrefix(left(P)));
            kanan = Fconcat(hasil,LinearPrefix(right(P)));

            if (!IsEmptyTree(left(P))) {
                if (visited(left(P)) == False) {
                    Pconcat(&kanan, hasil);
                    Pconcat(&kiri, kanan);
                    hasil = kiri;
                }
            }
        // if(!IsEmptyTree(left(P))) {
        //     Fconcat(hasil, LinearPrefix(left(P)));
        // }
        // if(!IsEmptyTree(right(P))) {
        //     Fconcat(hasil, LinearPrefix(right(P)));
        // }
    }

    return hasil; 
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
// List1 LinearPosfix (bintree3 P) {
// /* Menghasilkan list node dari P terurut posfix (kiri, kanan, akar) */
//     // Kamus lokal
//     List1 hasil, kiri, kanan;
//  CreateList(&hasil);
//     // Algoritma
//     if (!IsEmptyTree(P)) {
//         // Traverse subpohon kiri
//         kiri = LinearPosfix(Left(P));

//         // Traverse subpohon kanan
//         kanan = LinearPosfix(Right(P));

//         // Gabungkan hasil dari kiri dan kanan ke dalam hasil
//         Pconcat(&hasil, kiri);
//         Pconcat(&hasil, kanan);

//         // Tambahkan nilai dari akar
//         InsertVLast(&hasil, Akar(P));
//     }

//     // Kembalikan hasil
//     return hasil;
// }


/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P);

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P);