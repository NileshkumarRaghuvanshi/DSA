#include <stdio.h>
#include <string.h>

void printMatrix(int row, int col, int mat[row][col]) {

	int i,j;

	for(i=0; i<row; i++) {

		for(j=0; j<col; j++)
			printf("%d |",mat[i][j]);

		printf("\n");
	}

	printf("===============================\n");
}

int max(int a, int b) {
	return a>b?a:b;
}

int findLongestPalindromicSubsequence(char *str, int len) {

	int mat[len][len];
	int i,j;
	int pLen =1;
	int startLocation = 0;

	if(!len || !str) {
		printf("invalid input param\n");
		return;
	}

	//printf("Everything is fine\n");
	for(i=0; i<len; i++)
		for(j=0; j<len; j++)
			mat[i][j] = 0;

	//taking care of the default elements
	for(i=0; i<len; i++)
		mat[i][i] = 1;


	
	for(i=1; i<3; i++) {
		
		for(j=0; (j+i)< len; j++) {

			if(str[j] == str[j+i]) {
				mat[j][i+j] = i+1;
			}
			else
				mat[j][i+j] = max(mat[j][j+i-1],mat[j+1][j+i]);
		}

	}

	printMatrix(len,len,mat);



	for(i=3; i<len; i++) {

		for(j=0; (j+i)<len; j++) {

			if(str[j] == str[j+i]) {
				mat[j][i+j] = 2+max(mat[j][j+i-1],mat[j+1][j+i]);
			}
			else
				mat[j][i+j] = max(mat[j][j+i-1],mat[j+1][j+i]);
		}
	}

	printMatrix(len,len,mat);

	
	return mat[0][len-1];

}


int main() {

	char str[] = "aebila";

	printf("longest length palindromic subsequence is %d\n",findLongestPalindromicSubsequence(str,strlen(str)));

	return 0;

}

