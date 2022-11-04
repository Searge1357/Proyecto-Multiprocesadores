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
	FILE* of_A;
	FILE* of_B;
	FILE* of_C;
	errno_t err;
	long double x;

	/Open files/
	err = fopen_s(&of_A, "matrixA2500.txt", "r");
	if (err == 0)
	{
		printf("The file 'matrixA2500.txt' was opened\n");
		fread_s(&x, sizeof(long double), sizeof(long double), 1, of_A);
		printf("%lf\n", x);
	}
	else
	{
		printf("The file 'matrixA2500.txt' was not opened\n");
		exit(EXIT_FAILURE);
	}

	err = fopen_s(&of_B, "matrixB2500.txt", "r");
	if (err == 0)
	{
		printf("The file 'matrixB2500.txt' was opened\n");
	}
	else
	{
		printf("The file 'matrixB2500.txt' was not opened\n");
		exit(EXIT_FAILURE);
	}

	/SET ARRAYS SIZES/
	printf("Enter size of rows and columns for array A: ");
	scanf_s("%d %d", &arrA.rows, &arrA.columns);

	printf("Enter size of rows and columns for array B: ");
	scanf_s("%d %d", &arrB.rows, &arrB.columns);

	if (arrA.columns != arrB.rows) {
		printf("\nNUMBER OF COLUMNS AND ROWS DOES NOT MATCH!! TRY AGAIN \n");
		exit(EXIT_FAILURE);
	}

	//CHECK IF MEMORY HAS BEEN ALLOCATED
	ptrA = (double*)malloc(((double)arrA.columns * arrA.rows) * sizeof(double));
	ptrB = (double*)malloc(((double)arrB.columns * arrB.rows) * sizeof(double));
	ptrB_aux = (double*)malloc(((double)arrB.columns * arrB.rows) * sizeof(double));
	//printf("0x%x\n", &ptrA);
	/FILL ARRAYS  WITH INPUT FILE DATA/
	if (ptrA == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		int bufferA_size = arrA.columns * arrA.rows * sizeof(double);
		int elementA_count = arrA.columns * arrA.rows;
		//num_readA = fread_s(ptrA, bufferA_size, sizeof(double), elementA_count, of_A);

		////for (int i = 0; i < elementA_count; i++) {
		//fread_s(&x, sizeof(double), sizeof(double), 1, of_A);
		//printf("%lf\n", x);
		//}
	}

	if (ptrB == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		for (int i = 0; i < arrB.columns * arrB.rows; i++)
			ptrB[i] = (double)i + 1;
	}

	////PRINT VALUES INSIDE ARRAYS
	if (ptrA) {
		for (int i = 0; i < arrA.rows; i++) {
			for (int j = 0; j < arrA.columns; j++) {
				printf("%lf \t", ptrA[i * arrA.columns + j ]);
			}
			printf("\n");
		}
	}

	//printf("\n\n");

	//if (ptrB) {
	//	for (int i = 0; i < arrB.rows; i++) {
	//		for (int j = 0; j < arrB.columns; j++) {
	//			printf("%lf \t", ptrB[i * arrB.columns + j]);
	//		}
	//		printf("\n");
	//	}
	//}

	free(ptrA);
	free(ptrB);

	return 0;
}