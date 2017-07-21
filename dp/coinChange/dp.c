#include <stdio.h>
#include <malloc.h>
#include <string.h>

int max(int a, int b) {
	return a>b?a:b;

}

void printMat(int row, int col, int table[row][col]) {

	int i,j;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void getMaxCoinChange(int *s, int size, int num) {


	int i=0;
	int j=0;

	int table[size+1][num+1];

	memset(table,0,sizeof(table));

	table[0][0] = 0;
	for(i=1; i<size+1; i++) {
		table[i][0] = 1;
		//table[0][i] = 0;
	}

	printMat(size+1,num+1,table);
	for(i=1; i<size+1; i++) {

		for(j=1; j<num+1; j++) {


			table[i][j] += table[i-1][j];

			if(j-s[i-1] < 0) {
				table[i][j] += 0;
			}
			
			if(j-s[i-1] >= 0) {
				table[i][j] += table[i][j - s[i-1]];
			}

			
		}

		printMat(size+1,num+1,table);
	}



	printf("max possible combination is %d\n",table[size][num]);
}



int main() {


	int s[] = {1,2,3};


	getMaxCoinChange(s,sizeof(s)/sizeof(s[0]),2);

	return 0;
}
