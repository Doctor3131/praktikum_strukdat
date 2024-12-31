/* Program   : mainTqueue.c */
/* Deskripsi : main program dari adt Tqueue */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 27 September 2024*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "tqueue.c"



int main(){
    
    /*
    tqueue A;
    createQueue(&A);

    printf("%c\n", infoHead(A));
    printf("%c\n", infoTail(A)); 
    printf("%d\n", sizeQueue(A));

    printQueue(A);
    printf("\n");
    viewQueue(A);

    // enque
    printf("enqueue\n");
    char e;
    e = 'b';
    enqueue(&A, e);
    e = 'c';
    enqueue(&A, e);
    printf("elemen di head: %c\n", infoHead(A));
    printf("elemen di tail: %c\n", infoTail(A));
    printf("size: %d\n", sizeQueue(A));

    printQueue(A);
    printf("\n");
    viewQueue(A);
    printf("\n");
    printf("\n");

    // deque
    printf("dequeue\n");
    
    dequeue(&A, &e);
    printf("ambil: %c\n", e);
    dequeue(&A, &e);
    printf("ambil: %c\n", e);
    dequeue(&A, &e);
    printf("ambil: %c\n", e);

    printf("elemen di head: %c\n", infoHead(A));
    printf("elemen di tail: %c\n", infoTail(A));
    printf("size: %d\n", sizeQueue(A));

    printQueue(A);
    printf("\n");
    viewQueue(A);
    printf("\n");
    printf("\n");
    */

    tqueue A;
    tqueue B;
    createQueue(&A);
    createQueue(&B);

    char e;
    e = 'a';
    enqueue(&A, e);
    enqueue(&A, e);
    enqueue(&A, e);
    enqueue(&A, e);
    enqueue(&A, e);
    enqueue(&A, e);
    enqueue(&A, e);

    e = 'b';
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);
    enqueue(&B, e);

    printQueue(A);
    printf("\n");
    printQueue(B);
    printf("\n");
    // printf("panjang terbanyak: %d\n", maxlength(A, B));

    char e1;
    e1 = 'c';
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);
    enqueue1(&A, e1);


    printf("\n");
    printQueue(A);
    printf("\n");

}