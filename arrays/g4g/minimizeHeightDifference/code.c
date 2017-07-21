#include <stdio.h>

void print_array(int *a, int size) {

	int i=0;
	for(i=0;i<size;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}
void minimizeDifference(int *a, int size, int k) {

	int avg = 0;
	int i=0;
	int p,q;
	for(i=0;i<size;i++)
		avg+=a[i];
	avg = avg/size;

	printf("avg = %d\n",avg);
	
	for(i=0; i<size; i++) {

		p = a[i] + k;
		q = a[i] - k;
/*
		if(a[i] > avg) {
	
			a[i]-=k;	

		}
		else if(a[i] < avg) {
			
			a[i]+=k;

		}
		else {

*/			if(i!=0) {
				if(abs(p-a[i-1]) <= abs(q-a[i-1]))
					a[i]+=k;
				else
					a[i]-=k;
			}
			else
				a[i]+=k;
		//}

		print_array(a,sizeof(a)/sizeof(a[0]));
	}
}




int main() {

	int k = 6;
	int a[] = {1,5,6,7,8,9,10};
	
	printf("before\n");
	print_array(a,(sizeof(a)/sizeof(a[0])));
	minimizeDifference(a,(sizeof(a)/sizeof(a[0])),k);
	printf("After\n");
	print_array(a,(sizeof(a)/sizeof(a[0])));
	return 0;
}

