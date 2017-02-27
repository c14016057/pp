#include <stdio.h>
#include <stdlib.h>
#define Max 32
int dijiyobu(int *borad, int next, int position) {
	for(int i = 0; i < next; i++) {
		if(borad[i] == position || abs(borad[i] - position) == next - i) return 0;
	} 
	return 1;
}
int queen(int *borad, int next, int size) {
	int ret = 0;
	if(next == size) return 1;
	for(int i = 0 ; i < size; i++) {
		if(dijiyobu(borad, next, i)) {
			borad[next] = i;
			ret += queen(borad, next + 1, size);
		}
	}
	return ret;
}
int main() {
	int N,borad[32];
	scanf("%d",&N);
	printf("%d\n",queen(borad,0,N));
}
