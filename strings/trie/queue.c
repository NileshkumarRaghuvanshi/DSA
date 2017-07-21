#include <stdio.h>

#include "queue.h"
#define MAXQ_SIZE 1024

struct queue {
	element data[1024];
	int last;
}queueRoot;

//queueRoot.last = 0;

qRoot createQ() {
	queueRoot.last = 0;
}

void destroyQ(qRoot root) {

}

int addQ(element val) {
	if(queueRoot.last == MAXQ_SIZE-1)
		return -1;
	else
		queueRoot.data[queueRoot.last++] = val;
	
	return 0;
}
element removeQ() {
	if(queueRoot.last == 0)
		return -1;
	else
		return queueRoot.data[--queueRoot.last];
}

void printQ() {
	int i = 0;
	while(i != queueRoot.last) {
		printf("%c",queueRoot.data[i]);
		i++;
	}
	printf("\n");

}

void removeFromBack() {
	queueRoot.last--;
}
