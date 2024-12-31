#include "boolean.h"
#include "tqueue2.h"
#include <stdio.h>

/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 4 Oktober 2024*/
/***********************************/

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
// kamus lokal

// algoritma
    if(tail2(Q) == 0){
        return true;
    }
    else{
        return false;
    }
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
// kamus lokal

// algoritma
    if(tail2(Q) == 5){
        return true;
    }
    else{
        return false;
    }
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
// kamus lokal

// algoritma
    if(head2(Q) == tail2(Q) && !isEmptyQueue2(Q)) {
        return true;
    }
    else{
        return false;
    }
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q){
// kamus lokal
    int i;

// algoritma
    for(i = 0; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
// kamus lokal

// algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
// kamus lokal

// algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
// kamus lokal

// algoritma
    return Q.wadah[head2(Q)];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
// kamus lokal

// algoritma
    return Q.wadah[tail2(Q)];
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
// kamus lokal

// algoritma
    if(!isEmptyQueue2(Q)){
        return tail2(Q) - head2(Q) + 1; 
    }
    else{
        return 0;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
// kamus lokal
    int i;

// algoritma
    printf("[");
    for(i = 1; i <= 4; i++){
        printf("%c,", Q.wadah[i]);
    }
    printf("%c]", Q.wadah[i]);
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
// kamus lokal
    int i;

// algoritma
    printf("[");
    if(!isEmptyQueue2(Q)){
        for(i = head2(Q); i < tail2(Q); i++){
            printf("%c,", Q.wadah[i]);
        }
        printf("%c", Q.wadah[i]);
    }
    printf("]");
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
// kamus lokal

// algoritma
    if(isFullQueue2(Q)){
        return true;
    }
    else{
        return false;
    }
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
// kamus lokal
    int i;
    int temp;
// algoritma
    temp = 1;
    if(isTailStop(*Q) && head2(*Q) > 1){
        for(i = head2(*Q); i <= tail2(*Q); i++){
            (*Q).wadah[temp] = (*Q).wadah[i];
            (*Q).wadah[i] = '#';
            temp++;
        }
        (*Q).head = 1;
        (*Q).tail = temp - 1;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
// kamus lokal

// algoritma
    resetHead(&(*Q));
    if(!isFullQueue2(*Q)){
        (*Q).wadah[tail2(*Q)+1] = E;
        (*Q).tail++; 
    
        if(isOneElement2(*Q)){
            (*Q).head = 1;
        }
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
// kamus lokal
    int i;

// algoritma
    if(isEmptyQueue2(*Q)){
        *E = '@';
    }
    else{
        *E = infoHead2(*Q);
        (*Q).wadah[head2(*Q)] = '#';
        (*Q).head++;
        if(head2(*Q) > tail2(*Q)){
            (*Q).head = 0;
            (*Q).tail = 0;
        }
    }
}


/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboaraad, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
// kamus lokal
    int i;
    char temp;
// algoritma
    for(i = 1; i <= N; i++){
        scanf(" %c", &temp);
        enqueue2(&(*Q), temp);
    }
}


/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
// kamus lokal
    char a;
    char b;
    int temp;
    boolean check;
// algoritma
    check = false;
    if(sizeQueue2(Q1) == sizeQueue2(Q2)){
        check = true;
        temp = sizeQueue2(Q1);
        while(temp > 0){
            dequeue2(&Q1, &a);
            dequeue2(&Q2, &b);
            if(a != b){
                check = false;
                temp = 0;
            }
            temp--;
        }
    }
    return check;
}