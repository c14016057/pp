#include <stdio.h>
/*
every #for/section in #paralle will join
*/
int main() {
	int i = 0, j =10000;
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				while(++i<10000) printf("%d\n",i);
			}
			#pragma omp section
			{
				while(--j) printf("%d\n",j);
			}
		}
		#pragma omp for
		for(int i = 0; i < 10; i++)
			printf("for loop\n");
	}	
	return 0;
}
