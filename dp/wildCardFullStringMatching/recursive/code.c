#include <stdio.h>
#include <string.h>

int findMatch(char *str, char *pat) {

	//printf("string is %s\n",str);
	//printf("pat is %s\n",pat);

	int m = strlen(str);
	int n = strlen(pat);

	int i =0;

	if(!str[i] && !pat[i])
		return 1;
	
	if(!str[i] || !pat[i]) {
		if(!str[i] && pat[i] == '*' && !pat[i+1]) {
			printf("super special case\n");
			return 1;
		}
		return 0;
	}

	printf("===============comparing %c with %c===========\n",str[i],pat[i]);
	if(str[i] == pat[i]) {

		printf("===============matching %c with %c===========\n",str[i],pat[i]);
		return (1 && findMatch(str+1,pat+1));
	}
	else if(pat[i] == '*') {

		return (findMatch(str,pat+1) || findMatch(str+1,pat));

	}
	else 
		return 0;


}
int main() {


	char *str = "NileshkumarRaghuvanshi";
	char *pat = "*Nilesh*Raghuvansh";



	if(findMatch(str,pat)) {
		printf("match found\n");
	}
	else {
		printf("there is no match\n");
	}



	return 0;
}

