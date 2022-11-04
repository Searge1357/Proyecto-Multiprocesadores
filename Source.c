#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

struct arrs
{
	int columns;
	int rows;
};

/*MATRIX TRANSPOSITION
	-arr1: transposed matrix
	-arr2: original matrix
*/
void matrixTransposition(double* arr1, double* arr2) {

}

void fillArray(double* arr) {

}


int main() {
	//siempre alinear los arreglos
	//transposición
	int num_readA, num_readB;
	struct arrs arrA, arrB, arrC;
	double* ptrA;
	double* ptrB;
	double* ptrB_aux;
	/*FILE* of_A;
	FILE* of_B;
	FILE* of_C;
	errno_t err;
	long double x;*/

	//SET ARRAYS SIZES /
	printf("Enter size of rows and columns for array A: ");
	scanf_s("%d %d", &arrA.rows, &arrA.columns);

	printf("Enter size of rows and columns for array B: ");
	scanf_s("%d %d", &arrB.rows, &arrB.columns);

	if (arrA.columns != arrB.rows) {
		printf("\nNUMBER OF COLUMNS AND ROWS DOES NOT MATCH!! TRY AGAIN \n");
		exit(EXIT_FAILURE);
	}

	//Open files 

	FILE* FileA = fopen("matrixA2500.txt", "r");
	FILE* FileB = fopen("matrixB2500.txt", "r");
	if (FileA == NULL) {
		printf("File A does not exist.");
		return 0;
	}
	if (FileB == NULL) {
		printf("File B does not exist.");
		return 0;
	}


	//CHECK IF MEMORY HAS BEEN ALLOCATED
	ptrA = (double*)malloc(((double)arrA.columns * arrA.rows) * sizeof(double));
	ptrB = (double*)malloc(((double)arrB.columns * arrB.rows) * sizeof(double));
	ptrB_aux = (double*)malloc(((double)arrB.columns * arrB.rows) * sizeof(double));

	// FILL ARRAYS  WITH INPUT FILE DATA /
	//Array A
	if (ptrA == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		int elementA_count = arrA.columns * arrA.rows;
		int i = 0;
		while (i < elementA_count) {
			if (feof(FileA)) {
				printf("Se llego al final del archivo");
				return 0;
			}
			fscanf(FileA, "%lf ", &ptrA[i]); //LLena la matriz con todos los valores
			i++;
		}
	}

	//Array B
	if (ptrB == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		int elementB_count = arrB.columns * arrB.rows;
		int i = 0;
		while (i < elementB_count) {
			if (feof(FileB)) {
				printf("Se llego al final del archivo");
				return 0;
			}
			fscanf(FileB, "%lf ", &ptrB[i]); //LLena la matriz con todos los valores
			i++;
		}
	}



	////PRINT VALUES INSIDE ARRAYS
	/*if (ptrA) {
		for (int i = 0; i < arrA.rows; i++) {
			for (int j = 0; j < arrA.columns; j++) {
				printf("%0.12f \t", ptrA[i * arrA.columns + j]);
			}
			printf("\n");
		}
	}*/

	//printf("\n\n");

	/*if (ptrB) {
		for (int i = 0; i < arrB.rows; i++) {
			for (int j = 0; j < arrB.columns; j++) {
				printf("%0.12f \n", ptrB[i * arrB.columns + j]);
			}
			printf("\n");
		}
	}*/

	free(ptrA);
	free(ptrB);

	return 0;
}