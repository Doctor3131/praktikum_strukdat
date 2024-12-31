/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal :1 Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"

int main()
{ //kamus
  address A; 
  address B;
  address C;
  address P;
  List1 Senarai;
  List1 Senarai2;
  //algoritma
  
  // //aplikasi tipe address
  // A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  // A->info = 'G';   A->next = NIL;
  // // printf("info(A)=%c\t", A->info );
  // B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  // B->info = 'N';   B->next = A;
  // // printf("info(B)=%c\n", B->info );
  // C = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  // C->info = 'M';   C->next = B;

  // //aplikasi tipe List1
  CreateList(&Senarai);
  char a, b, c, d, e, f;
  a = 'A';
  b = 'B';
  c = 'C';
  d = 'G';
  e = 'E';
  f = 'G';

  // // memasukan (InsertVFirst)
  printf("\n");
  printf("InsertVFirst %c\n", a);
  InsertVFirst(&Senarai, a);
  printf("InsertVFirst %c\n", b);
  InsertVFirst(&Senarai, b);
  printf("InsertVFirst %c\n", c);
  InsertVFirst(&Senarai, c);
  printf("\n");

  // //tampilkan senarai 
  printf("Isi Senarai:[");
  PrintList( Senarai );
  printf("]\n");
  printf("Banyak isi Senarai: ");
  printf("%d\n",NbElm(Senarai));
  printf("\n");

  // // memasukan (InsertVFirst)
  printf("InsertVLast %c\n", d);
  InsertVLast(&Senarai, d);
  printf("InsertVLast %c\n", e);
  InsertVLast(&Senarai, e);
  printf("InsertVLast %c\n", f);
  InsertVLast(&Senarai, f);
  printf("\n");

  // //tampilkan senarai 
  printf("Isi Senarai:[");
  PrintList( Senarai );
  printf("]\n");
  printf("Banyak isi Senarai: ");
  printf("%d\n",NbElm(Senarai));
  printf("\n");

  // list ke dua
  CreateList(&Senarai2);
  char g, h, i, j, k, l;
  g = 'C';
  h = 'C';
  i = 'C';
  j = 'C';
  k = 'E';
  l = 'G';

  printf("InsertVFirst %c\n", g);
  InsertVFirst(&Senarai2, g);
  printf("InsertVFirst %c\n", h);
  InsertVFirst(&Senarai2, h);
  printf("InsertVFirst %c\n", i);
  InsertVFirst(&Senarai2, i);
  printf("InsertVFirst %c\n", j);
  InsertVFirst(&Senarai2, j);
  printf("InsertVFirst %c\n", k);
  InsertVFirst(&Senarai2, k);
  printf("InsertVFirst %c\n", l);
  InsertVFirst(&Senarai2, l);
  printf("\n");
  
  // //tampilkan senarai 
  printf("Isi Senarai2:[");
  PrintList( Senarai2 );
  printf("]\n");
  printf("Banyak isi Senarai: ");
  printf("%d\n",NbElm(Senarai));
  printf("\n");


  // // DeleteVfirst
  // infotype d1;
  // DeleteVFirst(&Senarai, &d1);
  //   printf("\n");
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");

  // // tampilkan senarai 
  // printf("Elemen yang di hapus first: ");
  // printf("%c\n",d1);
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // // DeleteVLast
  // infotype d2;
  // DeleteVLast(&Senarai, &d2);
  //   printf("\n");
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");

  // // tampilkan senarai 
  // printf("Elemen yang di hapus last: ");
  // printf("%c\n",d2);
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // SearchX
  // address z;
  // infotype x = 'A';
  // printf("search: %c\n", x);
  // SearchX(Senarai, x, &z);
  // printf("elemen yang di ambil: %c\n", info(z));
  // printf("\n");


  // // UpdateX
  // infotype SX = 'C';
  // infotype UX = 'X';
  // printf("update %c with %c\n", SX, UX);
  // UpdateX(&Senarai, SX, UX);
  // printf("\n");

  // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // invers
  // printf("invers:\n");
  // Invers(&Senarai);
  // printf("\n");

  // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // CountX
  // infotype CX = 'A';
  // printf("banyaknya %c adalah: %d\n", CX, CountX(Senarai, CX));
  // printf("\n");


  // // Frekuensi
  // infotype F = 'A';
  // printf("Frekuensi %c: %f\n", F, FrekuensiX(Senarai, F));
  // printf("\n");


  // // SearchAllX
  // infotype SAX = 'A';
  // printf("%c ada di posisi: \n[ ", SAX);
  // SearchAllX(Senarai, SAX);
  // printf("]\n");


  // // UpdateAllX
  // infotype UASX = 'A';
  // infotype UAUX = 'H';
  // printf("Update all %c with %c\n", UASX, UAUX);
  // UpdateAllX(&Senarai, UASX, UAUX);

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // InsertVAfter,
  // infotype IVA = 'C';
  // infotype IVN = 'N';
  // printf("insert %c after %c: \n", IVN, IVA);
  // InsertVAfter(&Senarai, IVA, IVN);

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // MaxMember
  // printf("Maxmember: %d\n", MaxMember(Senarai));
  // printf("\n");

  // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");


  // // Modus
  // printf("modus: %c\n", Modus(Senarai));
  // printf("\n");

  // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai));
  // printf("\n");

  
  // // concat
  // List1 Con;
  // CreateList(&Con);
  // printf("concat: \n");
  // ConcatList(Senarai, Senarai2, &Con);

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Con );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Con));
  // printf("\n");


  // // // SplitList
  // List1 L1;
  // List1 L2;
  // printf("potong list menjadi dua:\n");
  // SplitList(Con, &L1, &L2);

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( L1 );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(L1));
  // printf("\n");

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( L2 );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(L2));
  // printf("\n");


  // // // CopyList
  // printf("Copylist: \n");
  // List1 CL;
  // CopyList(Senarai2, &CL);

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( Senarai2 );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(Senarai2));
  // printf("\n");

  // // // tampilkan senarai 
  // printf("Isi Senarai:[");
  // PrintList( CL );
  // printf("]\n");
  // printf("Banyak isi Senarai: ");
  // printf("%d\n",NbElm(CL));
  // printf("\n");

  return 0;
}
