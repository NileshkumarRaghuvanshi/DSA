#include <stdio.h>
#include <string.h>
#include <math.h>

int hash_const = 3;

void match_pattern(char *text,int text_len, char *patt, int patt_len) {

	long long patt_hash = 0;
	long long text_hash = 0;
	int i,j;

	printf("text = %s\n, len = %d\n",text,text_len);
	printf("patt = %s\n, len = %d\n",patt,patt_len);

	for(i=0;i<patt_len;i++) {
		printf("patt[i] = %d, text[i] = %d\n",patt[i],text[i]);
		patt_hash += (patt[i] * pow(hash_const,i));
		text_hash += (text[i] * pow(hash_const,i));


		printf("hash_patt = %d\n",patt_hash);
		printf("first text_patt =%d\n",text_hash);
	}

	for(i = 0;i<(text_len - patt_len);i++) {
		if(text_hash == patt_hash) {
			printf("hash match\n");
			for(j =0; j<patt_len;j++) {
				if(patt[j] != text[i])
					printf("hash same but no match\n");
			}

			if(j == patt_len) {
				printf("Match found at index = %d\n",i);
			}
		}
		else {

			if(i < (text_len-patt_len) ) {
				printf("i = %d\n",i);
				printf("recalculating hash\n");
				text_hash -= text[i];
				text_hash /= hash_const;
				text_hash += text[i+patt_len]*((hash_const)^(patt_len-1));
				printf("text hash =%x\n",text_hash);
			}
		}
	}
}



int main() {



	char *text = "Nileshkumar";
	char *patt = "shk";

	match_pattern(text,strlen(text),patt,strlen(patt));

	return 0;
}
