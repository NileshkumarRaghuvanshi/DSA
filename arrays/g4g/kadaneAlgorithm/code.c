#include <stdio.h>


int findMaxSumContiguousSubArray(int *a, int size) {


	int max_so_far = 0;
	int curr_sum = 0;
	int i =0;

	for(i=0; i<size; i++) {

		curr_sum += a[i];

		if(curr_sum < 0)
			curr_sum = 0;
		else if(curr_sum > max_so_far)
			max_so_far = curr_sum;
	}

	return max_so_far;


}


int main() {


	int a[] = {-2,10,15,20,-3,-3,15};
		
	printf("max sum is %d\n",findMaxSumContiguousSubArray(a,sizeof(a)/sizeof(a[0])));
	return 0;
}
