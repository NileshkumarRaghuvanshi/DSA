#include <stdio.h>

void print_array(int *a, int size) {

	int i =0;
	for(i=0; i< size; i++) {
		printf("%d ",a[i]);
	}

	printf("\n");

}

void reverseArray(int *a, int size) {

	int start = 0;
	int end = size-1;

	while(start < end) {

		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}


void rotateArray(int *a, int size, int d) {

	reverseArray(a,d);
	reverseArray(a+d,size-d);
	reverseArray(a,size);

}

int main() {


	int a[] = {1,2,3,4,5,6,7,8,9,10};
	print_array(a,10);
	
	rotateArray(a,10,4);

	print_array(a,10);

	return 0;
}
