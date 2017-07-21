#include <stdio.h>

#include "stack.h"



int main() {

	stackPtr st = createStack();

	push(st,10);
	push(st,20);
	push(st,30);
	push(st,40);
	push(st,50);

	while(!isEmpty(st))
		printf("%d ",pop(st));


	return 0;
}

