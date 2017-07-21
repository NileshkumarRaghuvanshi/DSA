#include <stdio.h>

int binarySearchIterative(int *a, int size, int x) {

	int ret = -1;
	int lo = 0;
	int hi = size -1;


	while(lo <= hi) {

		int mid = lo + (hi-lo)/2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
			hi = mid - 1;
		else
			lo =  mid + 1;

	}
	return ret;
}


int binarySearchRecursive(int *a, int lo, int hi, int x) {

	int ret = -1;

	if(lo > hi)
		return ret;
	else {

		int mid = lo + (hi - lo)/2;
		if( a[mid] == x)
			return mid;
		else if( a[mid] > x)
			ret = binarySearchRecursive(a,lo,mid-1,x);
		else
			ret = binarySearchRecursive(a,mid+1,hi,x);

	}

	return ret;
}


int main() {

	int ret = -1;
	int x = 18;
	int a[] = {1,2,4,5,7,8,14,18,20};

	ret = binarySearchIterative(a,(sizeof(a)/sizeof(a[0])),x);
	
	if(ret != -1) printf("Number %d is present at index %d\n",x,ret);
	else printf("Iterative : Number %d is not present\n",x);
	
	ret = binarySearchRecursive(a,0,(sizeof(a)/sizeof(a[0]))-1,x);
	
	if(ret != -1) printf("Number %d is present at index %d\n",x,ret);
	else printf("Recursive : Number %d is not present\n",x);

	return 0;
}
