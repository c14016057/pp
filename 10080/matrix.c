#include "matrix.h"
#include <stdio.h>
#include <pthread.h> 
unsigned long *gA, *gC, *gB,TB[2048][2048] = {},gN,threadID[4] = {0, 1, 2, 3}, start[17];
void* mul(void* threadID) {
	int id = ((int *)threadID);
	int l = start[id], r = start[id+1];
	int N = gN;
	for (int i = l; i < r; i++)
		for (int j = 0; j < N; j++) {
			unsigned long sum = 0;
			for (int k = 0; k < N; k++)
				sum += gA[i*2048+k] * TB[j][k];	
			gC[i*2048+j] = sum;
		}
	pthread_exit (NULL);
}
void *paraT(void* threadID) {
	int id = (int *)threadID;
	for(int i = start[id]; i < start[id + 1]; i++)
		for(int j = 0; j < gN; j++) 
			TB[j][i] = gB[i*2048 + j];

}
void multiply(int N, unsigned long A[][2048], unsigned long B[][2048], unsigned long C[][2048]) {
	for(int i = 0; i < 17; i++) 
		start[i] = N* i/16; 
		//	{0, N/4, N/2, N*3/4, N};
	pthread_t pt[16];
	gA = &A[0][0];
	gB = &B[0][0];
	gC = &C[0][0];
	gN = N; 
    for (int i = 0; i < 16; i++)
		pthread_create (&pt[i], NULL, paraT, (void *)i);
	for (int i = 0; i < 16; i++)
		pthread_join (pt[i], NULL);
	for (int i = 0; i < 16; i++) 
		pthread_create (&pt[i], NULL, mul, (void *) i);
	for (int i = 0; i < 16; i++)
		pthread_join (pt[i], NULL);
}
