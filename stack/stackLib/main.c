#include <stdio.h>
#include "stackLib.h"


int main() {
  
  int choice = 0;
  struct myStack **top = createStack();
	do {

		printf("Hello Welcome to stack programm!!!\n \
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

					long newData;
					printf("Enter a new data\n");
					scanf("%ld",&newData);
					if(pushToStack(top,newData) < 0)
					    printf("ERROR  : Queuing data failed\n");
					else
					    printf("Data queued sucessfully!!!\n");
					break;
				}

			case 2: {
					long data = popFromStack(top);
					if( data < 0)
					    printf("ERROR  : poping failed\n");
					else
					  printf("data popped = %ld\n", data);
					break;
				}


			case 3: {
					//int data = sizeOfStack(top);
					if(sizeOfStack(top))
					  printf("Top entry = %ld\n",topOfStack(top));
					else
					  printf("No data in stack!!!\n");
					break;
				}


			case 4: {
					
					printf("size of the stack = %u\n",sizeOfStack(top));
					break;
				}


			case 5: {
					
					printf("Deleting stack\n");
					deleteStack(top);
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
					deleteStack(top);
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
