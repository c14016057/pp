#include <stdio.h>
#include <omp.h>
#define N 3
int main() {
	omp_set_num_threads(4);
	#pragma omp parallel
	for	(int i = 0; i < 1; i++)	{
		int id = omp_get_thread_num();
//		if(omp_get_thread_num() == 0) while(1);
		printf("first for, id = %d\n",id);
		#pragma omp for
		for(int j = 0; j < N; j++) 
			printf("threadID = %d,i = %d, j = %d, id = %d\n",omp_get_thread_num(), i, j, id);
	}
	return 0;
}
