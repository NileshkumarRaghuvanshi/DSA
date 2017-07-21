#include <stdio.h>

/*
int less(int a, int b) {
	printf("comparing %d with %d\n",a,b);	
	return ((a==b)?0:((a>b)?1:-1));
}
*/

char less(int a, int b) {
	printf("comapraing %d with %d\n",a,b);
	return (a<b)?1:0;
}
void print_array(int a[], int size) {
	int i;
	for(i=0;i<size;i++)
		printf("%d ",a[i]);

	printf("\n");
}

void merge(int a[], int lo, int mid, int hi) {
	
	int aux[hi];
	int i = lo;
	int j = mid+1;
	int k = lo;
	int temp;
	printf("merge routine\n");
	printf("lo = %d, mid = %d,hi =%d \n",lo,mid,hi);

	for(i=lo; i<=hi ;i++)
		aux[i] = a[i];
	i = lo;
	while(k<=hi) {
		if(i>mid) {
			printf("appending right half\n");
			a[k++] = aux[j++];
		}
		else if(j>hi) {
			printf("appending left half\n");
			a[k++] = aux[i++];
		}
		else if(less(aux[i],aux[j])) {
			printf("less\n");
			a[k++] = aux[i++];
		}
		else {
			printf(">=\n");
			a[k++] = aux[j++];
		}

		print_array(a,13);
		//print_array(aux,10);
	}
}

void merge_sort(int *a, unsigned int lo, unsigned int hi) {

	//printf("before sort\n");
	//print_array(a,10);
	printf("lo= %d, hi = %d\n",lo,hi);
	int mid;
	if(hi <= lo)
		return;
	mid = lo + (hi -lo)/2;
	printf("mid = %d\n",mid);
	merge_sort(a,lo,mid);
	printf("second recursion\n");
	merge_sort(a,mid+1,hi);
	merge(a,lo,mid,hi);

}

int main() {

	//int a[] = {1,2,3,5,7,4,6,8,9,10};
	int a[] = {13,12,11,10,9,8,7,6,5,4,3,2,1};

	merge_sort(a,0,(sizeof(a)/sizeof(int))-1);

	return 0;
}
