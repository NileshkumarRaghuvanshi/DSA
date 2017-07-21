#include <stdio.h>
#include "../../dpSample.h"
#include <string.h>


int getknapsackSolution(int *val, int *wt, int size, int maxW) {


	int i;
	int j;

	printf("size is%d\n",size);
	int table[size+1][maxW+1];

	memset(table,0,sizeof(table));
	
	/*
	for(i=0; i<maxW; i++) {
		table[0][i] = 0;
	}

	for(i=0; i<size; i++) {
		table[i][0] = 0;
	}
	*/

	for(i=1; i<size+1; i++) {
		
		for(j=1; j<maxW+1; j++) {

			if(j-wt[i-1] >= 0) {
		
				int valueWithIt = val[i-1] + table[i-1][j-wt[i-1]];
				int valueWithoutIt  = table[i-1][j];

				printf("with it = %d, without it = %d\n",valueWithIt,valueWithoutIt);	
				table[i][j] = max(valueWithIt,valueWithoutIt);
			}
			else
				table[i][j] = table[i-1][j];

		}

		printMat(size+1,maxW+1,table);
	}


	return table[size][maxW];
}


int main() {

	int val[] = {60,100,120};
	int wt[] = {1,2,3};
	int MaxWt = 5;

	printf("size if=%d\n",sizeof(val)/sizeof(val[0]));
	printf("Max profit obtained is %d\n",getknapsackSolution(val,wt,sizeof(val)/sizeof(val[0]),MaxWt));


	return 0;
}


