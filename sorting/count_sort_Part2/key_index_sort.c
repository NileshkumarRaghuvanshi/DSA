/*
**There are four section in this sorting
** 1. Count the frequency of the keys(keys are data to be sorted)
** 2.
** 3.
** 4.
*/


#include <stdio.h>



struct data_base_student {

	char name[50];
	int section;

} ;


struct data_base_student data_base[] = {

	{"Nilesh",1},
	{"jayesh",3},
	{"Bhavna",2},
	{"Karan",4},
	{"deepa",2},
	{"yogesh",3},
	{"sundari",1},
	{"sapna",2},
	{"Gunja",2},
	{"Rohini",3},
	{"taniya",4},
	{"Mamta",4},
	{"kavita",1},
	{"sudesh",3},
	{"taya",2},
	{"Pinky",4},
	{"vicky",2},
	{"anand",1},
	{"aarati",2},
	{"MeriWali",3}

};



void print_array(int *arr, int size) {
	int i = 0;
	for( i =0 ; i<size ; i++) 
		printf("%d ",arr[i]);

	printf("\n");
}


void print_ds(struct data_base_student *data, int size) {

	int i = 0;
	for(i=0; i<size; i++) 
		printf("%d : %s\n",data[i].section, data[i].name);

}

void count_sort(struct data_base_student *data, int size, int base) {

	int count[(base+1)];
	struct data_base_student  aux[size];
	int i = 0;

	for(i = 0; i<base+1;i++)
		count[i] = 0;

	//step 1: count the frequency
	for(i=0;i<size;i++) 
		count[data[i].section+1]++;
	
	print_array(count,base+1);
	
	//step 2: convert the count buffer to index buffer
	for(i = 0; i<base ; i++)
		count[i+1] += count[i];

	print_array(count, base+1);


	//distribute the keys to the right places
	for(i=0 ; i< size ; i++) {
		aux[count[data[i].section]] = data[i];
		count[data[i].section]++;
	}


	//step 4: copy back to original array
	for(i = 0; i<size ; i++)
		data[i] = aux[i];
}

int main(){


	//printf("%s %d\n",data_base[12].name,data_base[12].section);

	printf("before\n");
	print_ds(data_base,sizeof(data_base)/sizeof(struct data_base_student));
	
	count_sort(data_base,sizeof(data_base)/sizeof(struct data_base_student),(4+1));

	printf("After\n");
	print_ds(data_base,sizeof(data_base)/sizeof(struct data_base_student));

	return 0;

}
