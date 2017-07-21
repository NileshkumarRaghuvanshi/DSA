#include <stdio.h>

void print_array(int *a, int size) {
	int i;
	for(i = 0; i<size;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

void exchange(int *a, int i, int j) {
	printf("exchanging %d with %d\n",a[i],a[j]);
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int get_partition(int *a, int lo, int hi) {
	printf("partition\n");
	int partition= lo;

	int i,j;
       	i = lo+1;
	j = hi;

	printf("lo=%d, hi=%d\n",lo,hi);
	
	while(1) {
		while(a[i]<a[partition]) {
			printf("%d is less than %d\n",a[i],a[partition]);
			if(i == hi) {
				printf("i==hi breaking out\n");
				break;
			}
			i++;
		}
		printf("%d is greater than %d, returning from the first while\n",a[i],a[partition]);
		while(a[j]>a[partition]) {
			printf("%d is greater than %d\n",a[j],a[partition]);
			if(j == lo) {
				printf("j==lo breaking out\n");
				break;
			}
			j--;
		}
		
		printf("%d is less than %d, returning from the second while\n",a[j],a[partition]);

		if(j<=i) {
			printf("j<=i, updating final position of paritioned element\n");
			exchange(a,j,partition);
			return j;
		}

		exchange(a,i,j);
		print_array(a,10);
		
	}
}


void quick_sort(int *a, int lo, int hi) {
	
	printf("quick sort\n");	
	printf("lo=%d, hi=%d\n",lo,hi);

	if(hi<lo) {
		printf("hi<lo, recursion ends\n");
		return;
	}
	int partition = get_partition(a,lo,hi);
	quick_sort(a,lo,partition-1);
	quick_sort(a,partition+1,hi);
	
}

void quickSort(int *a, int size) {

	quick_sort(a,0,size-1);
}

int main() {
	
	printf("main\n");
	//int a[] = {8,1,6,9,4,10,2,5,3,7};
	//int a[] = {1,2,3,4,5,6,7,8,9,10};
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	quickSort(a,sizeof(a)/sizeof(a[0]));

	print_array(a,10);
	return 0;
}
