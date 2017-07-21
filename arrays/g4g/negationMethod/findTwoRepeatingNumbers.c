#include <stdio.h>

void findTwoRepeatingNumbers(int *a, int size) {

	int i =0;
	for(i=0; i<size; i++) {


		if(a[abs(a[i])-1] < 0) {
			printf("%d ",abs(a[i]));
		}
		else
			a[abs(a[i])-1] = -a[abs(a[i])-1];
	}



}


int main() {


	int a[] = {5,4,3,4,2,1,6,6,5,2,1,3};
	findTwoRepeatingNumbers(a,sizeof(a)/sizeof(a[0]));

	return 0;
}
