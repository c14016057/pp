#include <stdio.h>
#define Max 30
int Position[Max][Max]={}, N, count = 0;
int ok(int idx, int position, int id) {
	for(int i = 0; i < idx; i++)
		if(Position[id][i] == position || Position[id][i] - position == idx - i || Position[id][i] - position == i - idx) return 0;
	return 1;

}
void nqueen(int next,int id) {
	if(next == N) count++;
	for (int i = 0; i < N; i++) 
		if (ok(next, i, id)) {
			Position[id][next] = i;
			nqueen(++next,id);
			next--;		
		}

}
int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		Position[i][0] = i;
		nqueen(1,i);
	}
	printf("%d\n",count);


	return 0;
}
