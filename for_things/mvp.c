#include <stdio.h>
#include <omp.h>

int main () {
	int N = 5;
	double A[N][N], x[N], b[N], part;
	int i, j;
	
	for (i = 0; i < N; i++) {
		x[i] = i;
		for (j = 0; j < N; j++) {
			A[i][j] = i;
		}
	}

	for (i = 0; i < N; i++) {
		part = 0.0;
		#pragma omp parallel for reduction (+:part)
		for (j = 0; j < N; j++) {
			part += A[i][j] * x[j];
		}
		b[i] = part;
	}

	for (i = 0; i < N; i++) {
		printf("%f\n", b[i]);
	}
}
