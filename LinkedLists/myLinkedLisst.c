#include <stdio.h>
#include <malloc.h>


struct myNode {
  int data;
  struct myNode *next;
} *listhead = NULL;

int insertaNode(int newData) {
 
  struct myNode *temp = listhead;
  
  struct myNode *newNode = malloc(sizeof(struct myNode));
  if(!newNode) {
    printf("Error allocating memory!!!\n");
    return -1;
  }
  newNode->data = newData;
  newNode->next = NULL;
  
  if(!listhead) {
    printf("This is the first node!!\n");
    listhead = newNode;
  }
  else {
    printf("This is not the first node!!\n");
    for(;temp;temp = temp->next) {
      if(!(temp->next)) {
	printf("Adding to the end of the list\n");
	temp->next = newNode;
	return 0;
      }
    }
  }
}


int insertaNodeptp(int newData) {
  
  
  struct myNode **lpp  = NULL;
  struct myNode *newNode = malloc(sizeof(struct myNode));
  if(!newNode) {
    printf("Error Allocating mem for new node!!!\n");
    return -1;
  }
  newNode->data = newData;
  newNode->next = NULL;
  
  for(lpp = &listhead ; lpp ; lpp = &((*lpp)->next)) {
    if(!*lpp) {
      *lpp = newNode;
      return 0;
    } 
  }
  
  
  
  
}



int deleteANode(int deleteData) {
  
  struct myNode **lpp = &listhead;
  struct myNode *temp = NULL;
  
  for(;*lpp;lpp = &((*lpp)->next)) {
    if((*lpp)->data == deleteData ) {
      printf("Found the data to be deleted!!!\n");
      temp = *lpp;
      *lpp = (*lpp)->next;
      free(temp);
      return 0;
    }
  }
  return -1;
}

void printList() {
  
  struct myNode *temp = listhead;
  for(;temp;temp= temp->next) {
    printf("%d ",temp->data);
  }
  
  
}

void deleteList() {
  
  struct myNode *prev = listhead;
  struct myNode *nexttoprev = NULL;
  for(;prev;) {
    nexttoprev = prev->next;
    printf("deleting %d \n",prev->data);
    free(prev);
    prev = nexttoprev;
  }
  listhead = 0;
  
}

int main() {
  
	int choice = 0;
	do {

		printf("Hello Welcome to tree programm!!!\n \
			please select any one of these option:\n \
			1. Insert a node.\n \
			2. Remove a node.\n \
			3. search a node.\n \
			4. insert at location\n \
			5. print list.\n \
			6. insert with ptp\n \
			7. Delete a tree\n \
			0. exit\n \
			\n");

		scanf("%d",&choice);	
		switch(choice) {
	
			case 1: {

					int newData;
					printf("insert a node\n");
					printf("Insert data\n");
					scanf("%d",&newData);
					printf("Adding data to a node %d\n",newData);
					if(insertaNode(newData) < 0)
					    printf("ERROR  : inserting a node failed\n");
					else
					    printf("Data added sucessfully!!!\n");
					break;
				}

			case 2: {
					int newData;
					printf("Enter Node data to be removed\n");
					scanf("%d",&newData);
					if(deleteANode(newData) < 0)
					    printf("ERROR  : removing data failed\n");
					else
					    printf("Node removed successfully\n");
					break;
				}


			case 3: {
							
					printf("Search a node\n");
					break;
				}


			case 4: {
					
					printf("travse preorder\n");
					//preOrderTraverse(myTreeRoot);
					break;
				}


			case 5: {
					
					printf("printing the linked list data\n");
					printList();
					break;
				}


			case 6: {
					
					printf("insert with ptp\n");
					int newData;
					printf("insert a node\n");
					printf("Insert data\n");
					scanf("%d",&newData);
					printf("Adding data to a node %d\n",newData);
					if(insertaNodeptp(newData) < 0)
					    printf("ERROR  : inserting a node failed using ptp\n");
					else
					    printf("Data added sucessfully using ptp !!!\n");
					break;
				}

			case 7: {
					
					printf("Deleting tree!!!\n");
					deleteList();
					break;
				}
			case 0: {
					
					printf("Exiting!!!! See you again\n");
					deleteList();
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