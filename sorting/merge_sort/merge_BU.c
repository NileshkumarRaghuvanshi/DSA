#include <stdio.h>

void print_array(int *a, int size) {

	int i=0;
        for(i=0; i<size ; i++) 
                printf("%d ",a[i]);

        printf("\n");
}


void merge(int *a, int lo, int mid, int hi) {

	int i = lo;
	int j = mid+1;
	int k = lo;

	int aux[hi];

	//printf("lo = %d, mid = %d, hi = %d\n",lo,mid,hi);

	while( k <= hi) {
	
		if(i>mid) {
			aux[k++] = a[j++];
		}
		else if(j > hi) {
			aux[k++] = a[i++];
		}
		else if(a[i] > a[j]) {
			aux[k++] = a[j++];
		}
		else {
			aux[k++] = a[i++];
		}

	}

	for(i = lo ;i<=hi ; i++ )
		a[i] = aux[i];

	print_array(a,10);
}


int minof(int a, int b) {
	return (a<b)?a:b;
}

int mergeBU(int *a, int size) {

	int interval = 1;
	int lo;
	for(interval = 1 ; interval < size ; interval*=2) {
		for(lo = 0; (lo+interval) < size; lo += interval*2) {
			merge(a,lo,lo+interval-1,minof((lo+interval+interval-1),(size-1)));
		}
	}

}

int main() {



        int a[] = {10,9,8,7,6,5,4,3,2,1};
        
        printf("before\n");
	print_array(a,sizeof(a)/sizeof(int));

        mergeBU(a,sizeof(a)/sizeof(int));

        printf("After\n");
        print_array(a,sizeof(a)/sizeof(int));

	return 0;
}
