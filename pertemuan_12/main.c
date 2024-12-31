/* File : pohon3.c */
/* Deskripsi : Main.c dari pohon3 */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 6 Desember 2024*/
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "pohon3.c"
#include "list1.h"


int main() {
	//kamus
      infotype NodeX;
      infotype DaunX;
      int TnodeLevel;
      int NnodeLevel;
	
      // pembuat pohon
      bintree3 W = Tree3(NIL, 'A', False, NIL, NIL);

      bintree3 B = Tree3(W, 'B', False, NIL, NIL);
      bintree3 C = Tree3(W, 'C', False, NIL, NIL);
      left(W) = B;
      right(W) = C;

      bintree3 D = Tree3(B, 'D', False, NIL, NIL);
      right(B) = D;

      bintree3 E = Tree3(C, 'E', False, NIL, NIL);
      bintree3 F = Tree3(C, 'F', False, NIL, NIL);
      left(C) = E;
      right(C) = F;

      bintree3 G = Tree3(D, 'G', False, NIL, NIL);
      bintree3 H = Tree3(E, 'H', False, NIL, NIL);
      bintree3 I = Tree3(F, 'I', False, NIL, NIL);
      left(D) = G;
      right(E) = H;
      right(F) = I;

      bintree3 J = Tree3(I, 'J', False, NIL, NIL);
      bintree3 K = Tree3(I, 'K', False, NIL, NIL);
      left(I) = J;
      right(I) = K;

      /* 
              A
            /   \
           B     C
            \   / \
             D E   F
            /   \   \
           G     H   I
                    / \
                   J   K
      */


//    APLIKASI
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nprintDFS {MENCETAK NODE MENGGUNAKAN DFS} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nIsDaun {CEK APAKAH DAUN} \n");
//       printf("\n");
//       printf("cek IsDaun:            %d",IsDaun(left(right(left(W)))));
//       printf("\n");
//       printf("\n");
//       printDFS(left(right(left(W))));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nIsUnerRight {CEK APAKAH HANYA ADA KANAN} \n");
//       printf("\n");
//       printf("cek IsUnerRight:       %d",IsUnerRight(parent(right(left(W)))));
//       printf("\n");
//       printf("\n");
//       printDFS(parent(right(left(W))));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nIsUnerLeft {CEK APAKAH HANYA ADA KIRI} \n");
//       printf("\n");
//       printf("cek IsUnerLeft:        %d",IsUnerLeft(right(left(W))));
//       printf("\n");
//       printf("\n");
//       printDFS(right(left(W)));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nIsBiner {CEK APAKAH HANYA BINER} \n");
//       printf("\n");
//       printf("cek IsBiner:           %d",IsBiner(parent(right(right(W)))));
//       printf("\n");
//       printf("\n");
//       printDFS(parent(right(right(W))));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nprintPathX {MENCARI PATH AKAR KE NODE X} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       NodeX = 'E'; //elemen node yang dicari
//       printf("cek path ke:           %c",NodeX);
//       printf("\n");
//       printf("\n");
//       // printPathX(W, NodeX);
//       printPathX(W, 'F');
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nprintPathDauX {MENCARI PATH DAUN BERNILAI X} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       DaunX = 'K'; //elemen daun yang dicari
//       printf("cek path ke:           %c",DaunX);
//       printf("\n");
//       printf("\n");
//       printPathDaunX(W, DaunX);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nprintAllPaths {MENCARI SEMUA PATH KE TIAP DAUN} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printAllPaths(W);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nNbElmTree {MENGHITUNG BANYAKNYA ELEMEN DALAM POHON} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       printf("banyak elemen:        %d",NbElmTree(W));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nNbDaun {MENGHITUNG BANYAKNYA DAUN PADA POHON} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       printf("banyak daun:          %d",NbDaun(W));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nLevel {MENGHITUNG TINGKAT/LEVEL POHON} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       printf("banyak level:         %d",Level(W));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nCountLevelT {MENGHITUNG BANYAK NODE PADA TINGKAT/LEVEL T POHON} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       TnodeLevel = 5; //levelnya 
//       printf("\n");
//       printf("banyak level:         %d",TnodeLevel);
//       printf("\n");
//       printf("\n");
//       printf("banyak node:          %d",CountLevelT(W, TnodeLevel));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nTinggi {MENGHITUNG tinggi POHON} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
//       printf("\n");
//       printf("tinggi:               %d",Tinggi(W));
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nPrintLevel {MENAMPILKAN NILAI NODEL PADA TINGGI KE N} \n");
//       printf("\n");
//       NnodeLevel = 5; //levelnya 
//       printf("banyak level:         %d",NnodeLevel);
//       printf("\n");
//       printf("\n");
//       PrintLevel(W, NnodeLevel);
//       resetVisited(W);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nprintBFS {MENCETAK NODE MENGGUNAKAN BFS} \n");
//       printf("\n");
//       PrintBFS(W);
//       printf("\n");
printf("\n--------------------------------------------------------------------------------\n");
      printf("\n{MEMBUAT LIST1} \n");
// kamus lokal
      List1 Senarai;
      List1 Senarai2;

// algoritma
      printf("\n");
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
      // printf("Isi Senarai:[");
      // PrintList( Senarai );
      // printf("]\n");
      // printf("Banyak isi Senarai: ");
      // printf("%d\n",NbElm(Senarai));
      // printf("\n");

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

      printf("\n{MEMBUAT LIST1} \n");
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
printf("\n--------------------------------------------------------------------------------\n");
      printf("\nPconcat {MENGGABUNGKAN DUA LIST} \n");
// kamus lokal
      List1 Asli;

// algoritma
      CopyList(Senarai, &Asli);
      Pconcat(&Asli, Senarai2);
      printf("\n");
      printf("Isi Pconcat: [");
      PrintList(Asli);
      printf("]\n");
      printf("Banyak isi Senarai: ");
      printf("%d\n",NbElm(Asli));

      printf("\n");
      printf("Isi Asli: [");
      PrintList(Asli);
      printf("]\n");
      printf("Banyak isi Senarai: ");
      printf("%d\n",NbElm(Asli));
printf("\n--------------------------------------------------------------------------------\n");
      printf("\nFconcat {MENGGABUNGKAN DUA LIST (ME-RETURN LIST BARU)} \n");
// kamus lokal
      List1 FAsli;

// algoritma
      FAsli = Fconcat(Senarai, Senarai2);
      printf("\n");
      printf("Isi Pconcat: [");
      PrintList(FAsli);
      printf("]\n");
      printf("Banyak isi Senarai: ");
      printf("%d\n",NbElm(FAsli));

      printf("\n");
      printf("Isi Senarai: [");
      PrintList(Senarai);
      printf("]\n");
      printf("Banyak isi Senarai: ");
      printf("%d\n",NbElm(Senarai));

      printf("\n");
      printf("Isi Senarai2: [");
      PrintList(Senarai);
      printf("]\n");
      printf("Banyak isi Senarai2: ");
      printf("%d\n",NbElm(Senarai));
printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nLinearPrefix {MENGHASILKAN LIST NODE PREFIX)} \n");
// // kamus lokal
//       List1 LPrex;

// // algoritma
//       LPrex = LinearPrefix(W);
//       printf("\n");
//       printf("Isi LPrex: [");
//       PrintList(LPrex);
//       printf("]\n");
//       printf("Banyak isi Senarai: ");
//       printf("%d\n",NbElm(LPrex));
//       printf("\nprintDFS {MENCETAK NODE MENGGUNAKAN DFS} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");
//       printf("\nLinearPosfix {MENGHASILKAN LIST NODE POSFIX)} \n");
// // kamus lokal
//       List1 LPosx;

// // algoritma
//       LPosx = LinearPosfix(W);
//       printf("\n");
//       printf("Isi LPrex: [");
//       PrintList(LPosx);
//       printf("]\n");
//       printf("Banyak isi Senarai: ");
//       printf("%d\n",NbElm(LPosx));
//       printf("\nprintDFS {MENCETAK NODE MENGGUNAKAN DFS} \n");
//       printf("\n");
//       printDFS(W);
//       printf("\n");
// printf("\n--------------------------------------------------------------------------------\n");

      return 0;
}