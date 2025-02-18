#include "boolean.h"
#include "tqueue3.h"
#include <stdio.h>

/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 08/10/2024*/
/***********************************/


/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    // kamus lokal

    // algoritma
    if(tail3(Q) == 0){
        return true;
    }
    else{
        return false;
    }
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    // kamus lokal

    // algoritma
    if((tail3(Q) % 5) + 1 == head3(Q)){
        return true;
    }
    else{
        return false;                    
    }
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    // kamus lokal

    // algoritma
    if(head3(Q) == tail3(Q) && head3(Q) != 0){
        return true;
    }
    else{
        return false;
    }
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    // kamus lokal
    int i;
    // algoritma
    for(i = 0; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    // kamus lokal

    // algoritma
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    // kamus lokal

    // algoritma
    return Q.tail;
}


/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    // kamus lokal

    // algoritma
    return Q.wadah[head3(Q)];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    // kamus lokal

    // algoritma
    return Q.wadah[tail3(Q)];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    // kamus lokal

    // algoritma
    if (isEmptyQueue3(Q)) {
        return 0;
    }
    else if(head3(Q) <= tail3(Q)){
        return tail3(Q) - head3(Q) + 1;
    }
    else{
        return 5 - head3(Q) + 1 + tail3(Q); 
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q){
    // kamus lokal
    int i;

    // algoritma
    printf("[");
    for (i = 1; i <= 4; i++) {
        printf("%c, ", Q.wadah[i]);
    }
    printf("%c]", Q.wadah[i]);
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    // kamus lokal
    int i;

    // algoritma
    printf("[");
    if(!isEmptyQueue3(Q)){
        if (head3(Q) <= tail3(Q)) {
            for (i = head3(Q); i < tail3(Q); i++) {
                printf("%c, ", Q.wadah[i]);
            }
        } 
        else{
            for (i = head3(Q); i <= 5; i++) {
                printf("%c, ", Q.wadah[i]);
            }
            for (i = 1; i < tail3(Q); i++) {
                printf("%c, ", Q.wadah[i]);
            }
        }
        printf("%c", Q.wadah[tail3(Q)]);
    }
    printf("]");
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    // kamus lokal

    // algoritma
    if (!isFullQueue3(*Q)) {
        if(isEmptyQueue3(*Q)){
            (*Q).head = 1;
            (*Q).tail = 1;
        } 
        else{
            (*Q).tail = ((*Q).tail % 5) + 1;
        }
        (*Q).wadah[(*Q).tail] = E;
    }
}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    // kamus lokal

    // algoritma
    if (isEmptyQueue3(*Q)) {
        *E = ' ';
    }
    *E = infoHead3(*Q);
    (*Q).wadah[(*Q).head] = '#';

    if (isOneElement3(*Q)) {
        (*Q).head = 0;
        (*Q).tail = 0;
    } 
    else{
        (*Q).head = ((*Q).head % 5) + 1;
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    // kamus lokal

    // algoritma
    if(tail3(Q) < head3(Q) && !isEmptyQueue3(Q)){
        return true;
    }
    else{
        return false;
    }
}

/*function countMember(Q:tQueue3, E:character) -> boolean
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E){
    // kamus lokal
    int i;
    int count;

    // algoritma
    count = 0;
    if (!isEmptyQueue3(Q)) {
        if(!isTailOverHead(Q)){
            for (i = head3(Q); i <= tail3(Q); i++) {
                if (Q.wadah[i] == E) {
                    count++;
                }
            }
        } 
        else{
            for(i = head3(Q); i <= 5; i++){
                if (Q.wadah[i] == E) {
                    count++;
                }
            }
            for(i = 1; i <= tail3(Q); i++){
                if (Q.wadah[i] == E) {
                    count++;
                }
            }
        }
    }
    return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E){
    // kamus lokal

    // algoritma
    if (!isFullQueue3(*Q) && countMember(*Q, E) == 0) {
        enqueue3(Q, E);
    }
}
