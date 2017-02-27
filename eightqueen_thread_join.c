#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define Max 32
int size,borad[Max][Max],sum[Max]={},next[Max];
int dijiyobu(int id, int position) {
	for(int i = 0; i < next[id]; i++) {
		if(borad[id][i] == position || abs(borad[id][i] - position) == next[id] - i) return 0;
	} 
	return 1;
}
void queen(int id) {
//	printf("id = %d gogogo\n",id);
	if(next[id] == size) {
		sum[id]++;
//		printf("id = %d, sum = %d\n",id, sum[id]); 
		return;
	}
	for(int i = 0 ; i < size; i++) {
		if(dijiyobu(id, i)) {
			borad[id][next[id]] = i;
			next[id]++;
			queen(id);
			next[id]--;
		}
	}
}
void *goqueen(void* n) {
	int id = *((int *)n);
	queen(id);
//	printf("id = %d, sum = %d\n",id, sum[id]);
	pthread_exit(NULL);
}
int main() {
	pthread_t pt[Max];	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	scanf("%d", &size);
	for (int id = 0; id < size; id++) {
		borad[id][0] = id;
		next[id] = 1;
		int tid = pthread_create(&pt[id], &attr, goqueen, (void*)&borad[id][0]); 
	}
	for (int id = 0; id <size; id++) {
		pthread_join(pt[id], NULL);
		printf("id = %d, sum = %d\n",id, sum[id]);
	}
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
//	for(int i = 0; i < size; i++) printf ("id = %d, sum = %d\n", i, sum[i]);
}
