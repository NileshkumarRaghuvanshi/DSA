#include <stdio.h>
#include <malloc.h>

void printArray(int *a, int size) {


	int i =0;
	for(i=0; i<size; i++) {
		printf("%c ",a[i]);
	}
	printf("\n");
}

void _generatePermutation(int *arr, int size, int *out, int outSize,int index, int *visited) {


	int i =0;
	if(index >= outSize) {
		printArray(out,outSize);
		return;
	}


	for(i=0; i<size; i++) {
	

		if(!visited[i]) {
			out[index] = arr[i];
			visited[i] = 1;
			_generatePermutation(arr,size,out,outSize,index+1,visited);
			visited[i] = 0;
		}
	}

}

void generatePermutation(int *arr, int size, int *out, int outSize) {


	int *visited = calloc(size,sizeof(arr[0]));
	_generatePermutation(arr,size,out,outSize,0,visited);

}

int main() {


	//generataing permutaion of different letters from array of num letters 
	int arr[] = {'A','B','C','D','E'};

	int num = 5;
	int *out = malloc(sizeof(int)*num);
	generatePermutation(arr,(sizeof(arr)/sizeof(arr[0])),out,num);

	return 0;
}
