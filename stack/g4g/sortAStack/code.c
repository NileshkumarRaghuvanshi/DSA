#include <stdio.h>

#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


void insertAtSortedPlace(struct myStack **st, int item) {

	int element;
	if(isStackEmpty(st))  {
		printf("inserting %d\n",item);
		push(st,item);
		return;
	}

	if(topOfStack(st) <= item) {
		printf("inserting %d after %d\n",item,topOfStack(st));
		push(st,item);
		return;
	}
	element = pop(st);
	printf("element = %d\n",element);
	insertAtSortedPlace(st,item);
	push(st,element);
}

void sortAStack(struct myStack **st) {

	int element;
	if(isStackEmpty(st))
		return;

	element = pop(st);
	printf("%d\n",element);
	sortAStack(st);

	insertAtSortedPlace(st,element);

}
int main() {

	struct myStack **st = creatStack();
	push(st,1);
	push(st,15);
	push(st,6);
	push(st,4);
	push(st,20);
	push(st,10);
	push(st,11);
	push(st,7);

	sortAStack(st);

	while(!isStackEmpty(st))
		printf("%d\n",pop(st));

	return 0;
}
