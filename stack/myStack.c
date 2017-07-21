#include <stdio.h>
#include <malloc.h>


struct myNode {
  int data;
  struct myNode *next;
} *listhead = NULL;

int isStackFull() {

  return 0;
}

int pushToStack(int newData) {
 
  if(isStackFull()) {
    return -1;
  }
  
  return 1;
}

int isStackEmpty() {
  
  return 0;
}


int popFromStack() {
  
  if(isStackEmpty()) {
    return -1;
  }
  
  return 1;
}

void deleteStack() {

  printf("deleting stack\n!!!");
  
}
int main() {
  
	int choice = 0;
	do {

		printf("Hello Welcome to tree programm!!!\n \
			please select any one of these option:\n \
			1. Push.\n \
			2. Pop.\n \
			3. top.\n \
			4. size of Stack\n \
			5. Delete stack\n \
			6. Configure stack\n \
			0. exit\n \
			\n");

		scanf("%d",&choice);	
		switch(choice) {
	
			case 1: {

					int newData;
					printf("Enter a new data\n");
					scanf("%d",&newData);
					if(pushToStack(newData) < 0)
					    printf("ERROR  : pushing data failed\n");
					else
					    printf("Data pushed sucessfully!!!\n");
					break;
				}

			case 2: {

					if(popFromStack() < 0)
					    printf("ERROR  : poping failed\n");
					
					break;
				}


			case 3: {
							
					printf("top entry\n");
					break;
				}


			case 4: {
					
					printf("size of the stack\n");
					break;
				}


			case 5: {
					
					printf("Deleting stack\n");
					deleteStack();
					break;
				}


			case 6: {
					
					printf("configure stack\n");
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
					break;
				}

			case 0: {
					
					printf("Exiting!!!! See you again\n");
					deleteStack();
					break;
				}
			default: {
					
					printf("please check and select right option\n");	
					break;
				}
		}

	} while(choice !=0) ;


  
  return 0;
}