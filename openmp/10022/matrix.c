#include "matrix.h"
 
void multiply(int N, unsigned long A[][2048], unsigned long B[][2048], unsigned long C[][2048]) {
static int BB[2048][2048];
#pragma omp parallel
{
#pragma parallel for
	for (int i = 0;i < N; i++)
		for(int j = 0; j < N; j++)
			BB[i][j]=B[j][i];
#pragma  parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            unsigned long sum = 0;    // overflow, let it go.
            for (int k = 0; k < N; k++)
                sum += A[i][k] * BB[j][k];
            C[i][j] = sum;
        }
    }
}
}
