#include <stdio.h>
#include <limits.h>


int min(int a, int b, int c) {

	if(a<b)
		return (a<c)?a:c;
	else
		return (b<c)?b:c;
}


int FindMinCostPath(int a[3][3], int row, int col, int m, int n) {


	int tc[row+1][col+1];
	int i,j;


	for(i=0; i<row+1; i++)
		for(j =0; j<col+1; j++) {
			tc[i][j] = INT_MAX;
		}

	for(i=1; i<=m+1; i++) {
		for(j=1; j<=n+1; j++) {

			if(i ==1 && j ==1) {
				tc[i][j] = a[i-1][j-1];
				continue;
			}

			tc[i][j] = min(tc[i-1][j],tc[i-1][j-1],tc[i][j-1]) + a[i-1][j-1];
			printf("i %d, j %d, val %d\n",i,j,tc[i][j]);
		}
	}

	
	return tc[m+1][n+1];
}


int main() {
	
	int a[][3] = {{1,2,3},
			{4,8,2},
			{1,5,3}
			};

	printf("min sum is %d\n",FindMinCostPath(a,3,3,2,2));

	return 0;
}
