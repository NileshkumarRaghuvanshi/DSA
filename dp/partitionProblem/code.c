#include <stdio.h>

int _findTwoSubSetWithSameSum(int *a, int size, int sum, int index) {

	if(sum == 0)
		return 1;

	if(sum !=0 && index >= size)
		return 0;


	return _findTwoSubSetWithSameSum(a,size,sum-a[index],index+1) || _findTwoSubSetWithSameSum(a,size,sum,index+1);

}



int findIfTwoSumPresent(int *a, int size) {

	int totalSum = 0;
	int i = 0;

	for(i =0; i<size; i++)
		totalSum += a[i];

	if(!(totalSum%2))
		return _findTwoSubSetWithSameSum(a,size,totalSum/2,0);
	else
		return 0;

}

int main() {

	//int sum = 11;
	int a[] = {1,3,6,12};

	if(findIfTwoSumPresent(a,sizeof(a)/sizeof(a[0])))
		printf("two subesets are present\n");
	else
		printf("Two subsets are not present\n");

	return 0;
}
