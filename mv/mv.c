#include <stdio.h>
#include <omp.h>
#include "mv_func.h"

int main () {
	int N = 10;
	double A[N][N], x[N];
	double * b;
	int i, j;
	
	for (i = 0; i < N; i++) {
		x[i] = i;
		for (j = 0; j < N; j++) {
			A[i][j] = i+j;
		}
	}

	/* printf("Matriz A\n\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%f	", A[i][j]);
		}
		printf("\n");
	}

	printf("\nVector X\n\n");
	for (i = 0; i < N; i++) {
		printf("%f\n", x[i]);
	} */

	double tic = omp_get_wtime();

	b = mv(A, N, N, x, N);

	double toc = omp_get_wtime();

	printf("\nVector b\n\n");
	for (i = 0; i < N; i++) {
		printf("%f\n", b[i]);
	} 
	printf("\nTardó: %f segundos.\n", toc-tic);
}
