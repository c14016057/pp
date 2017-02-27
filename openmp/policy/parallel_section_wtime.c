#include <stdio.h>
#include <assert.h>
#include <omp.h>
int a[10000][10000], b[10000][10000];
int main() {
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			double t = omp_get_wtime();
			for (int i = 0; i < 10000; i++)
				for (int j = 0; j < 10000; j++)
					a[i][j] = i + j;
			t = omp_get_wtime() - t;
			printf("first section use %lf time\n", t);
		}
		#pragma omp section
		{
			double t = omp_get_wtime();
			for (int i = 0; i < 10000; i++)
				for (int j = 0; j < 10000; j++)
					b[i][j] = i - j;
			t = omp_get_wtime() - t;
			printf("second section use %lf tiem\n", t);
		}		
	}
	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < 10000; i ++) {
			printf("threadID = %d\n",omp_get_thread_num());
			for (int j = 0; j< 10000; j++)
				assert(a[i][j] == i + j);
		}
		#pragma omp for
		for (int i = 0; i < 10000; i ++) {
			printf("threadID = %d\n",omp_get_thread_num());
			for (int j = 0; j< 10000; j++)
				assert(a[i][j] == i + j);
		}

	}
	return 0;
}
