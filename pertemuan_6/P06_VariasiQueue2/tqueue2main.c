#include "boolean.h"
#include "tqueue2.c"
#include <stdio.h>

/* Program   : tqueue2main.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 4 Oktober 2024*/
/***********************************/

int main(){
    // tqueue2 A;

    // createQueue2(&A);

    // char b;
    // b = 'a';
    // enqueue2(&A, b);

    // b = 'e';
    // enqueue2(&A, b);

    // b = 'e';
    // enqueue2(&A, b);

    // b = 'e';
    // enqueue2(&A, b);

    // b = 'z';
    // enqueue2(&A, b);


    // dequeue2(&A, &b);

    // dequeue2(&A, &b);

    // dequeue2(&A, &b);

    // dequeue2(&A, &b);


    // printQueue2(A);
    // printf("\n");

    // printf("tail q: %d\n", tail2(A));
    // printf("head q: %d\n", head2(A));    
    // printf("apakah kosong: %d\n", isEmptyQueue2(A));
    // printf("apakah full: %d\n", isFullQueue2(A));
    // printf("apakah satu element: %d\n", isOneElement2(A));
    // printf("infotail2: %c\n", infoTail2(A));
    // printf("infohead2: %c\n", infoHead2(A));
    // printf("panjang antrian: %d\n", sizeQueue2(A));
    // printQueue2(A);
    // printf("\n");
    // viewQueue2(A);
    // printf("\n");
    // printf("tailstop: %d\n", isTailStop(A));


    // b = 'z';
    // enqueue2(&A, b);

    // printQueue2(A);
    // printf("\n");
    // printf("tail q: %d\n", tail2(A));
    // printf("head q: %d\n", head2(A));  

    // printf("tail q: %d\n", tail2(A));
    // printf("head q: %d\n", head2(A));  
    // printQueue2(A);
    // printf("\n");
    // enqueue2N(&A, 1);
    // printf("tail q: %d\n", tail2(A));
    // printf("head q: %d\n", head2(A));  
    // printQueue2(A);
    // printf("\n");


    tqueue2 a;
    tqueue2 b;

    createQueue2(&a);
    createQueue2(&b);


    enqueue2(&a, 'v');
    enqueue2(&a, 'v');
    enqueue2(&a, 'a');
    enqueue2(&a, 'v');
    enqueue2(&b, 'v');
    enqueue2(&b, 'v');
    enqueue2(&b, 'v');



    char temp;
    dequeue2(&a, &temp);

    printQueue2(a);
    printf("\n");
    printQueue2(b);
    printf("\n");

    printf("%d\n", sizeQueue2(a));
    printf("%d\n", sizeQueue2(b));

    printf("%d", isEqualQueue2(a, b));
}
