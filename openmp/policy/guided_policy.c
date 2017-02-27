#include <stdio.h>
#include <omp.h>
#include <unistd.h>
int main() {
	omp_set_num_threads(3);
	int exetime = 0;	
	#pragma omp parallel for schedule(guided, 1) \
firstprivate(exetime)
	for(int i = 0; i < 18 ; i++) {
		sleep(i);
		exetime += i;
		printf("threadID = %d, Iteration = %d ,Exetime = %d\n",omp_get_thread_num(), i, exetime);
	}	
	return 0;
}
