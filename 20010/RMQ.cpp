#include "RMQ.h"
#include <cstdlib>
#include <cstring>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define VERT(x, y) ((x)*N + (y))
struct T {
	int N;
	int32_t *a;
};
static inline int log2int(int x) {
    return 31 - __builtin_clz(x);
}
void *preprocessing(int N, int32_t A[]) {
	struct T *tool = (struct T*) malloc(sizeof(T));
	tool->a = (int32_t*) malloc(sizeof(int32_t)*N*(log2int(N) + 1));
	tool->N = N;
	for(int j = 0; j < N; j++) tool->a[j] = A[j];
	int logN = log2int(N);
	for(int i = 1; i <= logN; i++) {
		int range = 1 << (i-1);
		for(int j = 0; j < N - range; j++){
			tool->a[VERT(i, j)] = MAX(tool->a[VERT(i-1, j)], tool->a[VERT(i-1, j+range)]);
		}
	}
	return (void*)tool;
}
void offline_query(void *tool, int M, int32_t Q[][2], int32_t R[]) {
	struct T *Tool = (struct T*)tool;
	int len, N = Tool->N;
	for(int i = 0; len = Q[i][1]-Q[i][0]+1, i < M; i++) {
		int loglen = log2int(len);
		R[i] = MAX(Tool->a[VERT(loglen,Q[i][0])], Tool->a[VERT(loglen,Q[i][0] + len - (1<<loglen))]);
	}
}
void destroy(void *tool) {
	free(((struct T*)tool)->a);
	free(tool);
}
