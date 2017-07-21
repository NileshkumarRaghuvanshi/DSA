#include <stdio.h>
#include <string.h>

#define RADIX  256

char *a[] = {

	"APYPR7741A",
	"CTLKM8989D",
	"LKSNF8972F",
	"LSJKD7484S",
	"SASDF7383N",
	"SDFJI7492D",
	"ASDFE3240Q",
	"JSIRN3783B"
};


void print_strings(char **a, int no_of_strings) {

	int i ;
	printf("no of strings are %d\n", no_of_strings);

	for(i=0; i<no_of_strings;i++) {
		printf("%s\n",a[i]);
	}

	printf("\n");
}

void print_array (int *a, int size) {

	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",a[i]);

	printf("\n");
}

void sort_strings(char **a, int no_of_string) {

	int d =0;
	int i;
	char *aux[no_of_string];

	for(d = strlen(a[0])-1; d>=0; d--) {
		
		printf("d = %d\n",d);
		int count[RADIX] = {0};

		//Count the frequencies
		for(i = 0; i<no_of_string; i++) 
			count[a[i][d] + 1]++;
		
		//print_array(count,RADIX);


		//coonvert to indices
		for(i=0; i<(RADIX-1); i++) 
			count[i+1] += count[i];
	
		//print_array(count,RADIX);


		//distribute strings to right places
		for(i=0; i<no_of_string; i++) 
			aux[count[a[i][d]]++] = a[i];
		
		//print_strings(aux,(sizeof(aux)/strlen(aux[0])));
		//print_strings(aux,8);

		//copy back to the original array
		for(i =0 ; i<no_of_string; i++)
			a[i] = aux[i];


		//print_strings(a,8);
		//print_strings(a,(sizeof(a)/strlen(a[0])));
	}
}

int main() {

	printf("Before\n");
	printf("size of a = %d, strlen of a =%d, no of strings = %d",sizeof(*a),strlen(a[0]),(sizeof(a)/strlen(a[0])));
	//print_strings((char **)a,(sizeof(a)/strlen(a[0])));
	print_strings(a,8);
		
	//sort_strings((char **)a,(sizeof(a)/strlen(a[0])));
	sort_strings(a,8);

	printf("After\n");
	//print_strings((char **)a,(sizeof(a)/strlen(a[0])));
	print_strings(a,8);

	return 0;
}
