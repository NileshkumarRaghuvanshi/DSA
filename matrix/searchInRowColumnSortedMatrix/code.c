#include <stdio.h>


void printMatrix(int a[4][4], int row, int col) {

	int i=0;
	int j=0;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++)
			printf("%d ",a[i][j]);
		
		printf("\n");
	}

	printf("\n");
}

int searchInSortedMatrix(int a[4][4], int row, int col, int element) {


	int i = 0; 
	int j = col-1;

	while((j<col && j>=0) && (i<row && i>=0)) {

		if(a[i][j] == element) {
			return 1;
		}
		else if(a[i][j] < element) {
			i++;
			printf("incrementing row %d\n",i);
		}
		else {
			j--;
			printf("decrementing col %d\n",j);
		}
	}

	return 0;
}

int main() {


	int a[][4] = {	{10,20,30,40},
			{25,35,45,50},
			{28,38,48,53},
			{32,42,52,57},
			};

	int searchElement = 32;
	printMatrix(a,4,4);

	if(searchInSortedMatrix(a,4,4,searchElement))
		printf("element is present\n");
	else
		printf("element is not present\n");

	return 1;
}
