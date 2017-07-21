#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_Q_SIZE 100
struct queue_node {
	
	int data;
	//struct queue_node *next;
};

struct queue_ds {

	struct queue_node *data;
	int front;
	int rear;
	int size;
};


struct queue_ds *createQ() {


	struct queue_ds *temp = malloc(sizeof(struct queue_ds));
	if(!temp) {

		printf("ERROR : allocating queue memeory\n");
		exit(-1);
	}

	temp->front = 0;
	temp->rear = MAX_Q_SIZE -1;
	temp->size = 0;
	temp->data = malloc(sizeof(struct queue_node)*MAX_Q_SIZE);
	
	return temp;
}

int isEmpty(struct queue_ds *q) {

	//return (q->front == q->rear)?1:0;
	return (q->size == 0)?1:0;
}

int isFull(struct queue_ds *q) {

/*
	//if(q->rear == MAX_Q_SIZE)
	//	return 1;
	if(q->rear == ((q->front+1)%MAX_Q_SIZE))
		return 1;
	else
		return 0;
*/
	return (q->size == MAX_Q_SIZE)?1:0;	
}

void enqueue(struct queue_ds *q, int data) {

	if(!isFull(q)) {
		q->rear = ((q->rear+1) % MAX_Q_SIZE);	
		(q->data[q->rear]).data = data;
		++q->size;
	}
	else
		printf("Q is full\n");

}


int dequeue(struct queue_ds *q) {

	int temp;
	if(!isEmpty(q)) {
		temp = (q->data[q->front]).data;
		q->front = ((q->front + 1)% MAX_Q_SIZE);
		--q->size;
		//q->data[q->front] = data;
		return temp;
	}
	else
		printf("Q is Empty\n");

	return -1;
}


int front (struct queue_ds *q) {

	if(!isEmpty(q))
		return q->data[q->front].data;
	else
		return INT_MIN;

}

int rear (struct queue_ds *q) {

	if(!isEmpty(q)) 
		return q->data[q->rear].data;
	else
		return INT_MIN;
}

int main() {

	struct queue_ds *q = createQ();
	int i=0;
	int temp = 0;

	while(i++ < 101) {
		enqueue(q,i);
	}
	
	printf("Now dQ\n");
	//i =0;

	printf("front %d\n",front(q));
	printf("rear %d\n",rear(q));

	do {
		temp = dequeue(q);
		printf("%d\n",temp);
	
	}while(temp != -1);

	return 0;
}
