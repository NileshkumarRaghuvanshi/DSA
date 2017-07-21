#include <stdio.h>

#define FALSE 0
#define TRUE 1


void printMatrix(int row, int col, int a[row][col]) {

	int i =0;
	int j =0;

	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			printf("%d |",a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}


void findNumbers(int row, int col, int mat[row][col], int *set, int size) {


	row = row-1;
	col = col-1;

	while (col !=0) {

		if(mat[row-1][col] != FALSE) {
			row = row-1;
		}

		else {

			printf("%d ",set[row-1]);
			col = col - set[row-1];
		}
	}
	printf("\n");

}

int findSubsetSum(int *a, int size, int sum) {

	int mat[size+1][sum+1];

	int i;
	int j;

	for(i=0; i<=size; i++)
		mat[i][0] = TRUE;

	for(i=1; i<=sum; i++)
		mat[0][i] = FALSE;


	for(i=1; i<=size; i++) {

		for(j=1; j<=sum; j++) {

			if(j < a[i-1]){
				mat[i][j] = mat[i-1][j];
			}
			else {
				mat[i][j] = mat[i-1][j-a[i-1]];
			}

		}

		printMatrix(size+1,sum+1,mat);

	}


	if(mat[i-1][j-1]) {

		printf("Sum %d is present\n",sum);
		printf("The numbers are: \n");
		findNumbers(size+1,sum+1,mat,a,size);
		return 1;

	}

	printf("sum %d is not present\n",sum);
	return 0;
	//return mat[i-1][j-1];

}


int main() {

	
	int a[] = {1,3,5,7,10};
	int sum = 11;

	findSubsetSum(a,sizeof(a)/sizeof(a[0]),sum);

	return 0;

}
