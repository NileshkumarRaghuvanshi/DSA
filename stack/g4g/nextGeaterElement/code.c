#include <stdio.h>
#include "../../stackLib/stackLib.h"

#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)

void printNextGreaterElement(int *a, int size) {

	printf("taking next greater element\n");
	struct myStack **st = createStack();
	int i =0;

	while(i < size) {
		
		if(isStackEmpty(st)){
			push(st,a[i]);

		}
		else if(topOfStack(st) >= a[i]) {
			push(st,a[i]);

		}
		else {

			while(!isStackEmpty(st)) {
				if(topOfStack(st) < a[i]) {
					printf("%d --> %d\n",pop(st),a[i]);
				}
				else
					break;
			}
			push(st,a[i]);
		}
		i++;
	}

	while(!isStackEmpty(st)) {
		printf("%d --> -1\n",pop(st));
	}
}



int main() {

	int a[] = {11,7,6,5,4,10,8,9};
	printNextGreaterElement(a,8);


	return 0;
}
