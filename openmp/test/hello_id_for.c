#include <stdio.h>
#include <omp.h>
int main() {
	#pragma omp parallel for
	for(int i = 0 ;i < 48; i++)
		printf("hello, I am no.%d thread %d iteration\n",omp_get_thread_num(),i);
	return 0;
}
