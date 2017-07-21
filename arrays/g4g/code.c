#include <stdio.h>

void printArray(int *a, int size) {

	int i=0;
	for(i=0;i<size;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void sort(int *a, int size) {



}


int main() {


	int a[] = { 1,2,3,1,2,3,1,2,3,1,2,3};
	int size= sizeof(a)/sizeof(a[0]);


	printArray(a,size);
	sort(a,size);

	printArray(a,size);


	return 0;
}
