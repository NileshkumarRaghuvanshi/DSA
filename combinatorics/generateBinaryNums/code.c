#include <stdio.h>
#include <malloc.h>


void printArray(int *a, int size) {

	int i=0;
	for(i=0; i<size; i++)	
		printf("%d ",a[i]);

	printf("\n");
}
void getBinaryNums(int *arr, int size,int index) {

	int i=0;
	if(index >= size) {
		printArray(arr,size);
		return;
	}

	for(i =0; i<2; i++) {
		arr[index] = i;
		getBinaryNums(arr,size,index+1);
	}

}



int main() {

	int num = 4;
	int *out = malloc(sizeof(int)*num);


	getBinaryNums(out,num,0);

	return 0;
}
