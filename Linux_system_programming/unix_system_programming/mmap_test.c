#include <stdio.h>
#include <stdlib.h>

int count;
int main() {
	printf("Su-swagatam\n");
	int rc;
	int i;

	rc =fork();
	if(rc == 0) {
		printf("I am child\n");
		for(i = 0; i<10; i++) {
			i=0;
			//printf("Child : %d\n",i);
		}
		exit(0);
	}
	else {
		printf("I am parent\n");
		for(i = 0; i<5; i++) {
			i = 0;
			//printf("Parent : %d\n",i);
			//sleep(1);

		}
		//printf("parent is sleeping\n");
	}
	
	//sleep(4);
	printf("parent exiting\n");
	return 0;
}
