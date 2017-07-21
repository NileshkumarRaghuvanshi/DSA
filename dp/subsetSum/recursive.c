#include <stdio.h>


int
findSubsetWithSum(int *a, int size, int sum, int index) {



	if(sum == 0)
		return 1;

	if(index < 0 || sum <0)
		return 0;


	
	return findSubsetWithSum(a,size,sum-a[index],index-1) ||
		findSubsetWithSum(a,size,sum,index-1);



}





int
findSubSetWithSum(int *a, int size, int sum, int index) {


	if(sum ==0)
		return 1;
	if(index > size || sum < 0)
		return 0;


	return findSubSetWithSum(a,size,sum-a[index],index+1) ||
		findSubSetWithSum(a,size,sum,index+1);

}




int main() {


	int a[] = {1,2,3,8,10};

	int sum = 7;
	if(findSubSetWithSum(a,sizeof(a)/sizeof(a[0]),sum,0))
		printf("sum %d is present\n",sum);
	else
		printf("Sum %d is not present\n",sum);

	printf("checking from the last\n");

	if(findSubsetWithSum(a,sizeof(a)/sizeof(a[0]),sum,(sizeof(a)/sizeof(a[0])-1)))
		printf("sum %d is present\n",sum);
	else
		printf("Sum %d is not present\n",sum);


	return 0;

}
