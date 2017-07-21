#include <stdio.h>
#include <string.h>

int max(int a, int b) {

	return a>b?a:b;
}

int getLCS(char *str1, int len1, char *str2, int len2) {


	if(!str1 || !str2)
		return 0;
	if(len1 == 0 || len2 == 0)
		return 0;


	printf("str1 %s, str2 %s\n",str1,str2);

	if(str1[0] == str2[0]) {
		printf("matching char %c\n",str1[0]);
		return 1 + getLCS(str1+1,len1-1,str2+1,len2-1);
	}
	else
		return max(getLCS(str1+1,len1-1,str2,len2),getLCS(str1,len1,str2+1,len2-1));


}



int main() {


	char *str1 = "ABCDGH";
	char *str2 = "AEDFHR";


	printf("LCS is %d\n",getLCS(str1,strlen(str1),str2,strlen(str2)));


	return 0;
}
