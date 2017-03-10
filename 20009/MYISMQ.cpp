#include "ISMQ.h"
/*typedef struct node {
        uint32_t num;
        int parent;
        int rank;
		} node;*/
static uint32_t num[1<<24],rank[1<<24];
static int parent[1<<24];
int index, top = 0;
int stack[1<<24];
void init_ISMQ(int N) {
	index = 0;
	top = 0;
}
void append_ISMQ(uint32_t V) {
	int tar = index;
	uint32_t temp = 0;
	while(top > 0 && num[stack[top - 1]] <= V ) { 
		if (temp > rank[stack[top - 1]])
			parent[stack[top - 1]] = tar;
		else if ( temp < rank[stack[top - 1]]) {
			temp = rank[stack[top - 1]];
			parent[tar] = stack[top - 1];
			//A[stack[top - 1]].num = A[tar].num;
			tar = stack[top -1];				
			//A[tar].parent = -1;
		}
		else 
			parent[stack[top - 1]] = tar, temp++;
		top --;
	}
	rank[tar] = temp;
	num[tar] = V,parent[tar] = -1;
	stack[top] = tar;
	top ++;
	index ++;
}
uint32_t findR(uint32_t L) {
	uint32_t r = L;
	if (parent[r] == -1) return r;
	r = parent[r];
	uint32_t root = findR(r);
	parent[L] = root;
	return root;

}
uint32_t query_ISMQ(uint32_t L) {
	return num[findR(L)];
}
