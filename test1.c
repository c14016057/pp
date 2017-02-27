#include <stdio.h>
#include <pthread.h>
#define Max 8
void *printID(void *id) {
	printf("ID = %d\n", *((int*)id));
	pthread_exit(NULL);
}
int main() {
	pthread_t pt[Max];
	int id[Max];
	for(int i = 0; i < Max; i++) {
		id[i] = i;
		int tid = pthread_create(&pt[i], NULL, printID, (void *)&id[i]);
	}
	printf("end\n");
	pthread_exit(NULL);
	return 0;
}

