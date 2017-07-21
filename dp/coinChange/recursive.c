#include <stdio.h>

int max(int a, int b) {

	return a>b ? a:b;
}

int maxCoinChange(int num, int *s, int size) {

	//int totalCount = 0;
	//int i =0;

	if(num ==0)
		return 1;
	else if(num < 0)
		return 0;

	if(size -1 <=0)
		return 0;
//	for(i=0; i<size; i++) {
//		
//		totalCount+=maxCoinChange(num-s[i],s,size);
//
//	}


	return (maxCoinChange(num,s+1,size-1) + maxCoinChange(num-s[0],s,size));
}


int main() {


	int s[] = {1,2,3};

	printf("max change possible %d\n",maxCoinChange(4,s,sizeof(s)/sizeof(s[0])));

	return 0;

}
