#include <stdio.h>

void printMatrix(int row, int col, int a[row][col]) {


	int i =0;
	int j=0;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {	
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}

void printSpiral(int row, int col, int a[row][col]) {



	int i = 0;
	int j =0;




}

int main() {


	int a[][4] = {	{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16},
			};

	printMatrix(4,4,a);
	printSpiral(4,4,a);
	return 0;
}
