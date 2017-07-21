#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {

	if(a<b)
		return (a<c)?a:c;
	else
		return (b<c)?b:c;
}
/*
//str1 to be converted to str2
int _getNoOfOperation(char *str1, char *str2, int size1, int size2, int i, int j) {

	if(i < 0)
		return (j<0)?0:j;
	if(j < 0)
		return (i<0)?0:i;

	//printf("comparing i=%d j=%d\n",i,j);

	if(str1[i] == str2[j])
		return _getNoOfOperation(str1,str2,size1,size2,i-1,j-1);
	else {

		return 1 + min( _getNoOfOperation(str1,str2,size1,size2,i,j-1),		//insert
				 _getNoOfOperation(str1,str2,size1,size2,i-1,j),	//Remove
				 _getNoOfOperation(str1,str2,size1,size2,i-1,j-1));	//replace
	}
}
*/


void printMatrix( int row, int col, int a[7][7]) {

	int i =0;
	int j =0;
	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			printf("%d | ",a[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

//top-bottom approach
int getNoOfOperation(char *str1, char *str2, int size1, int size2) {

	//printf("Size is %d %d\n",size1,size2);

	int ed[size1+1][size2+1];
	int i = 0;
	int j =0;


	for(i=size1; i>=0; i--) 
		ed[i][size2] = 0;
	for(j=size2; j>=0; j--)
		ed[size1][j] = 0;


	for(i=size1-1; i>=0; i--) {
		for(j=size2-1; j>=0; j--) {			
			if(str1[i] == str2[j])
				ed[i][j] = ed[i+1][j+1];
			else
				ed[i][j] = 1 + min(ed[i+1][j],ed[i][j+1],ed[i+1][j+1]);
		}
	}

	for(i=0; i<=size1; i++) {
		for(j=0; j<=size2; j++) {
			printf("%d |",ed[i][j]);
		}
		printf("\n");
	}
	
	return ed[0][0];

}

int main() {

	char *str1 = "Nilesh";
	char *str2 = "Jayesh";



	int number = getNoOfOperation(str1,str2,strlen(str1),strlen(str2));
	printf("No of operation to convert %s to %s are %d\n",str1,str2,number);

	return 0;
}
