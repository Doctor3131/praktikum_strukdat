/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 20 September 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */


/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    // kamus lokal
    int i;

    // algoritma
    for(i = 1; i <= 10; i++){
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    if(top(T) == 0){
        return true;
    }
}

/*function bk( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    if(top(T) == 10){
        return true;
    }
    else{
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    // kamus lokal

    // algoritma
    if(!isFullStack(*T)){
        (*T).wadah[top(*T) + 1] = E;
        top(*T)++;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    // kamus lokal
    int i;

    // algoritma
    *X = infotop(*T);
    (*T).wadah[top(*T)] = '#';
    top(*T)--; 
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    // kamus lokal
    int i;

    // algoritma
    for(i = 1; i <= 9; i++){
        printf("%c;", T.wadah[i]);
    }
    printf("%c", T.wadah[i]);
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    // kamus lokal
    int i;

    // algoritma
    while(top(T) > 1){
        printf("%c;", infotop(T));
        top(T)--;
    }
    printf("%c", infotop(T));
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    // kamus lokal
    char temp;

    // algoritma
    if(11 - top(*T) > N){
        while(N > 0){
            scanf(" %c", &temp);
            push(&(*T), temp);
            N--;
        }
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    // kamus lokal

    // algoritma
    while (E != '0') {
        printStack(*T);
        printf("\n");
        scanf(" %c", &E);

        if(!isFullStack(*T)){
            push(&(*T), E);
        }
        else{
            createStack(&(*T));
        }

    }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    // kamus lokal

    // algoritma
    while (E != '0') {
        printStack(*T);
        printf("\nmasukan elemen: ");
        scanf(" %c", &E);

        if(infotop(*T) == E){
            pop(&(*T), &E);

        }
        else{
            push(&(*T), E);
        }
    }

}