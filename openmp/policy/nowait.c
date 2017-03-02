#include <stdio.h>
#include <omp.h>
int main() {
	#pragma omp parallel
	{
		#pragma omp for //nowait
		for(int i = 0; i < 3; i++)
			if(i == 0) while(1);
		#pragma omp for //schedule(dynamic, 1)
		for(int i =0; i < 3; i++)
			printf("%d\n",i);

	}
	return 0;
}
