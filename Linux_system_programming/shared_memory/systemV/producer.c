#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>

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
	int pos;
	fd = shm_open("soap_hist",O_RDWR,0666);
	if(fd == -1) {
		printf("Error opening a shared memory region\n");
		exit(-1);
	}
	s = (struct sops_hist *)mmap(NULL,sizeof(struct sops_hist),PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
	if(s == MAP_FAILED) {
		printf("ERROR : mapping a memory to process\n");
		exit(-1);
	}
	/*if(ftruncate(fd, sizeof(struct sops_hist)) == -1) {
		printf("ERROR: fruncate\n");
		exit(-1);
	}*/
	close(fd);

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
