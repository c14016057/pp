#include <stdio.h>
#define Max 30
int P[Max]={}, N, count = 0;
int ok(int idx, int position, int *Position) {
	for(int i = 0; i < idx; i++)
		if(Position[i] == position || Position[i] - position == idx - i || Position[i] - position == i - idx) return 0;
	return 1;

}
void nqueen(int next,int *Position) {
	if(next == N)
		#pragma omp critical 
		count++;
	for (int i = 0; i < N; i++) 
		if (ok(next, i, Position)) {
			Position[next] = i;
			nqueen(++next, Position);
			next--;		
		}
}
int main() {
	scanf("%d",&N);
#pragma omp parallel for private(P)
	for (int i = 0; i < N; i++) {
		P[0] = i;
		nqueen(1,P);
	}
	printf("ans = %d\n",count);	

	return 0;
}
