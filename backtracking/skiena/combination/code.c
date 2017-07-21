#include <stdio.h>
#include <malloc.h>


int is_a_solution(int *out, int size, int k, int n) {

	if(n == k)
		return 1;
	else
		return 0;

}


void process_solution( int *out,int n) {

	int i=0;
	for(i=0; i<n; i++)
		printf("%d ",out[i]);

	printf("\n");
}



void construct_candidates(int *a, int *out, int size, int k, int *c, int *nCandidates,int n, int start) {


	int used[size];
	int i,j;
	*nCandidates = 0;
/*
	for(i=0; i<size; i++) 
		used[i] = 0;

	for(i=0; i<k; i++) {
		//printf("written\n");	
		used[out[i]-1] = 1;
	}
*/

	for(i=0; i<(size-start); i++) {

		c[i] = a[i+start];
		(*nCandidates)++;
	}

	//process_solution(c,size);
}

void generateCombination(int *a, int *out, int size, int k, int n, int start) {

	int c[size];
	int nCandidates = 0;
	int i=0;

	if(is_a_solution(out,size,k,n)) {
		process_solution(out,n);
	}
	else {
		
		construct_candidates(a,out,size,k,c,&nCandidates,n,start);
		//process_solution(c,size);
		//printf("no of candidates %d\n",nCandidates);
		for(i =0; i<nCandidates; i++) {
			
			out[k] = c[i];
			generateCombination(a,out,size,k+1,n,i+1);
	
		}
	
	}
}


int main() {



	int a[] = {1,2,3,4,5};
	int *out = malloc(sizeof(a)/sizeof(a[0]));
	
	generateCombination(a,out,sizeof(a)/sizeof(a[0]),0,2,0);

	return 0;
}
