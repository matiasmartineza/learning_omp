#include <stdio.h>
#include <omp.h>
#include <math.h>

int main() {
	int i;
	double tic = omp_get_wtime();
	omp_set_num_threads(2);
	#pragma omp parallel for
	for (i = 1; i < 1000000; i++) {
		printf("%f\n", pow(i, 4));
	}
	double toc = omp_get_wtime();
	printf("Tardó %f [s]\n", toc-tic);
}
