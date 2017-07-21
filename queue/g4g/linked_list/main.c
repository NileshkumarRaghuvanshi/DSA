#include <stdio.h>
#include "linked_listQ.h"


int main() {

	struct queue_head *q = createQ();
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	enqueue(q,50);
	enqueue(q,60);
	enqueue(q,100);
	enqueue(q,70);
	enqueue(q,80);
	enqueue(q,90);


	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	enqueue(q,105);
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));
	printf("%d \n",dequeue(q));


	return 0;
}
