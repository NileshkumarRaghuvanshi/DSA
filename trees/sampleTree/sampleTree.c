#include <stdio.h>
#include <malloc.h>

#include "queuelib.h"
#include "stackLib.h"


struct myTree  {
	int data;
	struct myTree *left;
	struct myTree *right;
};

struct myTree *myTreeRoot = NULL;

int insertaNode(int newData, struct myTree **TempTreeNode) {

	//struct myTree **TempTreeNode = inputNode;
	
	if(!(*TempTreeNode)) {
	  printf("NULL so adding an element now!!!\n");
	  *TempTreeNode = (struct myTree *)malloc(sizeof(struct myTree));
	  if(!(*TempTreeNode)) {
	     printf("Not able to allocate memory for the node!!!\n");
	     return -1;
	  }
	  printf("Allocating data =%d\n",newData);
	  (*TempTreeNode)->left = NULL;
	  (*TempTreeNode)->right = NULL;
	  (*TempTreeNode)->data = newData;
	}
	else if ( newData < ((*TempTreeNode)->data)) {
	  printf("new data = %d smaller than current root = %d, so going left\n",newData,(*TempTreeNode)->data);
	  insertaNode(newData,&(*TempTreeNode)->left);
	}
	else if ( newData > ((*TempTreeNode)->data)) {
	  printf("new data = %d greater than current root = %d, so going right\n",newData,(*TempTreeNode)->data);
	  insertaNode(newData,&(*TempTreeNode)->right);
	  
	}
	
	return 0;
}

void deleteTree(struct myTree *treeRoot) {
  
  if(treeRoot) {
    deleteTree(treeRoot->left);
    printf("Nothing on left of treeRoot->data = %d\n",treeRoot->data);
    deleteTree(treeRoot->right);
    printf("Nothing on right of treeRoot->data = %d\n",treeRoot->data);
    printf("deleting treeRoot->data = %d\n",treeRoot->data);
    free(treeRoot);
  }
/*

    if (treeRoot->left->left == NULL && treeRoot->left->right == NULL) {
     free(treeRoot->left);
     treeRoot->left = NULL;
    }
    else {
      deleteTree(treeRoot->left);
      free(treeRoot);
    }
    
    if (treeRoot->right->left == NULL && treeRoot->right->right == NULL) {
      free(treeRoot->right);
      treeRoot->right = NULL;
    }
    else {
      deleteTree(treeRoot->right);
      free(treeRoot);
    }
    */
  
}



void preOrderTraverse(struct myTree *myTreeRoot) {

  if(myTreeRoot) {
    printf("%d ", myTreeRoot->data);
    preOrderTraverse(myTreeRoot->left);
    preOrderTraverse(myTreeRoot->right);
  }
  //else
    //printf("Nothing there\n");
}

void inOrderTraversal(struct myTree *myTreeRoot) {
 
  if(myTreeRoot) {
    inOrderTraversal(myTreeRoot->left);
    printf("%d ",myTreeRoot->data);
    inOrderTraversal(myTreeRoot->right);
  }
  
  
}

void LevelOrderTraversal(struct myTree *myTreeRoot) {
 
  
  if(myTreeRoot) {
    struct myQueue *Q = createQueue();
    
    enQueue(&Q,(long)myTreeRoot);
    
    while(!isQueueEmpty(&Q)) {
      struct myTree *temp = deQueue(&Q);
      printf("%d ",temp->data);
      
      if(temp->left)
	enQueue(&Q, (long)temp->left);
      if(temp->right)
	enQueue(&Q, (long)temp->right);
      
    }
    
    deleteQueue(&Q);
    /*printf("%x ",myTreeRoot);
    printf("%x ",sizeof(myTreeRoot));
    printf("%x ",sizeof(*myTreeRoot));
    printf("%x ",sizeof(struct myTree));
    printf("%x ",sizeof(int));*/
    
    
    
  }
}


void reverseLevelOrderTraversal(struct myTree *myTreeRoot) {
  
  if(myTreeRoot) {
   struct myQueue *Q = createQueue();
   struct myStack **stacktop = creatStack();
   
   enQueue(&Q,(long)myTreeRoot);
   
   while(!isQueueEmpty(&Q)) {
     
     struct myTree *temp = deQueue(&Q);
     //printf("pushing %d ",temp->data);
     pushToStack(stacktop, temp->data);
     
     if(temp->left)
       enQueue(&Q,(long)temp->left);
     if(temp->right)
       enQueue(&Q,(long)temp->right);
     
   }
   //deleteQueue(&Q);
   while(isStackEmpty(stacktop)) {
     printf("%ld ",popFromStack(stacktop));
   }
  }
  
  printf("\n");
}

int searchANode(int data, struct myTree *myTreeRoot) {
  int retVal = 0;
  static unsigned int count = 0;
  
  if(myTreeRoot) {
    printf("Count = %u\n",++count);
    if(myTreeRoot->data == data)
      return 1;
    else {
      if(retVal = searchANode(data, myTreeRoot->left))
	return 1;
      else
	retVal = searchANode(data,myTreeRoot->right);
	    
    }
  }
  return retVal;
}

//Pass the root node of the right subtree
int getMinInSubtree(struct myTree *node) {

	int successor = -1;

	printf("checking min in right subtree\n");
	if(node->left) {
		printf("Min: going left\n");
		successor = getMinInSubtree(node->left);
	}
	else
		successor = node->data;

	return successor;
}

struct myTree *getParent(struct myTree *node, int data) {
	
