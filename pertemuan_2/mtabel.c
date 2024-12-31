#include <stdio.h>
#include "tabel.c"
/*Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal : 6, September 2024*/

int main() {
	/*kamus*/
	Tabel T1;

	/*algoritma*/
	createTable(&T1);
	addXTable(&T1, 2);
	addXTable(&T1, 3);
	addXTable(&T1, 6);
	addXTable(&T1, 3);
	addXTable(&T1, 9);
	addXTable(&T1, 3);
	addXTable(&T1, 7);
	// printTable(T1);
	// printf("size = %d", getSize(T1));
	// printf("\n");
	// populate2(&T1);
	// printf("\n");
	// printf("size = %d\n", getSize(T1));
	// printTable(T1);
	// printf("\n");
	// printf("\n");
	// viewTable(T1);
	// printf("\n");
	// printf("\n");
	// printf("sum = %d\n", SumEl(T1));
	// printf("avg = %f\n", AverageEl(T1));
	// printf("max = %d\n", getMaxE/l(T1));
	// printf("min = %d\n", getMinEl(T1));
	// populate2(&T1);
	// printf("\n");
	printTable(T1);
	printf("\n");
	sortDesc(&T1);
	printTable(T1);

	//printf("%d", searchX(T,6));
	//addXTable(&T1,6);
	// printTable(T1);
	//delXTable(&T1,6);
	//printTable(T1);
	//dst ...
	return 0;
}
