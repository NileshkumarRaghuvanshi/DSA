#include <stdio.h>
#include <limits.h>


void printArray(int *a, int size) {

	int i = 0;
	for(i = 0; i<size; i++) 
		printf("%d ",a[i]);

	printf("\n");
}

void exchange(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int *a, int start, int end) {

	int pivot = start;
	int i = start;
	int j = end +1;
	while(1) {

		while (a[++i] < a[pivot]) {
			if(i == end)
				break;
		}

		while(a[--j] > a[pivot]) {
			//printf("%d > %d\n",a[j],a[pivot]);
			if(j== start)
				break;
			//j--;
		}

		//printf("i = %d, j = %d\n",i,j);

		if(i>=j)
			break;
		exchange(&a[i],&a[j]);
	}
	exchange(&a[pivot],&a[j]);

	return j;
}

void quickSort(int *a, int start, int end) {

	if(start >= end) 
		return;
	int part = partition(a,start,end);
	printf("%d\n",part);
	quickSort(a,start,part-1);
	quickSort(a,part+1,end);


	
}


void getValuesClosestToZero(int *a, int *val1, int *val2, int size) {

	int left = 0;
	int  right = size -1 ;
	int sum = INT_MAX;
	quickSort(a,0,size-1);
	printArray(a,size);

	while(left < right) {
	
		int tempSum = a[left] + a[right];
		if( abs(tempSum) < abs(sum)) {
			sum = tempSum;
			*val1 = a[left];
			*val2 = a[right];
		}
		if(tempSum > 0) {
			right--;
		}
		else if(tempSum < 0) {
			left++;
		}
		else {
			*val1 = left;
			*val2 = right;
			return;
		}



	}

}



int main() {


	int a[] = {1,60,-80,-10,95,5};
	int val1;
	int val2;

	getValuesClosestToZero(a,&val1,&val2,(sizeof(a)/sizeof(a[0])));

	printf("Two values are %d, %d\n",val1,val2);
	return 0;
}
