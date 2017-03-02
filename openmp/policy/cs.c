#include <stdio.h>
#define N 1000000
int main() {
	int n = 0;
	#pragma omp parallel for
	for(int i = 0; i < 16; i++)
//		#pragma omp critical
		for(int j = 0; j < N; j++)
//			#pragma omp critical
			n++;
	printf("n = %d\n",n);
	return 0;
}
