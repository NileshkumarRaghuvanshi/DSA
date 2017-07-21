#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

#define SEM_NAME_1 "/test_prod"
#define SEM_NAME_2 "/test_cons"

int main() {

	sem_t *sem1;
	sem_t *sem2;
	int err;
	sem1 = sem_open(SEM_NAME_1,O_CREAT,0666,1);
	err = errno;
	if(sem1 == SEM_FAILED) {
		printf("Failed to create producer semaphore, Eror = %d \n",err);
		exit(-1);
	}
	printf("sem = %lld \n",*((long long *)sem1));

	sem2 = sem_open(SEM_NAME_2,O_CREAT,0666,0);
	err = errno;
	if(sem2 == SEM_FAILED) {
		printf("Failed to create consumer semaphore, Eror = %d \n",err);
		exit(-1);
	}
	printf("sem = %lld \n",*((long long *)sem2));

	//while(1);
	
	printf("Waiting for consumer sem\n");
	sem_wait(sem2);
	printf("consumer sem released\n");

	sem_unlink(SEM_NAME_1);
	sem_unlink(SEM_NAME_2);

	return 0;
}
