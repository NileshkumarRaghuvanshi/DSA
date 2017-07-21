//in top-bottom approach, we start from the larger value and brake in down to lower values/base cases
//then we combine the necessary base cases and to get intermediate values which are in turn combined to 
//get the desired values



#include <stdio.h>
#include <malloc.h>

void printArray(int *a, int size) {

	int i=0;
	for(i =0; i<size; i++) 
		printf("%d ",a[i]);
	printf("\n");
}


int _fibonacciNumber(int n, int *arr) {


	if(arr[n]) return arr[n];

	if(n == 0) return 0;
	if(n == 1) return 1;


	arr[n] =  _fibonacciNumber(n-1,arr) + _fibonacciNumber(n-2,arr);

	printArray(arr,n);
	return arr[n];

}


int fibonacciNumber(int n) {

	
	int *arr = calloc(n,sizeof(int));

	arr[0] = 0;
	arr[1] = 1;
	return _fibonacciNumber(n,arr);

}

int main() {


	int n = fibonacciNumber(25);
	printf("25th no is %d\n",n);

	return 0;
}

