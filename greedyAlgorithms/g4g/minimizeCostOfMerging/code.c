#include <stdio.h>

struct intervals {
	int x;
	int y;
};

void printArray(struct intervals *a, int size) {
	
	int i =0;
	for(i=0;i<size;i++)
		printf("%d %d\n",a[i].x,a[i].y);

	//printf("\n");
}

void exchange(struct intervals *a, int i, int j) {
	int temp = a[i].y;
	a[i].y = a[j].y;
	a[j].y = temp;
}

int partition(struct intervals *a, int lo, int hi) {

	int pivot = lo;
	int i = lo;
	int j = hi+1;
	while(1) {

		while(a[pivot].y >= a[++i].y) {
			if(i == hi)
				break;
		}
		while(a[pivot].y <= a[--j].y) {
			if(j == lo)
				break;
		}

		if(i>j) {
			exchange(a,pivot,j);
			//printArray(a,hi+1);
			break;
		}
		exchange(a,i,j);
		//printArray(a,hi+1);
	}

	return j;
}


void quickSort(struct intervals *input, int lo, int hi) {

	if(lo>hi)
		return;

	int part = partition(input,lo,hi);
	printf("partition : %d\n",part);
	quickSort(input,lo,part-1);
	quickSort(input,part+1,hi);

}

void sort(struct intervals *input, int size) {

	quickSort(input,0,size-1);
}


int maxNonOverlappingInterval(struct intervals *input, int size) {

	int maxIntervals = 1;
	int prev = 0;
	int next = 1;
	sort(input,size);
	printArray(input,size);

	while(next <= size) {

		if(input[prev].y <= input[next].x) {
			maxIntervals++;
			prev = next;
		}

		next++;
	}

	return maxIntervals;
}

int main() {

/*
	struct intervals data[] = {{1,5},{4,5},{6,7},{2,3},{10,11}};

	int size = sizeof(data)/sizeof(data[0]);

	printArray(data,size);
	printf("Max non overlapping intervals are %d\n",maxNonOverlappingInterval(data,size));
*/
	printf("coding is not complete\n");
	return 0;
}

