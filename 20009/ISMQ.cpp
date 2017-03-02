#include "ISMQ.h"
#include <algorithm>

using namespace std;
typedef struct node {
	uint32_t num;
	node *parent;
	int rank;
} node;
int index, top;
node *stack[1<<24];
node A[1<<24];
void init_ISMQ(int N) {
	index = 0;
	top = 0;//NONONONONO
}
void append_ISMQ(uint32_t V) {
	A[index].num = V;
	A[index].parent = NULL;
	A[index].rank = 0;
	int oldtop = top, mrank = -1;
	node *leader = NULL;
	while(top > 0 && (stack[top - 1]->num <= V) ) {
		if(stack[top -1]->rank > mrank) {
			mrank = stack[top -1]->rank;
			leader = stack[top -1];
		}
		top --;
	}
	if(leader == NULL) {		
		stack[top] = &A[index];
	}
	else {
		for(int i = top; i < oldtop ; i++) 
			stack[i]->parent = leader;
		leader->parent = NULL;//nononononon
		leader->rank++;
		leader->num = V;
		A[index].parent = leader;
		stack[top] = leader;
	}
	top ++;
	index ++;
}
uint32_t query_ISMQ(uint32_t L) {
	node *Laddr = &A[L], *first = Laddr, *temp;
	while(Laddr->parent != NULL) Laddr = Laddr->parent;
	while(first->parent != NULL) 
		temp = first->parent, first->parent = Laddr, first = temp;
	return Laddr->num;
}

