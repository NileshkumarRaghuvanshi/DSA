#include <stdio.h>
#include <malloc.h>

void printArray(int *a, int n) {

	int i =0;
	for(i = 0; i<n; i++) 
		printf("%d ",a[i]);

	printf("\n");
}


int fibbonacciNumber(int n) {

	int *arr = calloc(n,sizeof(int));
	int result = 0;
	int i = 0;

	arr[0] = 0;
	arr[1] = 1;

	for(i=2; i<n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
		printArray(arr,i);
	}

	return arr[n-1];
}

int main() {

	printf("25th fibonnacci number is %d\n",fibbonacciNumber(25));
	return 0;

}
