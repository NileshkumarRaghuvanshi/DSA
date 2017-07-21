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


void findLongestPalindromicSubstring(char *str, int len) {

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
				pLen = i;
				startLocation = j;
				mat[j][j+i] = 1;
			}
		}

	}

	printMatrix(len,len,mat);



	for(i=3; i<len; i++) {

		for(j=0; (j+i)<len; j++) {

			if(str[j] == str[j+i] && mat[j+1][j+i-1]) {
			
				printf("palindrome i=%d,j=%d\n",i,j);	
				if(pLen < i) {
					printf("updated result\n");
					mat[j][j+i] = 1;
					pLen = i;
					startLocation = j;
				}
			}
		}
	}

	printMatrix(len,len,mat);

	
	printf("Longest palindromic string length is %d: ",pLen+1);
	for(i=0; i<=pLen; i++)
		printf("%c",str[startLocation+i]);

	printf("\n");

}


int main() {

	char str[] = "eabcdcballlmmmm";

	findLongestPalindromicSubstring(str,strlen(str));

	return 0;

}

