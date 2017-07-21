#include <stdio.h>

void checkRecursion(int *arr, int size, int index1, int index2) {

	

	if(index1 >= size || index2 >= size)
		return;

	/*
	if(index1 > index2) {
		return;
	}


	
	if(index1 == size || index2 == size-1){
		printf("end of arr\n");
		return;
	}

	if(index1 != -1)
		printf("index1 = %d\n",arr[index1]);
	else
		printf("index2 = %d\n",arr[index2]);

	*/

	printf("%d %d\n",index1,index2);
	checkRecursion(arr,size,index1+1,index2);
	if(!index1)
		checkRecursion(arr,size,index1,index2+1);




}

int main() {


	int arr[] = {1,2,3,4,5,6,7};

	checkRecursion(arr,sizeof(arr)/sizeof(arr[0]),0,0);



	return 0;
}
