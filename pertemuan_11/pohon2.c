#include "pohon2.h"
#include <stdlib.h>
#include <stdio.h>

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H) {
// kamus lokal
    int i;

// algoritma v1
    i = 0;
    if (IsEmptyTree(P)) {
        for (i; i < H; i++) {
            printf("--------");
        }
        printf("None");
    } else {
        for (i; i < H; i++) {
            printf("--------");
        }
        printf("%c\n", GetAkar(P));
        PrintTreeInden(GetLeft(P), H+1);
        printf("\n");
        PrintTreeInden(GetRight(P), H+1);
    }
// algoritma v2 print pohon ke bawah (status: gagal) 
    // i = 0;
    // if (IsEmptyTree(P)) {
    //     for (i; i < H/2; i++) {
    //         printf("\t");
    //     }
    //     printf("None\n");
    // } else {
    //     for (i; i < H; i++) {
    //         printf("\t");
    //     }
    //     printf("%c\n", GetAkar(P));

    //     if (left(P) != NIL) {
    //         i = 0;
    //         for (i; i < H/2; i++) {
    //             printf("\t");
    //         }
    //         // printf("/ ");
    //         PrintTreeInden(left(P), H/2);
    //     }
    //     if (right(P) != NIL) {
    //         i = 0;
    //         for (i; i < H+H/2; i++) {
    //             printf("\t");
    //         }
    //         // printf("\\ ");
    //         PrintTreeInden(right(P), H + H/2);
    //     }
    // }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N) {
// kamus lokal

// algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", GetAkar(P));
        } else {
            PrintLevel(GetLeft(P), N-1);
            // printf("\n");
            PrintLevel(GetRight(P), N-1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
// kamus lokal
    char A;

// algoritma
    if (n >= 1) {
        scanf(" %c", &A);
        return Tree(A, BuildBalanceTree(n-1-((n-1)/2)), BuildBalanceTree((n-1)/2));
    } else {
        return NIL;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
Boolean IsBalanceTree(bintree P) {
// kamus lokal
    int temp; 

// algoritma
    if (!IsEmptyTree(P)) {
        temp = abs(NbElm(GetLeft(P)) - NbElm(GetRight(P)));
        if (temp <= 1) {
            return True;
        } else {
            return False;
        }
    } else {
        printf("\ntree kosong\n");
        return -1;
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (GetAkar(GetLeft(P)) == '#') {
            left(P) = Tree(X,NIL,NIL);
        } else {
            AddDaunTerkiri(GetLeft(P), X);
        }
    } else {
        akar(P) = X;
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, Boolean Kiri) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(P)) {
        if (IsDaun(P)) {
            if (GetAkar(P) == X) {
                if (Kiri) {
                    left(P) = Tree(Y,NIL,NIL);
                } else {
                    right(P) = Tree(Y,NIL,NIL);
                }
            }
        } else {
            AddDaun(GetLeft(P), X, Y, Kiri);
            AddDaun(GetRight(P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
// kamus lokal
    bintree leftTemp;
// algoritma v2
    if (!IsEmptyTree(*P)) {
        if (!SearchX(*P, X)) {
            if (IsUnerRight(*P)) {
                left(*P) = Tree(X,NIL,NIL);
            } else if (IsUnerLeft(*P)) {
                right(*P) = Tree(X,NIL,NIL);
            } else {
                InsertX(&left(*P), X);
                if (!SearchX(*P, X)) {
                InsertX(&right(*P), X);
                }
            }
    } else {
        akar(*P) = X;
        }
    }

// algoritma v1
    // if (!IsEmptyTree(*P)) {
    //     if (!SearchX(*P, X)) {
    //         leftTemp = left(*P);
    //         left(*P) = Tree(X, NIL, NIL);
    //         left(left(*P)) = leftTemp;
    //     } else {
    //         printf("\nterdapat %c pada tree\n", X);
    //     }
    // } else {
    //     akar(*P) = X;
    // }

}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
// kamus lokal
    bintree temp;

// algoritma 1
    // *X = '#';
    // if (!IsEmptyTree(*P)) {
    //     if (IsDaun(left(*P))) {
    //         temp = left(*P);           
    //         *X = info(temp);             
    //         left(*P) = NIL;           
    //         Dealokasi(&temp);

    //     } else {
    //         DelDaunTerkiri(&(left(*P)), X);
    //     }
    // }
// algoritma 2
    *X = '#';
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            *X = info(*P);             
            Dealokasi(P);
            *P = NIL;           
        } else {
            if (Tinggi(left(*P)) <= Tinggi(right(*P))) {
                DelDaunTerkiri(&(left(*P)), X);
            } else {
                DelDaunTerkiri(&(right(*P)), X);
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
// kamus lokal
    

// algoritma 1 delete semua daun bernilai X yang di temukan
    // if (!IsEmptyTree(*P)) {
    //     if (IsDaun(*P)) {
    //         if (GetAkar(*P) == X) {
    //             Dealokasi(&(*P));
    //             *P = NIL;
    //         }
    //     } else {
    //         if (left(*P) != NIL) {
    //             DelDaun(&(left(*P)), X);
    //         } 
    //         if (right(*P) != NIL) {
    //             DelDaun(&(right(*P)), X);
    //         }
    //     }
    // }
// algoritma 2 sama aja, lebih ringkat tp
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            if (GetAkar(*P) == X) {
                Dealokasi(&(*P));
                *P = NIL;
            }
        } else {
            DelDaun(&(left(*P)), X);
            DelDaun(&(right(*P)), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }
{ jika ada di kondisi akar = X dan IsBiner(akar), right dari akar dijadikan
elemen paling kiri}*/

void DeleteX(bintree *P, infotype X) {
// kamus lokal
    bintree temp;
    bintree kanan; 
    bintree kiri; 

    // algoritma
    if (!IsEmptyTree(*P)) {

        if (left(*P) != NIL) {
            DeleteX(&left(*P), X);
        }
        if (right(*P) != NIL) {
            DeleteX(&right(*P), X);
        }

        if (akar(*P) == X) {
            temp = *P;
            if (IsBiner(*P)) {
                kanan = right(temp);
                *P = left(temp);
                kiri = temp;
                while (left(kiri) != NIL) {
                    kiri = left(kiri);
                }
                left(kiri) = kanan;

                    // printf("\naku ada disini\n");
                    // PrintTreeInden(kiri, 0);
                    // printf("\n");
                    // printf("\n");
                    // printf("\n-----------------------------------------------------------------\n");

            } else if (IsUnerLeft(*P)) {
                *P = left(*P);
            } else if (IsUnerRight(*P)) {
                *P = right(*P);
            } else if (IsDaun(*P)) { 
                *P = NIL;
            }
            Dealokasi(&(temp));
        }

    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
// kamus lokal
    

// algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            akar(*P) = Y;
        } 
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }   
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
infotype maxTree(bintree P) {
// kamus lokal
    char kanan;
    char kiri;
    char ayah;
    char temp;

// algoritma
    if (!IsEmptyTree(P)) {
        kanan = maxTree(left(P));
        kiri = maxTree(right(P));
        ayah = info(P);

        temp = ayah;
        if (kiri > temp) {
            temp = kiri;    
        }
        if (kanan > temp) {
            temp = kanan;
        }
        printf("\nnilai temp: %c\n", temp);
        printf("\n-----------------------------------------------------------------\n");
        return temp;
    } 
    return 0;
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
infotype minTree(bintree P) {
// kamus lokal
    char kanan;
    char kiri;
    char ayah;
    char temp;

// algoritma
    if (!IsEmptyTree(P)) {
        kanan = minTree(left(P));
        kiri = minTree(right(P));
        ayah = info(P);

        // printf("\nnilai kanan: %c\n", kanan);
        // printf("\nnilai kiri: %c\n", kiri);
        // printf("\nnilai temp: %c\n", ayah);

        temp = ayah;
        if (kiri != 0 && kiri < temp) {
            temp = kiri;    
        }
        if (kanan != 0 && kanan < temp) {
            temp = kanan;
        }
        // printf("\nnilai temp: %c\n", temp);
        return temp;
    } 
    return 0;
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
Boolean BSearch(bintree P, infotype X) {
// kamus lokal
    

// algoritma
    if (IsEmptyTree(P)) {
        return False;
    } else {
        if (GetAkar(P) == X) {  
            return True;
        } else if (GetAkar(P) > X) {
            return BSearch(GetLeft(P), X);
        } else {
            return BSearch(GetRight(P), X);
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
// kamus lokal
    bintree temp;


// algoritma
    if (!IsEmptyTree(P)) {
        if (X < akar(P)) {
            left(P) = InsSearch(left(P), X);
        } else if (X > akar(P)) {
            right(P) = InsSearch(right(P), X);
        }
        return P;
    } else {
        return Tree(X, NIL, NIL);
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
// kamus lokal
    bintree temp;
    bintree kanan; 
    bintree kiri; 

    // algoritma
    if (!IsEmptyTree(*P)) {

        if (GetAkar(*P) < X) {
            DelBtree(&left(*P), X);
        } 
        else if (GetAkar(*P) > X) {
            DelBtree(&right(*P), X);
        } else {

            temp = *P;
            if (IsDaun(*P)) {
                *P = NIL;
            } else if (IsUnerLeft(*P)) {
                *P = left(*P);
            } else if (IsUnerRight(*P)) {
                *P = right(*P);
            } else {
                do {
                *P = right(*P);
                right(*P) = left(*P);
                *P = left(*P);
                } while (*P != NIL);
            }
        }
    } 
}
