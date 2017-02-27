#include <stdio.h>
#include <omp.h>
#include <unistd.h>
int main() {
	omp_set_num_threads(3);
	int exetime = 0, policy, chunk;	
	scanf("%d%d",&policy,&chunk);
	/*
		policy:
			1 = static
			2 = dynamic
			3 = guided
			4 = auto
	*/
	omp_set_schedule(policy, chunk);
	#pragma omp parallel for schedule(runtime) \
firstprivate(exetime)
	for(int i =17 ; i >= 0 ; i--) {
		sleep(i);
		exetime += i;
		printf("threadID = %d, Iteration = %d ,Exetime = %d\n",omp_get_thread_num(), i, exetime);
	}	
	return 0;
}
