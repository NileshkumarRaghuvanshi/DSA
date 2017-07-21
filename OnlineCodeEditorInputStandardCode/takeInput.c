#include <stdio.h>

#define MAX 100
void printArray(int *a) {

	int i=0;
	for(i=0;a[i];i++)
		printf("%d ",a[i]);
	
	printf("\n");

}

int main() {


	int noOfTestCases;
	int arr[MAX];
	int i=0;
	int val = 0;
	scanf("%d",&noOfTestCases);
	printf("test cases = %d\n",noOfTestCases);
	while(noOfTestCases) {
		i=0;
		scanf("%d ",&val);
		arr[i++] = val;
		while(val) {
			scanf("%d ",&val);
			arr[i++] = val;
			//printf("%d ",i);
		}

		//printf("\n");

		//process the array element
		printf("processing\n");
		printArray(arr);
		noOfTestCases--;
	}

	return 0;
}
