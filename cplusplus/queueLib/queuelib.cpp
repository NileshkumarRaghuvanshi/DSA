#include <stdio.h>
#include <malloc.h>

#include "queuelib.h"



int enQueue(struct myQueue **Q, long data) {

  struct myQueueList *temp = (struct myQueueList *)malloc(sizeof(struct myQueueList));
  if(!temp) {
    printf("ERROR : Allocating memory to new entry failed!!!\n");
    return -1;
  }
  temp->data = data;
  temp->next = NULL;
  
  if((*Q)->rear)
   ((*Q)->rear)->next = temp; 
 
  (*Q)->rear = temp;
  if(!((*Q)->front))
   (*Q)->front = temp;
 
  return 0;
}

int deQueue(struct myQueue **Q) {
  
  struct myQueueList *temp = (*Q)->front;
  int data;
  if(temp) {
    data = ((*Q)->front)->data;
    (*Q)->front = ((*Q)->front)->next;
    free(temp);
  }
  else
    return -1;
  
 return data; 
}


int frontElement(struct myQueue **Q) {
  return (((*Q)->front== NULL)? -1:(*Q)->front->data);
}
int sizeQueue(struct myQueue **Q) {
  unsigned int len = 0;
  struct myQueueList *temp = ((*Q)->front);
  while(temp) {
    len++;
    temp = temp->next;
  }
  return len;
}

int isQueueEmpty(struct myQueue **Q) {
  return (((*Q)->front == NULL) ? 1: 0);
}


void deleteQueue(struct myQueue **Q){ 
  
  struct myQueueList *temp = ((*Q)->front);
  while(temp) {
    printf("deleting %d \n",(temp->data));
    (*Q)->front = (*Q)->front->next;
    free(temp);
    temp = ((*Q)->front);
  }
  free(*Q);
  printf("%x\n",*Q);
  *Q = NULL;
}

struct myQueue * createQueue() {

  struct myQueue *temp = NULL;
  temp = (struct myQueue *)malloc(sizeof(struct myQueue));
  if(!temp) {
    printf("ERROR : Allocating memory failed!!!\n");
    return NULL;
  }
  
  temp->front = temp->rear = NULL;
  printf("q = %x\n",temp);
  return temp;
}


void printQueue(struct myQueue **Q) {
  
  struct myQueueList *temp = ((*Q)->front);
  while(temp) {
    printf("%d ",(temp->data));
    temp = temp->next;
  }
  
}
void printQueueMenu() {
  

    struct myQueue *myQ = NULL;
    int choice = 0;
	do {
		printf("Hello Welcome to queue programm!!!\n \
			please select any one of these option:\n \
			1. Create Queue \n \
			2. EnQueue.\n \
			3. Dequeue.\n \
			4. Front.\n \
			5. size of Queue\n \
			6. Delete Queue\n \
			7. Configure Queue\n \
			8. Print Queue\n \
			0. exit\n \
			\n");

		scanf("%d",&choice);	
		switch(choice) {

			case 1: {
					printf("Creating a Queue\n");
					myQ = createQueue();
					if(!myQ)
					  printf("ERROR : Not able to create Queue\n");
					
					printf("Successfully created a Queue\n");
					break;
				}

			case 2: {

					long newData;
					printf("Enter a new data\n");
					scanf("%l",&newData);
					if(!(myQ))
					  myQ = createQueue();
					
					if(enQueue(&myQ,newData) < 0)
					    printf("ERROR  : queuing data failed\n");
					else
					    printf("Data queued sucessfully!!!\n");
					break;
				}

			case 3: {
					if(!(myQ))
					  myQ = createQueue();
					
					int data = deQueue(&myQ);
					if( data < 0)
					    printf("ERROR  : Dequeue data failed\n");
					else
					  printf("data dequeued = %d\n", data);
					break;
				}


			case 4: {
					if(!(myQ))
					  myQ = createQueue();
					
					if(!isQueueEmpty(&myQ))
					  printf("Front entry = %d\n",frontElement(&myQ));
					else
					  printf("No data in queue!!!\n");
					break;
				}


			case 5: {
					if(!(myQ))
					  myQ = createQueue();
					
					printf("size of the Q = %u\n",sizeQueue(&myQ));
					break;
				}


			case 6: {
					
					printf("Deleting Q\n");
					if(!(myQ))
					  myQ = createQueue();
					
					printf("%x \n",myQ);
					deleteQueue(&myQ);
					break;
				}
			case 8: {
					
					printf("printg Q\n");
					if(!(myQ))
					  myQ = createQueue();
					
					printQueue(&myQ);
					break;
				}


			case 7: {
					
					printf("configure Q\n");
#if 0
					int choice = 0;
					do {

					      printf("Hello Welcome to stack configure menu!!!\n \
					      please select any one of these option:\n \
					      1. configure stack max sise.\n \
					      0. exit\n \
					      ");

					      scanf("%d",&choice);
					      
					      switch(choice) {
	
					      case 1: {
							    int maxSize;
							    printf("configure the max size of stack\n");
							    printf("Enter Max size of the stack\n");
							    scanf("%d",&maxSize);
							    break;
						      }

					      case 0: {
							    printf("Exting configuration menu!!!\n");
							    break;
						      }
					      }
					      
					} while (choice != 0);
#endif
					break;
				}

			case 0: {
					
					printf("Exiting!!!! See you again\n");
					if(!(myQ))
					  myQ = createQueue();
					
					deleteQueue(&myQ);
					break;
				}
			default: {
					
					printf("please check and select right option\n");	
					break;
				}
		}

	} while(choice !=0) ;
  
}
