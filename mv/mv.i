%module mv
%{
#define SWIG_FILE_WITH_INIT
#include "mv_func.h"
%}

%include "numpy.i"
%init %{
import_array();
%}

%apply (double* IN_ARRAY2, int DIM1, int DIM2){(double A[][10], int N)};
%apply (double* IN_ARRAY1, int DIM1){(double x[], int M, int K)};
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
