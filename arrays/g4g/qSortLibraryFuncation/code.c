#include <stdio.h>

int ascending(const void *a,const void *b) {

	int *l = (int *)a;
	int *m = (int *)b;

	if(*l > *m) 
		return 1;
	else if( *l < *m)
		return -1;

	return 0;
}

int descending(const void *a,const void *b) {

	int *l = (int *)a;
	int *m = (int *)b;

	if(*l > *m) 
		return -1;
	else if( *l < *m)
		return 1;

	return 0;
}


void printArray(int *a, int size) {

	int i;
	for(i = 0; i<size; i++)
		printf("%d ",a[i]);
	
	printf("\n");

}
int main() {

	int a[] = {3, 5, 3, 10, 6, 8};
	
	printArray(a,sizeof(a)/sizeof(a[0]));
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),ascending);
	printArray(a,sizeof(a)/sizeof(a[0]));
	
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),descending);
	printArray(a,sizeof(a)/sizeof(a[0]));

	return 0;
}
