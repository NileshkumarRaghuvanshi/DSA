#include <stdio.h>
#include <limits.h>

void printMatrix(int a[4][4], int row, int col) {


	int i =0;
	int j=0;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {	
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}

void printInSortedForm(int a[4][4], int row, int col) {


	int temp[row];

	int i = 0;
	int j = 0;
	int k = 0;
	int min = 0;
	for(i=0; i< row; i++)
		temp[i] = 0;


	for(k =0; k<row; k++) {
	
		for(j=0; j<col; j++) {	
		
			min = 0;
			for(i=0; i<row; i++) {
				
				if(temp[i] != INT_MAX) {
		
					if(a[i][temp[i]] < a[min][temp[min]])
						min = i;
				}
				else
					min = i+1;
			}

			printf("%d ",a[min][temp[min]]);
			temp[min]++;
			if(temp[min] >= row) {
				temp[min] = INT_MAX;
			}
		}
	}

	printf("\n");
	//return a[min][temp[min]];
}


int main() {


	int a[][4] = {	{10,20,30,40},
			{15,25,35,45},
			{27,29,37,48},
			{32,33,39,50},
			};

	printMatrix(a,4,4);
	printInSortedForm(a,4,4);
	return 0;
}
