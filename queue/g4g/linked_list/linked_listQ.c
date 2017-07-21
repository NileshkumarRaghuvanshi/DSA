#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include "linked_listQ.h"



struct queue_node *createQNode(int data) {

	struct queue_node *temp = malloc(sizeof(struct queue_node));
	if(temp) {
		temp->data = data;
		temp->next = NULL;
	}

	return temp;
}


struct queue_head * createQ() {


	struct queue_head *temp = malloc(sizeof(struct queue_head));
	if(temp) 
		temp->front = temp->rear = NULL;

	return temp;
}

void deleteQ(struct queue_head *q) {


}
void enqueue(struct queue_head *q, int data) {

	struct queue_node *temp = createQNode(data);
	if(temp) {

		if(q->rear) {
			q->rear->next = temp;
			q->rear = temp;
		}
		else {
			q->rear = temp;
			q->front = temp;
		}
	}
	else
		printf("ERROR : enqueue\n");
	
}

int isEmpty(struct queue_head *q) {

	if(q->front == NULL && q->rear == NULL)
		return 1;
	else
		return 0;
}

int dequeue(struct queue_head *q) {

	struct queue_node *temp_ptr = NULL;
	int temp = INT_MIN;
	if(q->front) {
		temp = q->front->data;
		temp_ptr = q->front;
		q->front = q->front->next;
		free(temp_ptr);
	}


	if(q->front == NULL) { 
		q->rear = NULL;
		//printf("Q Khali he\n");
	}
	return temp;

}


int front(struct queue_head *q) {

	if(q->front)
		return q->front->data;
	else
		return INT_MIN;
}


int rear(struct queue_head *q) {

	if(q->rear)
		return q->rear->data;
	else
		return INT_MIN;
}



