#include <stdio.h>

void printArray(int *a, int size) {

	int i=0;
	for(i=0;i<size;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void swap(int *a, int l, int m) {

	int temp = a[l];
	a[l] = a[m];
	a[m] = temp;

}
void sort(int *a, int size) {


	int lo = 0;
	int mid = 0;
	int hi = size -1;


	while(mid<=hi) {

		if(a[mid] == 1) {

			swap(a,lo,mid);
			mid++;
			lo++;
		}
		else  if(a[mid] == 2) {

			mid++;
		}
		else { //a[mid] == 3

			swap(a,mid,hi);
			//mid++;
			hi--;
		}


	}
	

}


int main() {


	//int a[] = {1,2,3,1,2,3,1,2,3,1,2,3};
	int a[] = {3,3,3,3,3,2,2,2,2,1,1,1,1};
	int size= sizeof(a)/sizeof(a[0]);


	printArray(a,size);
	sort(a,size);

	printArray(a,size);


	return 0;
}
