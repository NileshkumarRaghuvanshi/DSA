#include <stdio.h>

int max(int a, int b) {

	return a>b?a:b;
}

int __getMaxValueKnapsack(int *val, int *wt, int size, int MaxWt, int currWt, int currVal, int index) {


	if(index >= size ) {
		printf("index is =%d\n",index);
		return currVal;
	}

	if(currWt + wt[index] > MaxWt)
		return __getMaxValueKnapsack(val, wt, size, MaxWt, currWt,currVal, index+1);
	else {

		return max(  __getMaxValueKnapsack(val, wt, size, MaxWt, currWt,currVal, index+1),
			__getMaxValueKnapsack(val,wt,size,MaxWt,(currWt+ wt[index]),(currVal+val[index]),index+1));
	}
}



int getMaxValueKnapsack(int *val, int val_size, int *wt, int wt_size, int maxW) {

	

	return __getMaxValueKnapsack(val,wt,val_size,maxW,0,0,0);


}



int main() {


	int val[] = {60, 100, 120,200};
	int wt[] = { 10,20,30,25};
	int W = 50;

	printf("Max profit is %d\n",getMaxValueKnapsack(val,sizeof(val)/sizeof(val[0]),wt, sizeof(wt)/sizeof(wt[0]),W));

	return 0;
}
