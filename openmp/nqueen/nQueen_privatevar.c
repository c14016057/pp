#include <stdio.h>
#define Max 30
int P[Max]={}, N, count = 0;
int ok(int idx, int position, int *Position) {
	for(int i = 0; i < idx; i++)
		if(Position[i] == position || Position[i] - position == idx - i || Position[i] - position == i - idx) return 0;
	return 1;

}
int nqueen(int next,int *Position) {
	if(next == N) return 1;
	int sum = 0;
	for (int i = 0; i < N; i++) 
		if (ok(next, i, Position)) {
			Position[next] = i;
			sum += nqueen(++next, Position);
			next--;		
		}
	return sum;

}
int main() {
	scanf("%d",&N);
#pragma omp parallel for private(P)
	for (int i = 0; i < N; i++) {
		P[0] = i;
		printf("thread%d=%d\n",i, nqueen(1,P));
	}


	return 0;
}
