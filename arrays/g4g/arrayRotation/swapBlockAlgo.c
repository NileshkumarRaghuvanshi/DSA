#include  <stdio.h>

void printArray(int *a, int size) {

	int i=0;
	for( i =0; i< size; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void swapArray(int *a, int *b, int size) {

	int i=0;
	while(i<size) {

		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
		i++;
	}
}


void swapBlockAlgo(int *a, int a_size, int *b, int b_size) {

	if(a_size == b_size) {
		swapArray(a,b,a_size);
		return;
	}
	else if(a_size > b_size) {
		//AlArB, swap Al with B
		swapArray(a,b,b_size);
		//BArAl recurse to A side
		swapBlockAlgo(a+b_size, (a_size-b_size), b, b_size);
	}
	else {

		//ABlBr, swap A with Br
		swapArray(a,b+b_size-a_size,a_size);
		//BrBlA, recurse to B side
		swapBlockAlgo(a, a_size, b,b_size-a_size);
	}
		
	
}


int rotateLeft(int *a, int d, int n) {

	if(n == 0|| n==d) {
		printf("no need to anything\n");
		return;
	}
	else {
		
		swapBlockAlgo(a,d,a+d,n-d);
	}

}

int main() {


	int a[] = {1,2,3,4,5,6,7,8,9,10,11};
	rotateLeft(a,9,11);

	printArray(a,11);
	return 0;
}


