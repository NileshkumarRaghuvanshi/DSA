#include <stdio.h>
#include <string.h>

//#include <stdlib.h>
//#include <malloc.h>


#define BASE 10
void print_array(int *a, unsigned int len) {
	unsigned int i;
	for(i=0; i<len;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


int find_max_num(int *a, unsigned int len) {
	
	int i;
	int temp=a[0];
	for(i=1;i<len;i++) {
		if(temp < a[i]) {
			temp = a[i];
		}
	}
	return temp;

}
void count_sort(int *a, unsigned int len,int pos) {
	//printf("Count Sort\n");
	//printf("len = %d, pos = %d\n",len,pos);

	int temp[BASE];
	int result[len];
	int i;
	memset(temp,0,sizeof(temp));

	for(i=0;i<len;i++) {

		++temp[(a[i]%(pos*BASE))/(pos)];
	}

	//print_array(temp,BASE);

	for(i=1;i<BASE;i++) 
		temp[i] += temp[i-1];

	//printf("printing temp\n");
	//print_array(temp,BASE);

	for(i=len-1;i>=0;i--) {
		result[temp[(a[i]%(pos*BASE))/pos] - 1] = a[i];
		--temp[(a[i]%(pos*BASE)/pos)];

	}

	for(i=0; i<len;i++)
		a[i] = result[i];

	//printf("printing result\n");
	//print_array(a,len);

	//print_array(a,len);

}
void radix_sort(int *a, unsigned int len) {

	printf("radix sort\n");
	int pos;

	int max_num = find_max_num(a,len);
	//printf("max num = %d\n",max_num);

	for(pos=1;max_num/pos; pos*=10) {
		count_sort(a,len,pos);
		//print_array(a,len);
	}

	//print_array(a,len)
}

int main() {


	int a[] = {312,123,456,78,99,58,499,568,1000,0,1000,58,99};
	printf("welcome\n");

	printf("before sort\n");
	print_array(a,sizeof(a)/sizeof(int));

	radix_sort(a,sizeof(a)/sizeof(int));
	
	printf("\nAfter sort\n");
	print_array(a,sizeof(a)/sizeof(int));

	
	return 0;
}
