#ifndef MV_H_
#define MV_H_

#include <omp.h>
#include <stdio.h>


double * mv (double A[][], int N, int K, double x[], int M) {

	K = 10
	static double b[K];
	int i, j;
	
	/*#pragma omp parallel for schedule(static)*/ 
	for (i = 0; i < N; i++) {
		b[i] = 0;
		for (j = 0; j < N; j++) {
			b[i] += A[i][j] * x[j];
		}
	}
	
	return b;
}

#endif
