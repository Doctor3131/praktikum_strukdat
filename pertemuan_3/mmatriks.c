/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060123120035/Siriel Wafa Nuriel Fahri*/
/* Tanggal   : 13 September 2024*/
/***********************************/

#include <stdio.h>
#include "matriks.c"


int main() {
	/*kamus*/
	Matriks M;
	Matriks M1;
	int row;
	int col;
	
	/*algoritma*/
	initMatriks(&M);
	initMatriks(&M1);
	
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 3, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 3));
	
	// printf("\n\n");
	// printf("3\n");
	// addX(&M, 3, 3, 3);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 3, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 3));

	// printf("\n\n");
	// printf("3\n");
	// addX(&M, 3, 2, 2);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 3, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 3));

	// printf("\n\n");
	// printf("3\n");
	// addX(&M, 3, 2, 8);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 3, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 3));


	// printf("\n\n");
	// printf("1\n");
	// editX(&M, 1, 2, 2);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 1, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 1));

	printf("\n\n");
	// addX(&M, 3, 2, 8);
	// addX(&M, 1, 1, 1);
	addX(&M, 1, 1, 1);
	addX(&M, 2, 1, 2);
	addX(&M, 3, 2, 1);
	addX(&M, 4, 2, 2);

	addX(&M1, 1, 1, 1);
	addX(&M1, 2, 1, 2);
	addX(&M1, 3, 2, 1);
	addX(&M1, 4, 2, 2);
	// printf("%d\n\n", getSumMatriks(M));
	// printf("%f\n\n", getAverageMatriks(M));
	// printf("%d", getMaxMatriks(M));
	// printMatriks(kaliSkalarMatriks(M, 3));
	Matriks M2;
	initMatriks(&M2);
	
	// isiMatriksIdentitas(&M2, 4);
	isiMatriksRandom(&M2, 3, 3);
	viewMatriks(M2);
	// printf("\n\n");
	// printMatriks(M);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 3, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 3));

	// printf("\n\n");
	// printf("1\n");
	// addX(&M, 1, 1, 1);
	// printf("baris = %d\n", getNBaris(M));
	// printf("kolom = %d\n", getNKolom(M));
	// printf("apakah kosong: %d\n", isEmptyMatriks(M));
	// printf("apakah full: %d\n", isFullMatriks(M));
	// searchX(M, 1, &row, &col);
	// printf("nilai x ada di: (%d, %d)\n", row, col);
	// printf("banyak nilai x: %d\n", countX(M, 1));
	
	printf("\n\n");
	delX(&M, 2);
	printf("baris = %d\n", getNBaris(M));
	printf("kolom = %d\n", getNKolom(M));
	printf("apakah kosong: %d\n", isEmptyMatriks(M));
	printf("apakah full: %d\n", isFullMatriks(M));
	// printMatriks(M);
	return 0;

	
}
