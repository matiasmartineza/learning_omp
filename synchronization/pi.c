#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int num_threads = 4;

int main() {
	int i;
	double pi = 0.0;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(num_threads);

	double tic = omp_get_wtime();

	#pragma omp parallel
	{
	double x, sum = 0.0, part;
	int thread = omp_get_thread_num();
	for (i = (thread) * (num_steps/num_threads) ; i <(thread+1)*( num_steps / num_threads); i++) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / ( 1.0 + x * x);
	}

	part = step * sum;
	#pragma omp critical
		pi += part;
	}

	double toc = omp_get_wtime();

	printf("%f, en %f segundos.\n", pi, toc - tic);
}
