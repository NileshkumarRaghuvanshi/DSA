#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long int DATA;

struct deque_node {

	DATA data;
	struct deque_node *next;
	struct deque_node *prev;
};

struct deque {

	//struct deque_node *list;
	struct deque_node *first;
	struct deque_node *last;
};


struct deque_node *createNode(DATA data) {

	struct deque_node *temp = malloc(sizeof(struct deque_node));
	if(temp) {
		temp->data = data;
		temp->next = temp->prev = NULL;
	}

	return temp;
}

struct deque * createDQ() {

	struct deque *temp = malloc(sizeof(struct deque));
	if(temp) {
		temp->first = temp->last = NULL;
	}

	return temp;

}


//insert at end
//There are only 3 cases
//1. is the Queue empty? (CASE I)
//2. if the Queue is not empty
//	a. if it is the first or the only element on which operation is performed. (CASE II)
//	b. if it is not the first element on which operation is performed. (CASE III)

void deque_nq(struct deque *dq, DATA data) {

	struct deque_node *temp = createNode(data);
	if(temp) {

		if(dq->first) {
			dq->last->next = temp;
			temp->prev = dq->last;
			dq->last = temp;
		}
		else {
			dq->first = dq->last = temp;
		}
	}
	else {
		printf("ERROR : adding a deque node\n");
		exit(-1);
	}
}

//remove at front
DATA deque_dq(struct deque *dq) {

	DATA temp = LONG_MIN;
	struct deque_node *temp_ptr = NULL;
	if(!isEmpty(dq)) {

		temp = dq->first->data;
		temp_ptr = dq->first;

		if(dq->first != dq->last) {
			dq->first = dq->first->next;
			dq->first->prev = NULL;
		}
		else {
			dq->last = dq->first = NULL;
		}	
		
		free(temp_ptr);

	}
	else {
		printf("ERROR : deque is empty\n");
	}

	return temp;
}

//remove at end
DATA deque_pop(struct deque *dq) {
	
	DATA temp = LONG_MIN;
	struct deque_node *temp_ptr = NULL;
	if(!isEmpty(dq)) {

		temp = dq->last->data;
		temp_ptr = dq->last;
		if(dq->first != dq->last) {
			dq->last = dq->last->prev;
			dq->last->next = NULL;
		}
		else {
			dq->first = dq->last = NULL;
		}

		free(temp_ptr);
	}
	else {
		printf("ERROR : deque is empty\n");
	}

	return temp;
}

//insert at front
void deque_insertAtBeg(struct deque *dq, DATA data) {

	struct deque_node *temp = createNode(data);
	if(temp) {
		
		if(dq->first) {
			temp->next = dq->first;
			dq->first->prev = temp;
			dq->first = temp;
		}
		else {
			dq->first = dq->last = temp;
		}
	}
	else {
		printf("ERROR : creating node \n");
		exit(-1);
	}
}


int isEmpty(struct deque *dq) {

	if(dq->first == NULL && dq->last == NULL)
		return 1;
	else
		return 0;

}

int main() {

	struct deque *dq = createDQ();

	if(dq) {
		deque_nq(dq,10);
		deque_insertAtBeg(dq,9);
		deque_nq(dq,11);
		deque_nq(dq,12);
		deque_nq(dq,13);	
		deque_nq(dq,14);
		deque_nq(dq,15);
		deque_insertAtBeg(dq,8);	
		deque_insertAtBeg(dq,7);
		deque_insertAtBeg(dq,6);
		deque_insertAtBeg(dq,5);

		printf("%lld\n",deque_dq(dq));
		printf("%lld\n",deque_dq(dq));
		printf("%lld\n",deque_pop(dq));
		printf("%lld\n",deque_pop(dq));
	}
	else {
		printf("ERROR : creating deque node\n");
	}
	return 1;

}
