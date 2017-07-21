#include <stdio.h>

int max(int a, int b) {
	return (a>b)?a:b;
}

int maxSumPath(int *arr1, int *arr2, int size1, int size2, int index, int *sum) {


	for(i = index; i<size1; i++) {

		if(arr1[index] == arr2[index]) {
			return max(maxSumPath(arr2,arr1,size2,size1,index+1,sum),maxSumPath(arr1,arr2,size1,size2,index+1))
		}
		else {

			*sum += arr1[index];
		}
	}
}


int main() {

	int arr1[] = { 2,3,7,10,11,35};
	int arr2[] = {1,5,7,30,35};




	return 0;
}

