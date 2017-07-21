#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define  printArray(arr, size) \
{\
	int i;\
	for(i=0; i<size; i++) {\
		printf("%d ",arr[i]);\
	}\
	printf("\n");\
}\

int LIS(int *arr,int size) {



	int lis[size];
	int i,j;
	memset(lis,1,sizeof(lis));

	
 	for(i=0 ;i<size; i++) {
 	//printf("%d ",lis[i]);
		lis[i] = 1;
	}
	//printf("\n");


	printArray(lis,size);

	for(i=1;i<size; i++) {
		for(j=0; j<i; j++) {

			if(arr[j] < arr[i]) {

				int newMax = 1 +lis[j];
				if(newMax > lis[i])
					lis[i] = newMax;

			}

		}

		printArray(lis,size);

	}

	return lis[size-1];
}

int main() {


	int arr[] = {10,22,9,33,50,41,60,80};

	printf("Longest increasing sequence is =%d\n",LIS(arr,sizeof(arr)/sizeof(arr[0])));


	return 0;
}

