/* There are two problems
**1. is to find an element which is present more than n/2 times
**2. to find an element which is present n/2 times
** We use moore's voting algorithm which is two step process
** 1. find majority element
** 2. check if the majority element is really a mojority element
**
**
** For step 1 what we do is we cancel out every occurence of majority element with every occurence of
** element other than majority element, hence if it is a majority element, it will remain till the count
** (since it is present more than n/2 times
*/


#include <stdio.h>
#include <limits.h>

int findMajorityElement(int *a, int size) {

	int majorityIndex = 0;
	int i=0;
	unsigned int count = 1;
	

	for(i=1;i<size;i++) {

		if(a[majorityIndex] == a[i])
			count++;
		else
			count--;

		if(count == -1) {
			majorityIndex = i;
			count  =1;
		}


	}


	return a[majorityIndex];

}


int checkMajorityElement(int *a, int size, int element) {

	int i=0;
	int count = 0;
	for(i=0;i<size;i++) {
		if(a[i] == element) {
			count++;
		}
	}

	if(count >= size/2)
		return element;
	else
		return 0;

}


int getMajorityElement(int *a, int size) {


	int majorityElement = findMajorityElement(a,size);

	if(checkMajorityElement(a, size, majorityElement))
		return majorityElement;	
	else
		return INT_MIN;
}


int main() {

	int a[] = {3,4,3,4,3,4,3,4,3,5,3,5};

	int element = getMajorityElement(a,(sizeof(a)/sizeof(a[0])));
	if(element != INT_MIN)	
		printf("Majority Element is %d\n",element);
	else
		printf("NONE\n");

	return 0;
}
