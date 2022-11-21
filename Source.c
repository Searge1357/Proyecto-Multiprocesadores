#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

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
	long double* new_arr;
	//long double* aux_arr;
	int arrSize = arrB.rows * arrB.columns;
	new_arr = (long double*)_aligned_malloc(sizeof(long double) * arrSize, sizeof(long double));
	//aux_arr = (long double*)malloc(sizeof(long double) * arrB.columns);

	//CHECK IF MEMORY ALLOCATED/
	if (new_arr == NULL) {
		printf("Memory no allocated");
		exit(EXIT_FAILURE);
	}
	/*if (aux_arr == NULL) {
		printf("Memory no allocated");
		exit(EXIT_FAILURE);
	}*/
	else {
		//TRANSPOSITION SECTION/
		for (int i = 0; i < arrB.rows; i++) {
			for (int j = 0; j < arrB.columns; j++) {
				new_arr[j * arrB.rows + i] = arr[i * arrB.columns + j];
			}
		}
	}
	printf("\n");

	return new_arr;
}
int main() {
	//siempre alinear los arreglos

	int num_readA, num_readB;
	struct arrs arrA, arrB, arrC;
	long double* ptrA;
	long double* ptrB;
	long double* ptrB_aux;
	long double* ptrC;

	//SET ARRAYS SIZES /
	printf("Enter size of rows and columns for array A: ");
	scanf_s("%d %d", &arrA.rows, &arrA.columns);

	printf("Enter size of rows and columns for array B: ");
	scanf_s("%d %d", &arrB.rows, &arrB.columns);

	arrC.columns = arrB.columns;
	arrC.rows = arrA.rows;

	if (arrA.columns != arrB.rows) {
		printf("\nNUMBER OF COLUMNS AND ROWS DOES NOT MATCH!! TRY AGAIN \n");
		exit(EXIT_FAILURE);
	}

	//OPEN FILES
	FILE* FileA = fopen("matrizA.txt", "r");
	FILE* FileB = fopen("matrizB.txt", "r");
	if (FileA == NULL) {
		printf("File A does not exist.");
		return 0;
	}
	if (FileB == NULL) {
		printf("File B does not exist.");
		return 0;
	}

	//CHECK IF MEMORY HAS BEEN ALLOCATED
	ptrA = (long double*)_aligned_malloc(((long double)arrA.columns * arrA.rows) * sizeof(long double), sizeof(long double));
	ptrB = (long double*)_aligned_malloc(((long double)arrB.columns * arrB.rows) * sizeof(long double), sizeof(long double));
	ptrC = (long double*)_aligned_malloc(((long double)arrA.rows * arrB.columns) * sizeof(long double), sizeof(long double));

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
		//printf("How many do elements you want to read for array A? ");
		//scanf_s("%d", &numElementsA);

		///* CHECK IF ARRAY SIZE CAN STORE NUMBER OF ELEMENTS THAT USER DESIRES TO READ*/
		//if (elementA_count != numElementsA) {
		//	printf("Size of the array doesn't match with the number of elements desired to read");
		//	exit(EXIT_FAILURE);
		//}

		//READ FILE AND STORE EACH ELEMENT IN THE CORRESPONDING ARRAY/
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

		//printf("How many do elements you want to read for array B? ");
		//scanf_s("%d", &numElementsB);

		///* CHECK IF ARRAY SIZE CAN STORE NUMBER OF ELEMENTS THAT USER DESIRES TO READ*/
		//if (elementB_count != numElementsB) {
		//	printf("Size of the array doesn't match with the number of elements desired to read");
		//	exit(EXIT_FAILURE);
		//}
		while (i < elementB_count) {
			if (feof(FileB)) {
				printf("Number of elements in the file are less than the desired number of elements");
				return 0;
			}
			fscanf(FileB, "%lf ", &ptrB[i]); //LLena la matriz con todos los valores
			i++;
		}
	}

	//TRANSPOSE ARR_B AND STORE IN NEW MEMORY BLOCK/
	ptrB_aux = matrixTransposition(arrB, ptrB);

	//Limpiar memoria 
	memset(ptrC, 0, sizeof(ptrC[0]) * arrC.columns * arrC.rows);

	//MATRIX MULTIPLICATION
	int aux = 0;
	for (int i = 0; i < arrA.rows; i++) {
		for (int j = 0; j < arrB.columns; j++) {
			for (int k = 0; k < arrA.columns; k++) {
				ptrC[aux] += ptrA[k + i * arrA.columns] * ptrB_aux[k + j * arrB.rows];
				//printf("%0.12f \n", ptrA[k + i * arrA.columns]);
				//printf("%0.12f \n", ptrB_aux[k + j * arrB.rows]);
			}
			aux++;
		}
	}


	_aligned_free(ptrB);
	_aligned_free(ptrA);

	FILE* FileC = fopen("matrizC.txt", "w");

	//PRINT VALUES OF RESULT ARRAY
	if (ptrC) {
		for (int i = 0; i < arrA.rows; i++) {
			for (int j = 0; j < arrB.columns; j++) {
				//printf("%0.10f  \t", ptrC[i * arrC.columns + j]);
				//fwrite(ptrC[i * arrC.columns + j], sizeof(long double), 1, FileC); 
				fprintf(FileC, "%0.12f \n", ptrC[i * arrC.columns + j]);
			}
		}
	}
	_aligned_free(ptrC);
	_aligned_free(ptrB_aux);
	return 0;
}
