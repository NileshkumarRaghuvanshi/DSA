#include <stdio.h>

void print_array(int *a, int size) {

	int i=0;
	for(i=0; i<size ;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}

void moveElementToEnd(int *a, int size) {

	int i,end;
	i = end = size -1;
	
	while(i >= 0) {

		if(a[i] != -1) {
			int temp = a[i];
			a[i] = a[end];
			a[end] = temp;
			end--;
		}
		i--;
	}
}


void mergeSortedArrays(int *a, int a_size, int *b, int b_size) {

	int k =0;
	int i = b_size;
	int j = 0;
	moveElementToEnd(a,a_size);
	print_array(a,a_size);

	while(k<a_size+b_size) {

		if(j == b_size) {
			printf("returning\n");
			return;
		}
		if(i == a_size) {
			printf("copying b directly\n");
			a[k++] = b[j++];
		}
		else if(a[i] < b[j]) {
			a[k++] = a[i++];
		}
		else {
			a[k++] = b[j++];
		}
	}
}


int main() {


	int a[] = {1,-1,-1,-1,-1,-1,-1,-1};
	int b[] = {2,5,8,10,13,30,34};

	int a_size = (sizeof(a)/sizeof(a[0]));
	int b_size = (sizeof(b)/sizeof(b[0]));

	mergeSortedArrays(a,a_size,b,b_size);

	print_array(a,a_size);
	return 0;
}
