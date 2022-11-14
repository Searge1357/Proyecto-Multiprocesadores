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
	- ARRB: ARR STRUCT THAT CONTAINS ORIGINAL SIZE
	- ARR: LONG DOUBLE POINTER THAT POINTS TO ARRAY HOLDING ELEMENTS READ FROM INPUT FILE
*/
double long* matrixTransposition(struct arrs arrB, long double* arr) {
	long double* aux_arr;
	int arrSize = arrB.rows * arrB.columns;
	aux_arr = (long double*)malloc(sizeof(long double) * arrSize);

	/CHECK IF MEMORY ALLOCATED/
	if (aux_arr == NULL) {
		printf("Memory no allocated");
		exit(EXIT_FAILURE);
	}
	else {
		/TRANSPOSITION SECTION/
		for (int i = 0; i < arrB.rows; i++) {
			for (int j = 0; j < arrB.columns; j++) {
				aux_arr[i * arrB.columns + j] = arr[(j*arrB.columns) + i];
			}
		}
	}

	/PRINT AUX_ARR ELEMENTS/
	//if (aux_arr) {
	//	for (int i = 0; i < arrB.columns; i++) {
	//		for (int j = 0; j < arrB.rows; j++) {
	//			printf("%0.12f  \t", aux_arr[i * arrB.columns + j]);
	//		}
	//		printf("\n");
	//	}
	//}
	//printf("\n");

	return aux_arr;
}

int main() {
	//siempre alinear los arreglos

	int num_readA, num_readB;
	struct arrs arrA, arrB, arrC;
	long double* ptrA;
	long double* ptrB;
	long double* ptrB_aux;

	//SET ARRAYS SIZES /
	printf("Enter size of rows and columns for array A: ");
	scanf_s("%d %d", &arrA.rows, &arrA.columns);

	printf("Enter size of rows and columns for array B: ");
	scanf_s("%d %d", &arrB.rows, &arrB.columns);

	if (arrA.columns != arrB.rows) {
		printf("\nNUMBER OF COLUMNS AND ROWS DOES NOT MATCH!! TRY AGAIN \n");
		exit(EXIT_FAILURE);
	}

	//OPEN FILES
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
	ptrA = (long double*)malloc(((long double)arrA.columns * arrA.rows) * sizeof(long double));
	ptrB = (long double*)malloc(((long double)arrB.columns * arrB.rows) * sizeof(long double));


	// FILL ARRAYS  WITH INPUT FILE DATA 
	//Array A
	if (ptrA == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		int elementA_count = arrA.columns * arrA.rows;
		int numElementsA;
		int i = 0;
		printf("How many do elements you want to read for array A? ");
		scanf_s("%d", &numElementsA);

		/* CHECK IF ARRAY SIZE CAN STORE NUMBER OF ELEMENTS THAT USER DESIRES TO READ*/
		if (elementA_count != numElementsA) {
			printf("Size of the array doesn't match with the number of elements desired to read");
			exit(EXIT_FAILURE);
		}

		/READ FILE AND STORE EACH ELEMENT IN THE CORRESPONDING ARRAY/
		while (i < elementA_count) {
			if (feof(FileA)) {
				printf("Number of elements in the file are less than the desired number of elements");
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
		int numElementsB;
		int i = 0;

		printf("How many do elements you want to read for array B? ");
		scanf_s("%d", &numElementsB);

		/* CHECK IF ARRAY SIZE CAN STORE NUMBER OF ELEMENTS THAT USER DESIRES TO READ*/
		if (elementB_count != numElementsB) {
			printf("Size of the array doesn't match with the number of elements desired to read");
			exit(EXIT_FAILURE);
		}
		while (i < elementB_count) {
			if (feof(FileB)) {
				printf("Number of elements in the file are less than the desired number of elements");
				return 0;
			}
			fscanf(FileB, "%lf ", &ptrB[i]); //LLena la matriz con todos los valores
			i++;
		}
	}

	/TRANSPOSE ARR_B AND STORE IN NEW MEMORY BLOCK/
	ptrB_aux = matrixTransposition(arrB, ptrB);

	//if (ptrB) {
	//	for (int i = 0; i < arrB.rows; i++) {
	//		for (int j = 0; j < arrB.columns; j++) {
	//			printf("%0.12f  \t", ptrB[i * arrB.columns + j]);
	//		}
	//		printf("\n");
	//	}
	//}
	//printf("\n");

	free(ptrB);

	//PRINT VALUES INSIDE ARRAYS
	if (ptrA) {
		for (int i = 0; i < arrA.rows; i++) {
			for (int j = 0; j < arrA.columns; j++) {
				printf("%0.12f  \t", ptrA[i * arrA.columns + j]);
			}
		printf("\n");
		}
	}

	printf("\n\n");

	free(ptrA);
	return 0;
}
