#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_TRANSACTION		100

#define MAX_REQUEST_SIZE 	50
#define MAX_IP_SIZE 		50
#define FILE_PATH		"/home/nilesh/dsa/linux_system/shared_memory/systemV/shm_file"

struct soap_hist_data {
	time_t timestamp;
	int pid;
	char transaction[MAX_REQUEST_SIZE];
	char ip[MAX_IP_SIZE];
	char response_code[3];
	char fault_code[3];

};

struct sops_hist {
	sem_t sh_sem;
	unsigned int start;
	unsigned int end;
	struct soap_hist_data transactions[MAX_TRANSACTION];	
};



int main() {

	struct sops_hist *s;
	void *shm_add = (void *)0;
	//int shm_add_int;
	int fd, i;
	int err;
	key_t shm_key;
	int no_of_enteries;
	int shmid;

	printf("size of struct = %d\n",sizeof(struct sops_hist));
	shm_key = ftok(FILE_PATH,0);
	printf("key  =  0X%x\n",shm_key);
	shmid = shmget(shm_key,sizeof(struct sops_hist),0777| IPC_CREAT);
	if(shmid == -1) {
		printf("Error : creating the shm mem\n");
		return -1;
	}

	shm_add = shmat(shmid,(void *)NULL,0);
	err = errno;
	if(s == (void *)-1) {
		printf("Error attaching the shared memory, errno = %d\n",err);
		return -1;
	}

	printf("Shared memory created\n");

	s = (struct sops_hist *)shm_add;

	//if(sem_init(&(s->sh_sem),1,1) == -1) {
	//	printf("Error doing sem_init\n");
	//	return -1;
	//}

	s->start = s->end = 0;

	printf("I am Consumer\n");
	while(1) {
		sem_wait(&(s->sh_sem));
		printf("Consumer lock acquired\n");
		no_of_enteries = s->end;
		//sem_post(&(s->sh_sem));
		printf("Consumer lock released\n");
		printf("Total no of enteries = %d \n",no_of_enteries);

		for(i =0; i< no_of_enteries; i++) {
			
			printf("time stamp = %lld\n",s->transactions[i].timestamp);
			printf("pid = %d\n",s->transactions[i].pid);
			printf("transaction = %s\n",s->transactions[i].transaction);
			printf("ip = %s\n",s->transactions[i].ip);
			printf("response code = %s\n",s->transactions[i].response_code);
			printf("fault code  = %s\n",s->transactions[i].fault_code);

		}
		sem_post(&(s->sh_sem));
		sleep(4);
	}

	shm_unlink("soap_hist");

	return 0;
}
