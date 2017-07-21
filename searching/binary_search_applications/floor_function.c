#include <stdio.h>

int binary_search(int *a, int lo, int hi, int element) {

	int mid = lo + (hi -lo)/2;

	printf("binary search,lo=%d,hi=%d,mid=%d,element=%d\n",lo,hi,mid,element);
	if(hi<lo) {
		printf("element is not present\n");
		//return;
		return mid;
	}

	if(a[mid] == element) {
		printf("Element present\n");
		return lo;
	}
	else if(a[mid]<element) {
		printf("goint right a[mid]=%d\n",a[mid]);
		binary_search(a,mid+1,hi,element);
	}
	else {
		printf("going left,a[mid]=%d\n",a[mid]);
		binary_search(a,lo,mid-1,element);
	}

	//return mid;


}

void get_floor_value(int *a, int size,int val) {
	printf("get floor value for %d\n",val);

	int pos = binary_search(a,0,size-1,val);

	printf("pos = %d , value @pos = %d\n",pos,a[pos]);


	if(a[pos] == val) {
		printf("floor value for %d is %d\n",val,a[pos]);
	}
	else if(a[pos-1]<val && a[pos] > val) {
		printf("floor value for %d is %d\n",val,a[pos-1]);
	}
	else if(a[pos] < val && a[pos+1] > val) {
		printf("flooe value for %d is %d\n",val,a[pos]);
	}
	else
		printf("else case\n");

}

int main() {

	int a[] = {-8,-5,-3,-1,4,6,7,9,10,11};
	int val;
	printf("enter the value you floor value of\n");
	scanf("%d",&val);
	printf("floor function\n");
	get_floor_value(a,(sizeof(a)/sizeof(a[0])),val);
	return 0;
}
