#include <stdio.h>

int main () {
	int N = 5;
	int A[N][N], x[N], b[N];
	int i, j;
	
	for (i = 0; i < N; i++) {
		x[i] = i;
		for (j = 0; j < N; j++) {
			A[i][j] = i * j;
		}
	}

	for (i = 0; i < N; i++) {
		b[i] = 0;
		for (j = 0; j < N; j++) {
			b[i] += A[i][j] * x[j];
		}
	}

	for (i = 0; i < N; i++) {
		printf("%d\n", b[i]);
	}
}
