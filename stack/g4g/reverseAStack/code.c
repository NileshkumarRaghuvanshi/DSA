#include <stdio.h>

#include "../../stackLib/stackLib.h"

#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)

void insertAtBottom(struct myStack **st, int item) {

	int element;
	if(isStackEmpty(st)) {
		push(st,item);
		return;
	}

	element = pop(st);
	printf("element =%d\n",element);
	insertAtBottom(st,item);
	push(st,element);
}
void reverseAStack(struct myStack **st) {

	int element;
	if(isStackEmpty(st)) {
		printf("returning\n");
		return;
	}
	//else 
	//	printf("something terrible\n");

	element = pop(st);
	printf("%d\n",element);
	reverseAStack(st);
	//printf("pushing %d\n",element);
	insertAtBottom(st,element);

}


int main() {


	struct myStack **st = creatStack();
	push(st,1);
	push(st,2);
	push(st,3);
	push(st,4);
	push(st,5);
	push(st,6);
	push(st,7);
	push(st,8);

	reverseAStack(st);

	while(!isStackEmpty(st))
		printf("%d\n",pop(st));

	return 0;
}
