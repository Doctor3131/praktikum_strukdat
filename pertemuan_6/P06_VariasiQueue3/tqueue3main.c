#include "tqueue3.c"
#include <stdio.h>

/* Program   : tqueue3main.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 08/10/2024*/
/***********************************/

int main(){
    tqueue3 a;
    createQueue3(&a);
    printf("index head: %d\n", head3(a));
    printf("index tail: %d\n", tail3(a));

    char b;
    
    b = 'p';
    enqueue3(&a, b);
    
    b = 'p';
    enqueue3(&a, b);
    
    b = 'p';
    enqueue3(&a, b);
    
    b = 'a';
    enqueue3(&a, b);

    dequeue3(&a, &b);
    dequeue3(&a, &b);
    dequeue3(&a, &b);

    
    b = 'b';
    enqueue3(&a, b);
    
    b = 'c';
    enqueue3(&a, b);
    
    b = 'b';
    enqueue3(&a, b);

    b = 'e';
    enqueue3(&a, b);

    printQueue3(a);
    printf("\n");
    viewQueue3(a);
    printf("\n");
    printf("%d\n", countMember(a, 'b'));

}