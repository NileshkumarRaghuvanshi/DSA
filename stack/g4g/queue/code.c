#include <stdio.h>
#include <limits.h>
#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


void enqueue(struct myStack **st, int data){

	push(st,data);	

}

int dequeue(struct myStack **st) {

	int ret = 0;
	int temp_pop = INT_MIN;
	if(isStackEmpty(st))
		return INT_MIN;
	
	temp_pop = pop(st);
	ret = dequeue(st);
	if(ret == INT_MIN) {
		//printf("ret = %d\n",temp_pop);
		ret = temp_pop;
	}
	else
		push(st,temp_pop);


	return ret;
}


int main() {

	struct myStack **st = createStack();

	enqueue(st,10);
	enqueue(st,20);
	enqueue(st,30);
	enqueue(st,40);
	enqueue(st,50);

	printf("%d\n",pop(st));

	while(!isStackEmpty(st))
		printf("%d \n",dequeue(st));	

	return 0;
}
