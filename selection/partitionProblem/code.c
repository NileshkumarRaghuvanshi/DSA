//This can be used to find the Kth-smallest elememts from the unsorted array
#include <stdio.h>


void exchange(int *a, int i, int j) {

	
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	printf("swapped %d with %d\n",i,j);
}

void printArray(int *a, int size) {

	int i =0;
	for(i=0; i<size; i++)
		printf("%d ",a[i]);

	printf("\n");
}


int partition(int *a, int lo, int hi) {

	int part;
	int i;
	int k = lo+1;
	int j = hi;
	if(hi<= lo)
		return lo;

	part = lo;
	while(1) {

		while(a[k] < a[part]) {
			if(k>=hi)
				break;

			k++;
		}

		while(a[j]> a[part]) {
			if(j<=lo)
				break;
			j--;
		}

		if(j<k) {
			exchange(a,part,j);
			return j;
		}

		exchange(a,k,j);
		j--;
		k++;
	}
}



int findPosition(int *a, int lo, int hi, int size, int k) {

	int part = partition(a,0,hi);
	
	if(part == (k-1)) {
		return k;
	}
	else if(part < (k-1)) {
		part = findPosition(a,part+1,hi,size,k);
	}
	else {
		part = findPosition(a,0,part-1,size,k);
	}

	printArray(a,size);
}


void findKSmallestElement(int *a, int size, int k) {

	int kPos;
	int i;
	if(size == 0 || size < k || k <=0) {
		printf("ERROR : invalid input args\n");
		return;
	}
	
	printf("finding the k-smallest elements\n");

	findPosition(a,0,size-1,size,k);
	for(i=0; i<k; i++)
		printf("%d ",a[i]);
	
	printf("\n");

}

	
int main() {

	int a[] = {15,6,2,4,9,17,3,5,1,10,11,7,14,13,8,12};
	int k = 15;
	findKSmallestElement(a,sizeof(a)/sizeof(a[0]),k);


	return 0;
}
