//Sorting an array of structure
#include <stdio.h>

struct emp {
	int number;
	int empid;
};

int compfunc(const void *a, const void *b) {


	return (((struct emp *)a)->number) - (((struct emp *)b)->number);

}

void print(struct emp *database, int size) {

	int i=0;
	for(i=0; i<size; i++) {
		printf("number = %d, empid = %d\n",database[i].number,database[i].empid);
	}
}


int main() {

	struct emp database[7];

	database[0].number = 6;
	database[0].empid = 1212;
	database[1].number = 1;
	database[1].empid = 1212;
	database[2].number = 5;
	database[2].empid = 1212;
	database[3].number = 3;
	database[3].empid = 1212;
	database[4].number = 7;
	database[4].empid = 1212;
	database[5].number = 2;
	database[5].empid = 1212;
	database[6].number = 4;
	database[6].empid = 1212;



	print(database,7);
	qsort(database,7,sizeof(struct emp),compfunc);
	printf("=================================================\n");
	print(database,7);



	return 0;
}
