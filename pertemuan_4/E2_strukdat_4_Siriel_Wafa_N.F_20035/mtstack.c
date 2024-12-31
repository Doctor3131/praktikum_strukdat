/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 20 September 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
#include "boolean.h"
/* include tstack+boolean */

/*disini saya menggunakan dua fungsi pembantu guna mencari palindrome.
  kenapa saya menggunakan parameter stack di kedua nya karena saya salah paham
  kalau ternyata argumen untuk palindrome harus string :(
*/
void getReverse(Tstack A, Tstack *E){
	// kamus lokal
	char temp;
	char data;
	// algoritma
	while(top(A) >= 1){
		pop(&A, &temp);
		push(&(*E), temp);
	}
}

boolean cekSama(Tstack A, Tstack E){
	// kamus lokal
	boolean cek;
	char c1;
	char c2;

	// algoritma
	cek = true;
	while (cek && top(A) > 0){
		pop(&A, &c1);
		pop(&E, &c2);
		if(c1 != c2){
			cek = false;
		}
	}
	return cek;
}

boolean Palindrome(char data[]){
	// kamus lokal
	int i;
	Tstack B;
	Tstack E;

	// algoritma
	createStack(&B);
	createStack(&E);

	for (i = 0; data[i] != '\0'; i++){
		push(&B, data[i]);
	}

	getReverse(B, &E);

	return cekSama(B, E);
}


int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	
	/* algoritma */
	createStack(&A);
	// printStack(A);
	// printf("\n%d", isFullStack(A));
	// printf("\n%d\n", isEmptyStack(A));
	// push(&A, 'r');
	// printStack(A);
	// printf("\n%d", isFullStack(A));
	// printf("\n%d", isEmptyStack(A));
	// printf("\n%d", top(A));

	// char e;
	// pop(&A, &e);
	// printf("\n%c", e);
	// printf("\n%d", top(A));
	push(&A, 'm');
	// printf("\n%d", top(A));

	push(&A, 'a');
	// printf("\n%d", top(A));

	push(&A, 'l');
	// printf("\n%d", top(A));

	push(&A, 'a');
	// printf("\n%d", top(A));

	push(&A, 'm');

	// printf("\n");
	// printStack(A);
	// printf("\n");
	// char e;
	// pop(&A, &e);
	// printf("\n%c", e);
	// printf("\n%d\n", top(A));
	// viewStack(A);

	// palindrome
	// membuat fungsi pembantu berupa getReverse
	// Tstack E;
	// createStack(&E);
	// getReverse(A, &E);
	// printStack(E);
	// printf("\n%d\n", top(E));
	// printf("\n");
	// printStack(A);
	// printf("\n%d\n", top(A));
	// printf("%d", Palindrome("adadda"));
	// pushN(&A, 7);
	// printStack(A);
	char H; 
	pushZuma(&A, H);
	printStack(A);
}
