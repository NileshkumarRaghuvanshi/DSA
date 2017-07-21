/*Counting sort 
**It needs 3 arrays
**It is not a comparison based sorting, hence the performance comes down to linear
**The linearity in performance is achieved by restricting the input set to some range
**of possible values


**It can be made stable,
**precaution need to be taken while copying the result to the destination
** or the temp result buffer. check the IMP NOTE comment below
*/
#include <stdio.h>
#include <string.h>

#define RANGE 255

void print_int_array(char *a, unsigned int len) {

	int i;
	for(i=0;i<len;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
void print_array(char *a, unsigned int len) {

	int i;
	for(i=0;i<len;i++) {
		printf("%c",a[i]);
	}
	printf("\n");
}

void count_sort(char *a, unsigned int len) {
	char temp[RANGE+1] = {0};
	char result[len];
	int i;
	//memset(temp,0,sizeof(temp));

	for(i=0;i<len;i++)
		++temp[a[i]];

	printf("printing temp size = %d\n",sizeof(temp));
	print_int_array(temp,RANGE);
	
	for(i=1;i<RANGE;i++) {
		temp[i] += temp[i-1];
		//printf("adding value %d at pos %d to value %d at pos %d\n",temp[i-1],i-1,temp[i],i);
	}

	printf("printing temp 2 size = %d\n",sizeof(temp));
	print_int_array(temp,RANGE);

//IMP NOTE: below loop starts from 0 which makes it unstable since the occurence of all 
//the repeating number are stored in reverse order, one that occured first will be stored
//at the end of the group all the similar number
//Hence to maintain the stability start the loop from end. see below stable version

	for(i=len;i>0;i--) {
		result[temp[a[i]]-1] = a[i];
		temp[a[i]]--;

	}
/* below will sort but it is not stable
	for(i=0;i<len;i++) {
		
		result[temp[a[i]]-1] = a[i];
		temp[a[i]]--;

	}	
*/
	printf("printing result size = %d\n",sizeof(result));
	print_array(result,len);

}

int main() {

	printf("Counting sort\n");
	char *str = "hakunamatata";

	printf("str %s, len %d\n",str,strlen(str));
	printf("before sort: \n");
	print_array(str,strlen(str));

	count_sort(str,strlen(str));

	printf("After sort: \n");
	print_array(str,strlen(str));

	return 0;
}
