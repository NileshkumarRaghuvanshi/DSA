/* Here the change is the both the string should match with each other
 * when I say match it should completely match with 
 * each other
 *
 */


/*
 * '*' matches to no charaters or it matches to one or more characters
 * '?' matches to any character
 */

#include <stdio.h>
#include <string.h>

void printTable(int row, int col, int mat[row][col]) {

	int i ,j;

	for(i=0; i<row; i++) {
		for(j=0; j<col; j++) {
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}

}

int findMatch(char *str, char *pat) {

	int i,j;
	printf("String is %s\n",str);
	printf("pattern is %s\n",pat);

	int str_len = strlen(str);
	int pat_len = strlen(pat);

	int table[str_len+1][pat_len+1];

	memset(table,0,sizeof(table));
	table[0][0] = 1;

	for(i=0; i<pat_len; i++) {

		if(pat[i] == '*') { 
			printf("* found\n");
			table[0][i+1] = table[0][i];
		}

	}


	for(i=1; i<str_len+1; i++) {

		for(j=1; j<pat_len+1; j++) {
			
			if(str[i-1] == pat[j-1] || pat[j-1] == '?') {

				table[i][j] = 1 || table[i-1][j-1];
			}
			else if(pat[j-1] == '*') {

				table[i][j] = table[i][j-1] || table[i-1][j];
			}
			else {
				table[i][j] = 0;
			}

		}

		if(i>=(pat_len+1) && table[i][j]) {
			printTable(str_len+1,pat_len+1,table);
			return 1;
		}

	}

	printTable(str_len+1,pat_len+1,table);
	return table[str_len][pat_len] ;
}


int main() {

	char *str = "Thisismycountry";
	char *pat = "This*";


	if(findMatch(str,pat))
		printf("Match is present\n");
	else
		printf("Match is not present\n");




	return 0;
}
