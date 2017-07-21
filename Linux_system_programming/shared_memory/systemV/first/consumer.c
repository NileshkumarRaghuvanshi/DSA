#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
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
	int i;
	unsigned int no_of_enteries;
	int shmid;
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


	sem_init(&(s->sh_sem),1,1);
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

                        printf("time stamp = %lld\n",(long long)s->transactions[i].timestamp);
                        printf("pid = %d\n",s->transactions[i].pid);
                        printf("transaction = %s\n",s->transactions[i].transaction);
                        printf("ip = %s\n",s->transactions[i].ip);
                        printf("response code = %s\n",s->transactions[i].response_code);
                        printf("fault code  = %s\n",s->transactions[i].fault_code);

                }
                sem_post(&(s->sh_sem));
                sleep(4);
        }
	return 0;
}
