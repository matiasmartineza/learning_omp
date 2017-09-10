#include <stdio.h>
#include <omp.h>

int main () {
	int p = 0;
	int i;
	double tic = omp_get_wtime();
	#pragma omp parallel for
	for (i = 1; i < 10001; i++) {
		#pragma omp critical
		p += i;
	}
	double toc = omp_get_wtime();
	printf("The sum is %d. I took %f seconds.\n", p, toc-tic);
}
