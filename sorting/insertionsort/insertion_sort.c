#include <stdio.h>

unsigned int no_of_swap = 0;
unsigned int complexity = 0;

void print_array(int a[], int len) {

	int i;
	for(i=0;i<len;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void insertion_sort(int A[], unsigned int len) {

	int i,j;
	int pos_to_insert;
	int value_to_insert;
	complexity = 0;
	for(i=1;i<len;i++) {
		pos_to_insert=j=i;
		value_to_insert = A[i];
		for(;j>=1;j--) {
			complexity++;
			if(A[j-1] > value_to_insert) {

				A[j] = A[j - 1];
				pos_to_insert--;
			}
			print_array(A,len);
		}
		A[pos_to_insert] = value_to_insert;
		//print_array(A,len);
	}
	print_array(A,len);
}



int main() {

	//int A[] = {1,2,3,4,5};
	int A[] = {5,6,2,1,4,3};

	printf("Before sorting\n");
	print_array(A,6);

	insertion_sort(A,6);
	
	printf("After sorting\n");
	print_array(A,6);

	printf("No of swap = %u\n",no_of_swap);
	printf("complexity = %u\n",complexity);
	return 0;
}
