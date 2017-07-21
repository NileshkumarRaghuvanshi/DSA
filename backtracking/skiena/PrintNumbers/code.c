#include <stdio.h>

int isASolution(int *a, int k, int n) {

	if(n ==0)
		return 1;
	else
		return 0;
}

void printSolution(int *a, int k, int n) {

	int i=0;
	for(i=0; i<k; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void constructCandidates(int *a, int k, int n, int *c, int *nCandidates) {

	*nCandidates = 0;
	int i =0;
	while(k > 0 && a[k-1] < n) {
		n--;
	}
	//printf("n= %d\n",n);
	for(i=0; i<n; i++) {

		c[i] = (n-i);
		(*nCandidates)++;
	}


	//for(i=0;i<n;i++)
	//	printf("%d ",c[i]);
	//printf("\n");
	
	//printf("nCandidates = %d\n",*nCandidates);

}
void _printNumbers(int *a, int k, int n) {
	
	int c[n];
	int nCandidates = n;
	int i = 0;
	
	//printf("here1\n");

	if(isASolution(a,k,n)) {
		//printf("found  a solution\n");
		printSolution(a,k,n);
	}
	else {

		constructCandidates(a,k,n,c,&nCandidates);
		//printf("here\n");	
		for(i=0; i<nCandidates; i++) {

			
			a[k] = c[i];
			//printf("before call n = %d\n",(n-a[k]));
			_printNumbers(a,k+1,(n-a[k]));
		}
	}
}

void printNumber(int n) {

	int a[n];
	_printNumbers(a,0,n);
}


int main() {


	printNumber(5);


	return 0;
}
