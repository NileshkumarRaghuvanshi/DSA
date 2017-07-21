#include <stdio.h>

void printArray(int *a, int size) {
	int i =0;
	for(i=0;i<size;i++)
		printf("%d ",a[i]);

	printf("\n");
}

void exchange(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int *a, int lo, int hi) {

	int pivot = lo;
	int i = lo;
	int j = hi+1;
	while(1) {

		while(a[pivot] >= a[++i]) {
			if(i == hi)
				break;
		}
		while(a[pivot] <= a[--j]) {
			if(j == lo)
				break;
		}

		if(i>j) {
			exchange(a,pivot,j);
			printArray(a,hi+1);
			break;
		}
		exchange(a,i,j);
		printArray(a,hi+1);
	}

	return j;
}


void quickSort(int *a, int lo, int hi) {

	if(lo>hi)
		return;

	int part = partition(a,lo,hi);
	printf("partition : %d\n",part);
	quickSort(a,lo,part-1);
	quickSort(a,part+1,hi);

}

void sort(int *a, int size) {

	quickSort(a,0,size-1);
}

int main() {

	int a[] = {5,4,9,7,6,2,1,8,3};

	int size = (sizeof(a)/sizeof(a[0]));

	printf("Size is %d\n",size);
	printArray(a,size);
	sort(a,size);


	return 0;
}
