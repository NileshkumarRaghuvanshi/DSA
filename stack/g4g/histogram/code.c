#include <stdio.h>
#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)

//1. if the current element is higher than the top of the stack or the stack is empty then push the current element
//2. if the current element is smalller than the top of the stack then
//	i). pop elements from stack till the current element is higher than.
//	ii). calculate the area with 
//		a. poped element as the min and 
//		b. right index as the current element and 
//		c. left index as the top of the stack
//3. if the stack is empty then
//	i).
int getMaxArea(int a[], int size) {

	struct myStack **st =  createStack();
	int i =0;
	int maxArea = 0;
	int current = 0;
	while(i < size) {
		if(isStackEmpty(st)) {
			printf("pushed : %d\n",a[i]);
			push(st,i++);
		}

		while(a[topOfStack(st)] <= a[i]) {
			printf("pushed : %d\n",a[i]);
			push(st,i++);
			
		}

		while(!isStackEmpty(st) && a[i] <= a[topOfStack(st)]) {
		
			int localMaxArea =0;
			int range = 0;
			current = pop(st);
			printf("poped :%d\n",a[current]);
			range = !isStackEmpty(st)?(i-topOfStack(st)-1):i;
			
			localMaxArea = (range)*a[current];
			printf("%d\n",localMaxArea);
			if(maxArea< localMaxArea)
				maxArea = localMaxArea;
		}
	
	}


	while(!isStackEmpty(st)) {
		int range = 0;
		int lMaxArea = 0;
		int current = pop(st);
		range = !isStackEmpty(st)?(i-topOfStack(st) -1):i;

		lMaxArea = range*a[current];
	

		if(maxArea < lMaxArea)
			maxArea = lMaxArea;
	}

	return maxArea;
}

int main() {


	int a[] = {6,1,5,6,7,8,2,9};

	printf("Max area = %d\n",getMaxArea(a,(sizeof(a)/sizeof(int))));

	return 0;
}

