#include <stdio.h>

int max(int a, int b) {
	return a>b?a:b;
}
int min(int a, int b) {
	return a<b?a:b;
}


int getMedian(int *a, int size) {

	if((size%2) == 0) 
		return ((a[size/2] + a[size/2 -1])/2);
	else
		return (a[size/2]);

}

int findMedian(int *a, int *b, int size) {

	int m1 = 0;
	int m2 = 0;
	int median = 0;
	if(size == 1) {
		if(a[0] != b[0])
			return (a[0]+b[0])/2;
		else
			return a[0];
	}
	if(size == 2 ) {
		return ((max(a[0],b[0]) + min(a[1],b[1]))/2);
	}

	m1 = getMedian(a,size);
	m2 = getMedian(b,size);

	if(m1 == m2) {
		return m1;
	}
	else if(m1 < m2) {
		if(size%2)
			median = findMedian(a+(size/2),b,(size/2)+1);
		else
			median = findMedian(a+(size/2 - 1),b,(size/2)+1);
	}
	else {

		if(size%2)
			median = findMedian(a,b+(size/2),(size/2)+1);
		else
			median = findMedian(a,b+(size/2 -1),(size/2)+1);

	}


	return median;

}


int main() {

	int a[] = {1,4,9,12,20,25};
	int b[] = {2,5,9,15,18,30};

	int a_size = (sizeof(a)/sizeof(a[0]));
	int b_size = (sizeof(b)/sizeof(b[0]));

	if(a_size == b_size)
		printf("Median is %d\n",findMedian(a,b,b_size));
	else
		printf("ERROR : both array should have same lengh\n");



	return 0;
}
