#include <stdio.h>

//void _binary_search(int *a,int lo, int hi)  {


void binary_search(int *a, int lo, int hi, int element) {
	

	printf("Element to search=%d lo=%d,hi=%d\n",element,lo,hi);

	int mid;

	mid = lo + (hi-lo)/2;
	
	if(hi < lo) {
		printf("Not found returning\n");
		return;
	}

	
	if(a[mid] == element) {
		printf("Element is found\n");
		return;
	}
	else if(a[mid]>element) {
		printf("going left\n");
		binary_search(a,lo,mid,element);
	}
	else {
		printf("going right\n");
		binary_search(a,mid+1,hi,element);
	}
}


int main() {
	
	int element;
	printf("binary search\n");

	printf("Enter element to search\n");
	scanf("%d",&element);
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	binary_search(a,0,9,element);
	

	return 0;
}