	struct myTree *parent;
	struct myStack **top = creatStack();
	if(node) {
		pushToStack(top,node);
		if(node->data == data) {
			struct myTree *parent = popFromStack(top);
			return parent;
		}
		findInorderSuccessor(node->left);
		findInorderSuccessor(node->right);
	}

	return 0;

}

//One case pending which is if the data is not found 
//then need to return proper error code
int findInorderSuccessor(struct myTree *node, int data) {
	//struct myTree *parent = getParent(node,data);
	struct myTree *root = node;
	struct myTree *succ = NULL;
	while (node && (node->data != data)) {
		if(data < node->data) {
			printf("traverse ging left\n");
			node = node->left;
		}
		else {
			printf("traverse going right\n");
			node = node->right;
		}
	}
	if(node && node->right) {
		printf("Node found\n");
		return getMinInSubtree(node->right);
	}
	else if(node && !node->right) {
		printf("case 2\n");
		node = root;
		while(node) {
			if(data < node->data) {
				printf("going left\n");
				succ = node;
				node = node->left;
			}
			else if( data > node->data) {
				printf("going right\n");
				node = node->right;
			}
			else
				break;
		}
		
		return succ?succ->data:-1;
	}
	else
		printf("Data not found\n");
}


void get_size_of_tree(struct myTree *root) {

	printf("calculating size of a tree\n");
}

void get_diameter_of_tree(struct myTree *root) {

	printf("calculating diameter of a tree\n");


}

int removeANode(struct myTree **root,int data) {

	//printf("removing a node from a tree\n");
	static int rc;
	if(!(*root)) {
		printf("Node not found or tree is emty\n");
		return -1;
	}
	else {
		if(data < (*root)->data)
			removeANode(&((*root)->left),data);
		else if(data > (*root)->data)
			removeANode(&((*root)->right),data);
		else {
			printf("node found = %d \n",(*root)->data);

			if(((*root)->left) && ((*root)->right)) {
				printf("Both child are present\n");
				int sucessor = getMinInSubtree((*root)->right);
				printf("successor = %d\n",sucessor);
				(*root)->data = sucessor;
				rc = removeANode(&((*root)->right),sucessor);
			}
			else if(!((*root)->left) && ((*root)->right)) {
				printf("Only right child present\n");
				struct myTree *temp = *root;
				*root = (*root)->right;
				free(temp);
				rc = 1;
			}
			else if(((*root)->left) && !((*root)->right)) {
				printf("only left child present\n");
				struct myTree *temp = *root;
				*root = (*root)->left;
				free(temp);
				rc = 1;
			}
			else {
				printf("No child\n");
				free((*root));
				*root = NULL;
				rc = 1 ;
			}
		}
	}
	return rc;
}




int main() {

	int choice = 0;
	do {

		printf("Hello Welcome to tree programm!!!\n \
			please select any one of these option:\n \
			1. Insert a node.\n \
			2. Remove a node.\n \
			3. search a node.\n \
			4. traverse preorder\n \
			5. traverse postorder\n \
			6. traverse inorder\n \
			7. Delete a tree\n \
			8. Level order traversal\n \
			9. Level order in reverse way\n \
			10. Get Inorder successor\n \
			11. Get Size of a tree\n\
			12. Get diameter of a tree\n \
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
					if(insertaNode(newData,&myTreeRoot) < 0)
					    printf("ERROR  : inserting a node failed\n");
					else
					    printf("Data added sucessfully!!!\n");
					break;
				}

			case 2: {
					int data;
					printf("Remove a node\n");
					printf("Enter a node to be removed\n");
					scanf("%d",&data);
					if(removeANode(&myTreeRoot,data) < 0)
						printf("ERROR : removing a node\n");
					else
						printf("Node removed sucessfully!!!\n");

					break;
				}


			case 3: {

					int data;
					printf("Enter a data to search \n");
					scanf("%d",&data);
					if(searchANode(data,myTreeRoot))
					  printf("SUCESS : Element is present in the tree!!!\n");
					else
					  printf("ERROR :  Element is not present in the tree!!!\n");
					
					break;
				}


			case 4: {
					
					printf("travse preorder\n");
					preOrderTraverse(myTreeRoot);
					break;
				}


			case 5: {
					
					printf("traverse post order\n");
					break;
				}


			case 6: {
					
					printf("travese inorder\n");
					inOrderTraversal(myTreeRoot);
					break;
				}

			case 7: {
					
					printf("Deleting tree!!!\n");
					deleteTree(myTreeRoot);
					break;
				}
			case 8: {
					
					printf("travese LevelOrder\n");
					LevelOrderTraversal(myTreeRoot);
					break;
				}
			case 9: {
					
					printf("travese LevelOrder reverse\n");
					reverseLevelOrderTraversal(myTreeRoot);
					break;
				}
			case 10: {
					printf("inorder successor\n");
					printf("Enter data jiska successor chahiye\n");
					int data;
					scanf("%d",&data);
					int succ = findInorderSuccessor(myTreeRoot,data);
					if(succ >0)
						printf("succ %d\n",succ);
					else
						printf("No successor\n");
					break;
				}
			case 11: {
					
					printf("Get size of a tree\n");
					get_size_of_tree(myTreeRoot);
					break;
				}
			case 12: {
					
					printf("get diameter of a tree\n");
					get_diameter_of_tree(myTreeRoot);
					break;
				}
			case 0: {
					
					printf("Exiting!!!! See you again\n");
					deleteTree(myTreeRoot);
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
