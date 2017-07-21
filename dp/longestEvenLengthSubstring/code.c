#include <stdio.h>
#include <string.h>



int check2KSum(char *a, int len) {

	int i = 0;
	int j = 0;

	//char *str1 = a;
	//char *str2 = &a[len/2];

	if((len%2) !=0)
		return 0;

	for(i=0,j=(len/2); i<len && j<len; i++, j++) {
		if(a[i] != a[j])
			return 0;
	}
	//printf("str1 = %s, str2 = %s\n",str1,str2);

	return 1;
}

int findLongestEvenLengthSubstring(char *a, int len) {




	return 0;

}



int main() {


	char *a = "12311231";

	printf("The lenght is %d \n",findLongestEvenLengthSubstring(a,strlen(a)));

	if(check2KSum(a,strlen(a)))
		printf("Same\n");
	else
		printf("not same\n");

	
	return 0;
}

