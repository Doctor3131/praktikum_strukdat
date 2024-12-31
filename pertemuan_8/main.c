/* File : main.c */
/* Deskripsi : Realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120035 & Siriel Wafa Nuriel Fahri*/
/* Tanggal : 11/11/2024*/

#include <stdio.h>
#include "list2.c"

int main() {
    address A, B;
    infotype a, b, c, d, f, g, h, i;
    List2 senarai;

    a = 'a';
    b = 'g';
    c = 'n';
    d = 'l';
    f = 'f';
    g = 'u';
    h = 'w';
    i = 'q';
    CreateList(&senarai);
    
    InsertVFirst(&senarai, a);
    InsertVFirst(&senarai, b);
    // InsertVFirst(&senarai, c);
    // InsertVFirst(&senarai, d);

    // InsertVLast(&senarai, f);
    // InsertVLast(&senarai, g);
    // InsertVLast(&senarai, h);
    // InsertVLast(&senarai, i);

    PrintList(senarai);
    printf("\nbanyak elemen: %d",NbElm(senarai));

    // infotype temp;
    // DeleteVFirst(&senarai, &temp);
    // printf("\n\n%c", temp);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));

    // infotype temp1;
    // DeleteVLast(&senarai, &temp1);
    // printf("\n\n%c", temp1);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));

    // infotype temp2;
    // temp2 = 'g';
    // printf("\nelemen yang di hapus %c", temp2);
    // DeleteX(&senarai, temp2);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));
    // printf("\nthe first elm: %c", info(First(senarai)));

    // infotype temp3;
    // address Atemp;
    // temp3 = 'u';
    // printf("\n\ndicari X: %c", temp3);
    // SearchX(senarai, temp3, &Atemp);
    // if (Atemp != NIL){
    // printf("\nisi A: %c", info(Atemp));
    // }
    // else {
    //     printf("*A: NIL");
    // }
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));

    // infotype temp4;
    // infotype temp5;
    // temp4 = 'h';
    // temp5 = 'a';
    // printf("\n\nelemen %c ditukar %c", temp4, temp5);
    // UpdateX(&senarai, temp4, temp5);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));    

    // printf("\n\ninvers: ");
    // Invers(&senarai);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));  
    
    // printf("\n\nCountX\n");
    // infotype temp6;
    // temp6 = 'a';
    // printf("Banyaknya %c: %d\n", temp6, CountX(senarai, temp6));

    // printf("\n\nfrekuensi\n");
    // infotype temp7;
    // temp7 = 'a';
    // printf("banyaknya kemunculan %c: %f\n", temp7, FrekuensiX(senarai, temp7));
    
    // printf("\n\nCountVocal\n");
    // printf("banyaknya kemunculan huruf vocal: %d\n", CountVocal(senarai));
    
    // printf("\n\nCountNG\n");
    // printf("banyaknya kemunculan: %d\n", CountNG(senarai));
    
    // // InsertVAfterX,
    // infotype IVA = 'o';
    // infotype IVAN = 'q';
    // printf("\n\ninsert %c after %c: \n", IVA, IVAN);
    // InsertVAfterX(&senarai, IVAN, IVA);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));  

    // // InsertVBeforeX,
    // infotype IVB = 'j';
    // infotype IVBN = 'o';
    // printf("\n\ninsert %c before %c: \n", IVB, IVBN);
    // InsertVBeforeX(&senarai, IVBN, IVB);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));  

    // DeleteVAfterX,
    // infotype DVX = 'u';
    // infotype DVA;
    // printf("\n\ndelete after %c: \n", DVX);
    // DeleteVAfterX(&senarai, DVX, &DVA);
    // PrintList(senarai);
    // printf("\nbanyak elemen: %d",NbElm(senarai));
    // printf("\nisi yang dihapus: %C", DVA);  
    
    infotype DVX2 = 'a';
    infotype DVBA;
    printf("\n\ndelete before %c: \n", DVX2);
    DeleteVBeforeX(&senarai, DVX2, &DVBA);
    PrintList(senarai);
    printf("\nbanyak elemen: %d",NbElm(senarai));
    printf("\nisi yang dihapus: %C", DVBA); 
    return 0;
}
