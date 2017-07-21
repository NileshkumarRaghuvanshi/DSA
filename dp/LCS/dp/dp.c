#include <stdio.h>
#include <string.h>
#include <malloc.h>

int max(int a, int b) {

	return a>b?a:b;
}

void printMat(int row, int col, int table[row][col]) {

	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++) {

			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
}

int getLCS(char *str1,int len1,char *str2,int len2) {


	//int arrSize = len1>len2?len2:len1;
	
	int table[len1+1][len2+1];

	memset(table,0,sizeof(table));

	int i,j;

	for(i=0;i<len2+1; i++) {
		table[0][i] = 0;
	}

	for(j=0;j<len1+1; j++)
		table[j][0] = 0;

	printMat(len1+1,len2+1,table);

	for(i=1; i<len1+1; i++) {

		for(j=1; j<len2+1; j++) {

			if(str1[i-1] == str2[j-1]) {

				table[i][j] = 1 + table[i-1][j-1];
			}
			else {
				table[i][j] = max(table[i-1][j],table[i][j-1]);
			}
		}

		printMat(len1+1,len2+1,table);
		printf("\n");
	}


	return table[len1][len2];;
	//return _getLCS(str1,len1,str2,len2,arr,arrSize);
}


int main() {


	char *str1 = "ABCDGH";
	char *str2 = "AEDFHR";


	printf("LCS is %d\n",getLCS(str1,strlen(str1),str2,strlen(str2)));


	return 0;
}
