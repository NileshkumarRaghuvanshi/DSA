#include <stdio.h>
#include <stdlib.h>


#define LEFT 0
#define RIGHT 1

int boundaryCheck(int left, int right) {

	if((left <0) || (right >0))
		return 1;
	else
		return 0;
}


void mergeArray(int *a, int size, int index, int direction) {

	if(direction == LEFT) {

		a[index+1] += a[index];
	}
	else if(direction == RIGHT) {

		a[index-1] += a[index];

	}
	else {
		printf("there is some weird error\n");
		exit(-1);
	}

}


void printArray(int *a, int size) {

	int i =0;
	for(i=0; i<size; i++)
		printf("%d ",a[i]);

	printf("\n");
}

int findMinMergesToMakePalindrome(int *a, int size,int left, int right) {


	int count = 0;
	while(left != right) {

		
		if(a[left] == a[right]) {
			left++;
			right--;
		}
		else {
			if(a[left] > a[right]) {
				mergeArray(a,size,right,RIGHT);
				right--;
			
			}
			else {
				mergeArray(a,size,left,LEFT);
				left++;
			}

			count++;

		}
		printArray(a,size);	
	

	}

	return count;

}

int main() {


	int a[] = {1,6,5,4,5,6,1};
	
	int noOfMerges = findMinMergesToMakePalindrome(a,sizeof(a)/sizeof(a[0]),0,((sizeof(a)/sizeof(a[0]))-1));

	printf("no of merges = %d\n",noOfMerges);

	return 0;
}

