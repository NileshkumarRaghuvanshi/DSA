#include <stdio.h>

unsigned int no_of_swap = 0;
unsigned int complexity = 0;


void shell_sort(int *A, unsigned int len) {
	int i,j;
	printf("shell sort\n");

}

void print_array(int a[], int len) {

	int i;
	for(i=0;i<len;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main() {

	int A[] = {1,2,3,4,5};

	int swap_done = 1;
	printf("Before sorting\n");
	print_array(A,5);

	shell_sort(A,5);
	
	printf("After sorting\n");
	print_array(A,5);

	printf("No of swap = %u\n",no_of_swap);
	printf("complexity = %u\n",complexity);
	return 0;
}
