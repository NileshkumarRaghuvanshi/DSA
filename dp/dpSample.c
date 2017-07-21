#include "dpSample.h"
#include <stdio.h>


void printMat(int row, int col, int mat[row][col]) {

	int i= 0;
	int j=0;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}


void printArray(int *arr, int size) {

	int i =0;
	for(i=0; i<size; i++) {

		printf("%d ",arr[i]);
	}
	printf("\n");
}

int max(int a, int b) {

	return a>b?a:b;

}
