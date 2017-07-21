#include <stdio.h>

void getMinJumpToReachEnd(int *a, int size) {

	int i =0;
	int j = 0;
	int count = 0;
	int localMax = 0;
	int jump = 0;
/*
	for(i=0; i<size; i++) {

		localMax = 0;
		for(j=i+1; j<(i+a[i]); j++) {
			
			if(a[localMax] < a[j])
				localMax = j;
			
		}

		count++;
	}
*/

	while(i<size) {

		jump = a[i];
		localMax = i+1;
		
		if((i+a[i]) > size) {
			count++;
			break;
		}


		while(jump>0) {

			if(a[localMax] < a[i+jump])
				localMax = i+jump;
	
			jump--;
		}
		
		
		i = localMax;
		if(a[localMax] == 0) {
			printf("there is no solution possible\n");
			return;
		}
		
		count++;
		if((i + a[i]) > size) {
			count++;
			break;
		}

	}

	printf("jumps are %d\n",count);
}

int main() {

	int a[] = {1,3,5,8,9,2,6,7,6,8,9};
	//int a[] = {1,3,6,1,0,9};
	getMinJumpToReachEnd(a,sizeof(a)/sizeof(a[0]));
	return 0;
}
