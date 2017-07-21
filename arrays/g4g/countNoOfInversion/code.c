#include <stdio.h>
#include "../../../stack/stackLib/stackLib.h"

#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


int countInversion(int *a int size) {

	struct myStack **st = createStack();
	int i = 0;
	int inversions= 0;
	int maxElement = 0;

	if(size <= 1) 
		return (size == 1)?0:-1;

	
	while(i<size) {

		if(a[i] < a[i+1]) {
			push(st,a[i]);
			maxElement = a[++i];
		}
		else {
			
			while(!isStackEmpty(st)){
				pop(st);
				inversions++;
			}
			push(st,maxElement);
		}
	}

	return inversions;

}


int main() {


	int a[] = {2,4,1,3,5};
	printf("No of inversions are %d\n",countInversion(a,sizeof(a)/sizeof(a[0])));

	return 0;
}


