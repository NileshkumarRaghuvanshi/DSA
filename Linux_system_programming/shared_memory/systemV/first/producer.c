#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MAX_TRANSACTION		100

#define MAX_REQUEST_SIZE 	50
#define MAX_IP_SIZE 		50


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
	int fd, i;
	int shmid;
	int pos;
        shmid = shmget((key_t)0x9916,sizeof(struct sops_hist),IPC_CREAT|0777);
        if(shmid == -1) {
                printf("Error creating shm\n");
                return -1;
        }

        s = (struct sops_hist *)shmat(shmid,(void *)NULL,0);
        if(s == (struct sops_hist *) -1) {
                printf("Error attaching shm\n");
                return -1;
        }

        printf("Shared memory created\n");


	//sem_init(&(s->sh_sem),1,1);
	//s->start = s->end = 0;

	printf("I am producer\n");
	for(i=0;i<10;i++) {
		sem_wait(&(s->sh_sem));
		printf("lock acquired\n");
		pos = s->end++;
		printf("producer: no of enteries = %d\n",s->end);
		sem_post(&(s->sh_sem));
		printf("Lock released\n");
		s->transactions[pos].timestamp = time(NULL);
		s->transactions[pos].pid = getpid();
		strcpy(s->transactions[pos].transaction,"getInterconnectInfo");
		strcpy(s->transactions[pos].ip,"127.0.0.1");
		strcpy(s->transactions[pos].response_code,"0");
		strcpy(s->transactions[pos].fault_code,"NA");

		//sleep(2);
	}

	//shm_unlink(s);

	return 0;
}
