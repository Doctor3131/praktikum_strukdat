/* File : main.c */
/* Deskripsi : aplikasi realisasi ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 22/11/2024*/

#include <stdio.h>
#include "pohon1.h"
#include "pohon1.c"

int main() {
// kamus lokal
    bintree Z;
    bintree A;
    bintree B;
    bintree C;
    bintree D;
    infotype g;
    infotype h;
    infotype i;
    infotype j;
    infotype k;
    infotype l;
    infotype m;
    infotype n;
    infotype o;
    infotype r;
    int q;





    A = Tree('a'
                ,Tree('c'
                        ,Tree('e'
                                ,NIL
                                ,NIL)
                        ,Tree('f'
                                ,NIL
                                ,NIL))
                ,Tree('d'
                        ,NIL
                        ,Tree('e'
                                ,Tree('h'
                                        ,NIL
                                        ,NIL)
                                ,NIL))
    );

    B = Tree('a'
                ,Tree('b'
                        ,NIL
                        ,Tree('d'
                                ,NIL
                                ,NIL))
                ,Tree('d'
                        ,NIL
                        ,NIL));


    C = Tree('a'
                ,Tree('a'
                        ,NIL
                        ,Tree('a'
                                ,NIL
                                ,NIL))
                ,Tree('a'
                        ,NIL
                        ,NIL));


    Z = Tree('#',NIL,NIL);

    D = Tree('A',
                Tree('I',
                        Tree('O',
                                Tree('D',
                                        NIL,
                                        NIL),
                                NIL),
                        Tree('Q',
                                NIL,
                                NIL)
                ),
                Tree('U',
                        Tree('S',
                                NIL,
                                NIL),
                        Tree('D',
                                NIL,
                                NIL)
                ));

     printf("\nnilai akar                : %c\n", GetAkar(A));
     printf("\nnilai left                : %c\n", GetAkar(GetLeft(A)));
     printf("\nnilai right               : %c\n", GetAkar(GetRight(A)));
     printf("\napakah pohon kosong       : %d\n", IsEmptyTree((GetLeft(GetRight(A)))));
     printf("\n");
     printf("\napakah daun               : %d\n", IsDaun((GetLeft(GetRight(A)))));
     printf("\napakah daun               : %d\n", IsDaun((GetLeft(GetLeft(A)))));
     printf("\n");
     printf("\napakah pohon biner        : %d\n", IsBiner((A)));
     printf("\napakah pohon biner        : %d\n", IsBiner((GetLeft(GetLeft(A)))));
     printf("\n");
     printf("\napakah unerLeft           : %d\n", IsUnerLeft(GetRight(A)));
     printf("\napakah unerLeft           : %d\n", IsUnerLeft((GetRight(GetRight(A)))));
     printf("\n");
     printf("\napakah unerRight          : %d\n", IsUnerRight(GetRight(A)));
     printf("\napakah unerRight          : %d\n", IsUnerRight((GetRight(GetRight(A)))));
     printf("\n");
     printf("\nprint tree A              : ");
     PrintPrefix(A);
     printf("\n");
     printf("\nprint tree B              : ");
     PrintPrefix(B);
     printf("\n");
     printf("\n");
     printf("\nbanyak element pada tree  : %d\n", NbElm(A));
     printf("\n");
     printf("\nbanyak daun pada tree A   : %d\n", NbDaun(A));
     printf("\n");
     printf("\n");
     printf("\nbanyak daun pada tree B   : %d\n", NbDaun(B));
     printf("\n");
     printf("\n");
     printf("\ntinggi dari pohon A       : %d\n", Tinggi(A));
     printf("\n");
     printf("\n");
     printf("\ntinggi dari pohon B       : %d\n", Tinggi(B));
     printf("\n");
     g = 'a';
     h = 'f';
     i = 'd';
     j = 'j';
     k = 'k';
     printf("\n");
     printf("\ncari %c dari pohon A       : %d\n", g, SearchX(A,g));
     printf("\n");
     printf("\n");
     printf("\ncari %c dari pohon A       : %d\n", h, SearchX(A,h));
     printf("\n");
     printf("\n");
     printf("\ncari %c dari pohon A       : %d\n", i, SearchX(A,i));
     printf("\n");
     printf("\n");
     printf("\ncari %c dari pohon A       : %d\n", j, SearchX(A,j));
     printf("\n");
     printf("\n");
     printf("\ncari %c dari pohon A       : %d\n", k, SearchX(A,k));
     printf("\n");
     l = 'f';
     m = 'z';
     printf("\n");
     printf("\nprint tree A              : ");
     PrintPrefix(A);
     printf("\n");
     printf("\n");
     printf("\ntukar %c dengan %c          : ", l, m);
     UpdateX(&A, l, m);
     PrintPrefix(A);
     printf("\n");
     printf("\n");
     n = 'a';
     printf("\n");
     printf("\ntotal %c pada akar C       : %d\n", n, CountX(C,n));
     printf("\n");  
     printf("\n");
     printf("\napakah condong kiri       : %d\n", IsSkewLeft(A));
     printf("\napakah condong kanan      : %d\n", IsSkewRight(A));
     printf("\ntinggi kiri               : %d\n", Tinggi(GetLeft(A)));
     printf("\ntinggi kanan              : %d\n", Tinggi(GetRight(A)));
     printf("\n");
     printf("\nprint tree A v1           : ");
     PrintPrefix(A);
     printf("\n");
     printf("\nprint tree A v2           : ");
     PrintPrefixV2(B);
     printf("\n");
     printf("\n");
     o = 'a';
     printf("\n");
     printf("\nLevel %c pada akar A       : %d\n", o, LevelX(A,o));
     PrintPrefixV2(A);
     printf("\n");  
     printf("\n");
     q = 4;
     printf("\n");
     printf("\nn elm Level %d pada akar A : %d\n", q, CountLevelT(A,q));
     PrintPrefixV2(A);
     printf("\n");
     printf("\n");
     printf("\ndaun terkiri pada akar A   : %c\n", GetDaunTerkiri(C));
     PrintPrefixV2(A);
     printf("\n");    
     r = 'a';
     printf("\n");
     printf("\ntotal %c                      : %d\n",r , CountX(C, r));
     printf("\nbanyak elm                   : %d\n", NbElm(C));
     printf("\nfrek %c pada akar A           : %f\n",r , FrekuensiX(C, r));
     printf("\n");  
     printf("\n");
     printf("\nbanyak vocal pada akar A   : %d\n", CountVocal(C));
     PrintPrefixV2(A);
     printf("\n");     
     printf("\n");
     printf("\nModus A                    : %c\n", Modus(A));
     PrintPrefixV2(A);
     printf("\n");    

     printf("\nModus D                    : %c\n", Modus(D));
     PrintPrefixV2(D);
     printf("\n");

    return 0;
}
