#include <stdio.h>
#include <omp.h>

static long num_steps = 10000;
double step;
int main () {
	double x, pi, sum = 0.0;
	step = 1.0/(double) num_steps;
	
	omp_set_num_threads(num_steps);
	#pragma omp parallel
	{
		int i;
		i = omp_get_thread_num();
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	pi = step * sum;
	printf("%f\n", pi);
}
