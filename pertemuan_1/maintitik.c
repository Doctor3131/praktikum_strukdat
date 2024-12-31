/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 29, Agustus 2024, 14.38*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main(){

	// Titik A;

	// makeTitik(&A);

	// geserXY(&A, 3, 4);

	// printf("%d", getAbsis(A));


	Titik A;
	Titik B;

	makeTitik(&A);
	makeTitik(&B);

	setAbsis(&A, 3);
	setOrdinat(&B, 4);

	printf("%d\n", getAbsis(A));
	printf("%d\n", getOrdinat(B));
	printf("%.2f", Jarak(A, B));

	return 0;
}
