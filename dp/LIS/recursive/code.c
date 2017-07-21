#include <stdio.h>

int max(int a, int b) {
	return a>b?a:b;
}

void printArray(int *a, int size) {

	int i =0;
	for(i=0; i<size; i++)
		printf("%d ",a[i]);

	printf("\n");
}

int _getLIS(int *a, int *val, int size, int index) {

	int val1 = 0 ;
	int val2 = 0;
	if(index == size )
		return 0;

	printArray(val,size);

	if(val[index]) {
		printf("using already calculated value @ %d, value  %d\n",index,val[index]);
		return val[index];
	}

	if(index == 0 || a[index-1] < a[index]) {
		if(index == 0)
			val[index] =1;
		else
			val[index] = 1+val[index-1];

		val1 =  1 + _getLIS(a,val,size,index+1);
	}
	else {
		val[index] = 1;
		val2 =  _getLIS(a,val,size,index+1);
	}


	return max(val1,val2);
}



int getLIS(int *a, int size) {

	int val[size];
	int i;
	for(i=0 ;i<size; i++)
		val[i] = 0;

	i = _getLIS(a,val,size,0);
	
	printArray(val,size);

	return i;
}


int main() {

	int a[] = {10,22,9,33,21,50,41,60};

	int size =  sizeof(a)/sizeof(a[0]);

	printArray(a,size);	
	printf("Max LIS is %d\n",getLIS(a,size));


	return 0;
}

