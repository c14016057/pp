#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include "utils.h" 
#define MAXN 10000005
#define MAX_THREAD 4
uint32_t prefix_sum[MAXN];
int n,start[MAX_THREAD],end[MAX_THREAD],tid[MAX_THREAD] = {0, 1, 2, 3};
uint32_t offset[5];
uint32_t key;
void *tsum(void* n) {
	int id = *((int *)n);
	uint32_t sum = 0;
	for(int i = start[id]; i <=end[id]; i++) {
		sum += encrypt(i, key);
		prefix_sum[i] = sum;
	} 
	pthread_exit(NULL);
}
void *toffset(void* n) {
	int id = *((int *)n);
	int off = offset[id];
	for(int i = start[id]; i <= end[id]; i++)
		prefix_sum[i] += off;
	pthread_exit(NULL);

}
int main() {
	pthread_t pt[MAX_THREAD];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    while (scanf("%d %" PRIu32, &n, &key) == 2) {
		int w = n/MAX_THREAD;
		for(int id = 0; id < MAX_THREAD; id++) {
			start[id] = w*id + 1;
			end[id] = ((id!=3) ? w*(id + 1) : n); 
		//	start[MAX_THREAD] = {1, w+1, 2*w+1, 3*w+1};
		//	end[MAX_THREAD] = {w, 2*w, 3*w, n};
		}
		for(int id = 0; id < MAX_THREAD; id++) {
        	pthread_create(&pt[id], &attr, tsum, (void *)&tid[id]);
		}
		for(int id = 0; id < MAX_THREAD; id++) {
			pthread_join(pt[id],NULL);
			offset[id+1] = prefix_sum[end[id]];
		}
		offset[2] += offset[1];
		offset[3] += offset[2];
		for(int id = 1; id < MAX_THREAD; id++) {
			pthread_create(&pt[id], &attr, toffset, (void *)&tid[id]);
		}
		for(int id = 0; id < MAX_THREAD; id++) {
			pthread_join(pt[id],NULL);
		}
        output(prefix_sum, n);
//		for(int i = 1 ; i <= n; i++) printf("%d%c",prefix_sum[i]," \n"[i==n]);
    }
	pthread_exit(NULL);
    return 0;
}
