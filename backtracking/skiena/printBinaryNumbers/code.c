#include <stdio.h>
#include <malloc.h>


int is_a_solution(int *out, int size, int k) {

	if(size == k)
		return 1;
	else
		return 0;

}


void process_solution(int *a, int *out,int size) {

	int i=0;
	for(i=0; i<size; i++) {
		printf("%d ",out[i]);
	}
	printf("\n");
}



void construct_candidates(int *a, int *out, int size, int k, int *c, int *nCandidates) {

	*nCandidates = 2;

	c[0] = 0;
	c[1] = 1;
}

void generatePermutation(int *a, int *out, int size, int k) {

	int c[size];
	int nCandidates = 0;
	int i=0;

	if(is_a_solution(out,size,k)) {
		process_solution(a,out,size);
	}
	else {
		
		construct_candidates(a,out,size,k,c,&nCandidates);
		for(i =0; i<nCandidates; i++) {
			
			out[k] = c[i];
			generatePermutation(a,out,size,k+1);
	
		}
	
	}
}


int main() {



	int a[] = {1,2,3};
	int *out = malloc(sizeof(a)/sizeof(a[0]));
	
	generatePermutation(a,out,sizeof(a)/sizeof(a[0]),0);

	return 0;
}
