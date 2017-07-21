#include <stdio.h>

void print_array(int *a, int size) {

	int i=0;
	for(i=0; i<size ;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}

void mergeSortedArrays(int *a, int a_size, int *b, int b_size) {

	int k = a_size-1;
	int i = a_size - b_size -1;
	int j = b_size-1;

	while(k >= 0) {

		if(j < 0) {
			printf("returning\n");
			return;
		}
		if(i < 0) {
			printf("copying b directly\n");
			a[k--] = b[j--];
		}
		else if(a[i] > b[j]) {
			a[k--] = a[i--];
		}
		else {
			a[k--] = b[j--];
		}
	}
}


int main() {


	int a[] = {2,3,37,41,-1,-1,-1,-1,-1,-1,-1};
	int b[] = {1,5,8,10,13,30,34};

	int a_size = (sizeof(a)/sizeof(a[0]));
	int b_size = (sizeof(b)/sizeof(b[0]));

	mergeSortedArrays(a,a_size,b,b_size);

	print_array(a,a_size);
	return 0;
}
