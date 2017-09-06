#ifndef HELLO_H_
#define HELLO_H_

#include <omp.h>
#include <stdio.h>

int hello() {
	omp_set_num_threads(6);
	#pragma omp parallel
	{
	int ID = omp_get_thread_num();
	printf("Hello(%d)", ID);
	#pragma omp barrier
	printf(" world(%d) \n", ID);
	}
}

#endif
