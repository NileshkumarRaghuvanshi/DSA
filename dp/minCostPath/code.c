#include <stdio.h>
#include <limits.h>

int min(int a, int b, int c) {

	if(a<b && a<c)
		return a;
	else if(b<c && b<a)
		return b;
	else
		return c;
}


int _findMinCostPath(int a[3][3], int row, int col, int m, int n, int rowi, int colj) {


	int val1, val2,val3;
	if(rowi > m || colj > n)
		return INT_MAX;

	printf(" row %d, col %d\n",rowi,colj);
	if(rowi == m && colj == n) {
		printf("match %d\n",a[rowi][colj]);
		return a[rowi][colj];
	}


	val1 = _findMinCostPath(a,row,col,m,n,rowi+1,colj);
	printf("val1 %d\n",val1);
	val2 = _findMinCostPath(a,row,col,m,n,rowi+1,colj+1);
	
	printf("val2 %d\n",val2);
	val3 = _findMinCostPath(a,row,col,m,n,rowi,colj+1);

	printf("done\n");
	printf("val3 %d\n",val3);

	printf("%d %d %d\n",val1,val2,val3);
	return min(val1,val2,val3)+ a[rowi][colj];




}

int findMinCostPath(int a[3][3], int row, int col, int m, int n) {


	return _findMinCostPath(a,row,col,m,n,0,0);
}

int main() {

		int a[][3] = {{1,2,3},
				{4,8,2},
				{1,5,3}
				};

		int row = 3;
		int col = 3;
		printf("min cost is %d\n",findMinCostPath(a, row, col,2,2));

	return 0;
}
