#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {

	if(a<b)
		return (a<c)?a:c;
	else
		return (b<c)?b:c;
}

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


int getNoOfOperation(char *str1, char *str2, int size1, int size2) {

	printf("Size is %d %d\n",size1,size2);
	return _getNoOfOperation(str1,str2,size1,size2,(size1-1),(size2-1));
}

int main() {

	char *str1 = "jayesh";
	char *str2 = "nilesh";



	int number = getNoOfOperation(str1,str2,strlen(str1),strlen(str2));
	printf("No of operation to convert %s to %s are %d\n",str1,str2,number);

	return 0;
}


