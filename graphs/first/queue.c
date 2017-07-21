//this Q is implemented with circular array, 
//that is when the size is not eqaul to MAXQ_SIZE then
//we set the rear to 0, and there is no need to delete since
//you can always override values

#include "queue.h"
#include <stdio.h>
#include <malloc.h>


#define MAXQ_SIZE 100

//struct QNode {
//	int data[MAXQ_SIZE];
//;}

struct Q {
	//int data[MAXQ_SIZE];
	int *data;
	//struct QNode *data;
	int front;
	int rear;
	unsigned int size;
};

Qptr createQ() {
	
	Qptr temp = (Qptr) calloc(1, sizeof(struct Q));
	temp->data = (int  *) malloc(sizeof(int)*MAXQ_SIZE);
	return temp;

}

void destroyQ(Qptr q) {
	free(q);

}

int isFull(Qptr q) {

	return ((q->size == MAXQ_SIZE)? 1:0);
}

int nQ(Qptr q, int data) {
	if(isFull(q))
		return -1;

	q->size++;
	q->data[q->rear++] = data;
	if(q->rear > MAXQ_SIZE)
		q->rear = 0;

	return 0;
}

int isEmpty(Qptr q) {
	return q->size?0:1;
}

int dQ(Qptr q) {
	
	int data;
	if(isEmpty(q))
		return -1;
	
	q->size--;
	data = q->data[q->front++];
	if(q->front > MAXQ_SIZE)
		q->front = 0;

	return data;
}

