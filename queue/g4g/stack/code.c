#include <stdio.h>
#include "../linked_list/linked_listQ.h"
#include <limits.h>


void push(struct queue_head *q, int data) {

	enqueue(q,data);

}


void pop_helper(struct queue_head *q, struct queue_head *q2, int *res) {

	int reare = rear(q);
	*res = INT_MIN;

	int temp = dequeue(q);
	if(temp == INT_MIN) {
		*res = temp;
		return;
	}

	while(reare != temp) {
		enqueue(q2,temp);
		temp = dequeue(q);
	}

	*res = temp;

	//q = q2;
	temp = dequeue(q2);
	while(temp !=INT_MIN) {
		enqueue(q,temp);
		temp = dequeue(q2);
	}

}


int pop(struct queue_head *q) {

	int res;

	//printf("res @ %p\n",&res);
	struct queue_head *q2 = createQ();
	pop_helper(q,q2,&res);

	return res;
}

int main() {

	struct queue_head *q = createQ();

	push(q,10);
	push(q,20);
	push(q,30);
	push(q,40);
	printf("%d\n",pop(q));
	printf("%d\n",pop(q));
	printf("%d\n",pop(q));
	printf("%d\n",pop(q));

	return 0;
}
