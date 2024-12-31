/* File : main.c */
/* Deskripsi : file Aplikasi*/
/* NIM & Nama : 24060123120035 Siriel Wafa Nuriel fahri*/
/* Tanggal : 18/11/2024*/

#include <stdio.h>
#include "list3.h"
#include "list3.c"
int main(){
    
    address A;
    address B;
    List3 senarai, senarai2;
    infotype a, b, c, d, f, g, h, i;

    a = 'a';
    b = 'b';
    c = 'c';
    d = 'd';
    f = 'e';
    g = 'f';
    h = 'g';
    i = 'i';

    CreateList(&senarai);
    CreateList(&senarai2);

    InsertVFirst(&senarai, a);
    InsertVFirst(&senarai, b);
    InsertVFirst(&senarai, c);
    InsertVFirst(&senarai, d);

    InsertVLast(&senarai2, f);
    InsertVLast(&senarai2, g);
    InsertVLast(&senarai2, h);
    InsertVLast(&senarai2, i);

    printf("\ndefault data senarai:");
    printf("\njumlah list: %d\n", NbElm(senarai));
    PrintList(senarai);

    printf("\ndefault data senarai2:");
    printf("\njumlah list: %d\n", NbElm(senarai2));
    PrintList(senarai2);

    // infotype delF;
    // DeleteVFirst(&senarai, &delF);
    // printf("\nhapus awal: %c\n", delF);
    // PrintList(senarai);

    // infotype delL;
    // DeleteVLast(&senarai, &delL);
    // printf("\nhapus akhir: %c\n", delL);
    // PrintList(senarai);

    // infotype delX;
    // delX = 'b';
    // DeleteX(&senarai, delX);
    // printf("\nhapus nilai X: %c\n", delX);
    // PrintList(senarai);

    // infotype serX;
    // address serA;
    // serX = 'e';
    // SearchX(senarai, serX, &serA);
    // if (serA == NIL) {printf("\ntidak ada %c di list\n", serX);}
    // else {printf("\nditemukan %c untuk x: %c\n", info(serA), serX);}
    // PrintList(senarai);

    // infotype updX;
    // infotype updY;
    // updX = 'g';
    // updY = 'z';
    // UpdateX(&senarai, updX, updY);
    // PrintList(senarai);

    // Invers(&senarai);
    // printf("\ninvers:");
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    // infotype insAX;
    // infotype insVA;
    // insAX = 'i';
    // insVA = 'i';
    // InsertVAfterX(&senarai, insAX, insVA);
    // printf("\nInsert %c after %c", insVA, insAX);
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    // infotype insBX;
    // infotype insVB;
    // insBX = 'i';
    // insVB = 'i';
    // InsertVBeforeX(&senarai, insBX, insVB);
    // printf("\nInsert %c before %c", insVB, insBX);
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    // infotype delAX;
    // infotype delVA;
    // delAX = 'h';
    // DeleteVAfterX(&senarai, delAX, &delVA);
    // printf("\ndelete %c after %c", delVA, delAX);
    // printf("\nelemen yang dihapus: %c", delVA);
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    // infotype delBX;
    // infotype delVB;
    // delBX = 'h';
    // DeleteVBeforeX(&senarai, delBX, &delVB);
    // printf("\ndelete %c before %c", delVB, delBX);
    // printf("\nelemen yang dihapus: %c", delVB);
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    // infotype conX;
    // conX = 'g';
    // printf("\nbanyak %c: %d\n", conX, CountX(senarai, conX));

    // infotype freX;
    // freX = 'g';
    // printf("\nbanyak %c: %f\n", freX, FrekuensiX(senarai, freX));    

    // printf("\nmaxMember: %d\n", MaxMember(senarai));

    // printf("\nmodus: %c\n", Modus(senarai));

    // printf("\nCountVocal: %d\n", CountVocal(senarai));

    // infotype saX;
    // saX = 'q';
    // printf("\nindeks %c: ", saX);
    // SearchAllX(senarai, saX);


    // infotype daX;
    // daX = 'i';
    // printf("\ndelete all %c: ", daX);
    // DeleteAllX(&senarai, daX);
    // printf("\njumlah list: %d\n", NbElm(senarai));
    // PrintList(senarai);

    List3 senaraiNew;
    CreateList(&senaraiNew);
    ConcatList(senarai, senarai2, &senaraiNew);
    printf("\njumlah list: %d\n", NbElm(senaraiNew));
    PrintList(senaraiNew);

    List3 copySenarai;
    List3 copySenarai2;
    CreateList(&copySenarai);
    CreateList(&copySenarai2);
    SplitList(senaraiNew, &copySenarai, &copySenarai2);
    printf("\njumlah list: %d\n", NbElm(senarai2));
    PrintList(copySenarai2);
    printf("\njumlah list: %d\n", NbElm(senarai2));
    PrintList(copySenarai2);

    List3 copySenarai3;
    NbElm(copySenarai3);
    PrintList(copySenarai3);
    return 0;
}
