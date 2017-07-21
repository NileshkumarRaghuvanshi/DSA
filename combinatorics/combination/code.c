#include <stdio.h>
#include <malloc.h>

void printArray(int *arr, int size) {

	int i=0;
	for (i=0; i<size; i++) 
		printf("%c ",arr[i]);

	printf("\n");
}

void _generateCombination(int *arr, int arrSize, int *out, int outSize, int index,int start) {

	int i =0;
	if(index >= outSize) {
		printArray(out,outSize);
		return;
	}

	for(i=start; i<arrSize; i++) {

		out[index] = arr[i];
		_generateCombination(arr,arrSize,out,outSize,index+1,i+1);
	}
}


void generateCombination(int *arr,int arrSize,int *out, int outSize) {


	_generateCombination(arr,arrSize,out,outSize,0,0);
}

int main() {

	int arr[] = {'a','b','c','d','e'};
	int num = 2;
	int *out = malloc(sizeof(arr[0])*num);


	generateCombination(arr,(sizeof(arr)/sizeof(arr[0])),out,5);

	return 0;
}
