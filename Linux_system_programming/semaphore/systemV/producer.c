#include<stdio.h>
#include <sys/sem.h>

//#include "soap_history_structures.h"
#include "semun.h"

#define SEM_ID (key_t)0x991638

void wait_semaphore(int semid,struct sembuf *sem_buf, int sem_num) {

	int rc;
	printf("Locking a semaphore\n");

	sem_buf->sem_num = 0;
	sem_buf->sem_op = -1;
	sem_buf->sem_flg = SEM_UNDO;
	rc = semop(semid,sem_buf,1);
	if(rc == -1)
		printf("ERROR : Locking a sempahore\n");
	else
		printf("seamphore locked\n");

}


void post_semaphore(int semid,struct sembuf *sem_buf, int sem_num) {

	int rc;
	printf("releasing a semaphore\n");
	
	sem_buf->sem_num = 0;
	sem_buf->sem_op = 1;
	sem_buf->sem_flg = SEM_UNDO;
	rc = semop(semid,sem_buf,1);
	if(rc == -1)
		printf("ERROR : releaing a sempahore\n");
	else
		printf("seamphore released\n");

}
int main() {
	
	int semid;
	union semun sem_union;
	int rc;
	struct sembuf sem_buf;
	semid = semget((key_t)1234,1,0666|IPC_CREAT);
	if(semid == -1) {
		printf("ERROR : Creating semaphore\n");
		return -1;
	}
	
	sem_union.val = 0;
	rc = semctl(semid,0,SETVAL,sem_union);
	if(rc == -1) {
		printf("ERROR : seting a value to semaphore\n");
		return -1;
	}

	printf("producer locking a semaphore\n");
	wait_semaphore(semid,&sem_buf,0);
	printf("PRODUCER : woken up\n");
	//sleep(2);
	//printf("producer releasing a semaphore\n");
	//post_semaphore(semid,&sem_buf,0);


	rc = semctl(semid,0,IPC_RMID);
	if(rc == -1) {
		printf("ERROR : removing a sempahore\n");
		return -1;
	}

	printf("PRODUCER : semaphore is removed from system\n");

	return 0;
}

