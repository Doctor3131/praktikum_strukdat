#include <stdio.h>
#include "pohon2.h"
#include "pohon2.c"

int main() {
// kamus lokal
    bintree Z;
    bintree Z1;
    bintree A;
    bintree B;
    bintree C;
    bintree D;
    bintree BST1;
    bintree BSTA;
    bintree d1;
    bintree d2;
    bintree d3;
    bintree d4;
    bintree d5;
    bintree d6;
    bintree d7;
    bintree d8;
    bintree d9;
    bintree d10;
    bintree d11;
    bintree d12;
    bintree d13;
    bintree d14;
    bintree d15;
    int  g;
    int  h;
    int  i;
    infotype  j;
    infotype  k;
    infotype  l;
    infotype  m;
    infotype  n;
    infotype  o;
    infotype  p;
    infotype  q;
    infotype  r;
    infotype  s;
    infotype  t;
    infotype  u;





    A = Tree('z'
                ,Tree('y'
                        ,Tree('u'
                                ,Tree('c'
                                        ,NIL
                                        ,NIL)
                                ,NIL)
                        ,Tree('a'
                                ,NIL
                                ,NIL))
                ,Tree('d'
                        ,NIL
                        ,Tree('a'
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
                                ,Tree('e'
                                        ,NIL
                                        ,NIL)))
                ,Tree('d'
                        ,NIL
                        ,NIL));


    C = Tree('d'
                ,Tree('a'
                        ,NIL
                        ,NIL)
                ,Tree('h'
                        ,NIL
                        ,NIL));

    
    Z = Tree('#',NIL,NIL); // '#' sebagai representasi elemen kosong

    Z1 = Tree('a',NIL,NIL);

    D = Tree('d',
                Tree('d',
                        Tree('d',
                                Tree('d',
                                        NIL,
                                        NIL),
                                NIL),
                        Tree('d',
                                NIL,
                                NIL)
                ),
                Tree('d',
                        Tree('d',
                                NIL,
                                NIL),
                        Tree('d',
                                NIL,
                                NIL)
                ));

    BST1 = Tree(50,
                Tree(30,
                        Tree(20,
                        Tree(10, 
                                NIL, 
                                NIL),
                        NIL),
                        Tree(40, 
                                NIL, 
                                NIL)),
                Tree(70,
                        Tree(60,
                                NIL,
                                Tree(65, 
                                        NIL, 
                                        NIL)),
                        Tree(80,
                                NIL,
                                Tree(90, 
                                        NIL, 
                                        NIL))
                ));
    BSTA = Tree('m',
                Tree('f',
                        Tree('d',
                                Tree('a', 
                                        NIL, 
                                        NIL),
                                NIL),
                        Tree('h', 
                                NIL, 
                                NIL)),
                Tree('t',
                        Tree('p',
                                NIL,
                                Tree('r', 
                                        NIL, 
                                        NIL)),
                        Tree('w',
                                NIL,
                                Tree('z', 
                                        NIL, 
                                        NIL))
                ));



// realisasi
// printf("\n-----------------------------------------------------------------\n");
//     d1 = A;
//     printf("\nPrintPrefix dari A                :");
//     printf("\n");
//     PrintPrefix(d1);
//     printf("\n");
//     g = 0;
//     printf("\nPrintTreeInden dari A             :");
//     printf("\n");
//     PrintTreeInden(d1, g);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     h = 3;
//     printf("\nPrintLevel %d                      :", h);
//     printf("\n");
//     PrintLevel(D, h);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     i = 9; // banyak simpul
//     printf("\nBuildBalanceTree n node %d         :", i);
//     printf("\n");
//     printf("Ketik huruf sebanyak: %d", i);
//     printf("\n");
//     d2 = BuildBalanceTree(i);
//     printf("\n");
//     PrintTreeInden(d2, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     printf("\nIsBalanceTree                     : %d", IsBalanceTree(D));
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     j = 'k'; // elemen yang dimasukan
//     d3 = Z; // tree yang digunakan
//     printf("\n");
//     PrintTreeInden(d3, 0);
//     printf("\n");
//     printf("\nAddDaunTerkiri elemen %c          :", j);
//     AddDaunTerkiri(d3, j);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d3, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     k = 'h'; // elemen daun yang di cari
//     l = 'p'; // elemen yang dimasukan
//     d4 = A; // tree yang digunakan
//     printf("\n");
//     PrintTreeInden(d4, 0);
//     printf("\n");
//     printf("\nAddDaun %c elemen %c              :", k, l);
//     AddDaun(d4, k, l, 1);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d4, 0);
//     printf("\n");
printf("\n-----------------------------------------------------------------\n");
    printf("\n");
    m = 'i'; // elemen daun yang di cari
    d5 = BSTA; // tree yang digunakan
    printf("\n");
    PrintTreeInden(d5, 0);
    printf("\n");
    printf("\nInsertX elemen %c               :", m);
    InsertX(&d5, m);
    printf("\n");
    printf("\n");
    PrintTreeInden(d5, 0);
    printf("\n");
printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d6 = B; // tree yang digunakan
//     printf("\n");
//     PrintTreeInden(d6, 0);
//     printf("\n");
//     DelDaunTerkiri(&d6, &n);
//     printf("\nDelDaunTerkiri                 : %c", n);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d6, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d7 = D; // tree yang digunakan
//     o = 'd'; // elemen yang di cari
//     printf("\n");
//     PrintTreeInden(d7, 0);
//     printf("\n");
//     DelDaun(&d7, o);
//     printf("\nDelDaun %c                    : ", o);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d7, 0);
//     printf("\n");
//  printf("\n-----------------------------------------------------------------\n");
//      printf("\n");
//      d8 = D; // tree yang digunakan
//      p = 'd'; // elemen yang di ganti
//      q = 'a'; // elemen pengganti
//      printf("\n");
//      PrintTreeInden(d8, 0);
//      printf("\n");
//      UpdateAllX(&d8, p, q);
//      printf("\n UpdateAllX %c diganti %c      : ", p, q);
//      printf("\n");
//      printf("\n");
//      PrintTreeInden(d8, 0);
//      printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d9 = A; // tree yang digunakan
//     r = 'a'; // elemen yang di hapus
//     printf("\n");
//     PrintTreeInden(d9, 0);
//     printf("\n");
//     DeleteX(&d9, r);
//     printf("\n DeleteX dengan X = %c            : ", r);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d9, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d10 = A; // tree yang digunakan
//     printf("\n");
//     PrintTreeInden(d10, 0);
//     printf("\n");
//     printf("\nmaxTree                           : %c", maxTree(d10));
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d11 = A; // tree yang digunakan
//     printf("\n");
//     PrintTreeInden(d11, 0);
//     printf("\n");
//     printf("\nminTree                           : %c", minTree(d11));
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d12 = BSTA; // tree yang digunakan
//     s = 'e'; // elemen yang di ditambahkan
//     printf("\n");
//     PrintTreeInden(d12, 0);
//     printf("\n");
//     printf("\nBSearch                           : %d", BSearch(d12, s));
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d13 = BSTA; // tree yang digunakan
//     t = 'e'; // elemen yang di ditambahkan
//     printf("\n");
//     d14 = InsSearch(d13, s);
//     printf("\nInsSearch add %c                  : ", t);
//     printf("\n");
//     printf("\nlama                              : ", t);
//     printf("\n");
//     PrintTreeInden(d13, 0);
//     printf("\n");
//     printf("\nbaru                              : ", t);
//     printf("\n");
//     PrintTreeInden(d14, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
//     printf("\n");
//     d15 = BSTA; // tree yang digunakan
//     u = 'q'; // elemen yang di hapus
//     printf("\n");
//     PrintTreeInden(d15, 0);
//     printf("\n");
//     DelBtree(&d15, u);
//     printf("\n DeleteX dengan X = %c            : ", u);
//     printf("\n");
//     printf("\n");
//     PrintTreeInden(d15, 0);
//     printf("\n");
// printf("\n-----------------------------------------------------------------\n");
}

