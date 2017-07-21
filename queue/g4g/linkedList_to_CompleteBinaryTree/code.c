#include <stdio.h>
#include "linked_listQ.h"
#include <malloc.h>
#include <limits.h>


struct tree_node {
	int data;
	struct tree_node *left, *right;
};

struct tree_root {
	struct tree_node *root;
};

struct tree_root * createTree() {

	struct tree_root *temp = malloc(sizeof(struct tree_root));
	if(temp) {
		temp->root = NULL;
	}
	
	return temp;
}

struct tree_node *createTreeNode(int data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));

	if(temp) {
		temp->data = data;
		temp->left = temp->right = NULL;
	}

	return temp;
}

void convertLinkedListToCompleteBinaryTree(struct queue_head *ll, struct tree_root **tree) {

	struct queue_head *q = createQ();
	struct queue_node *node = ll->front;
	struct tree_node **tempNode;
	if(!ll || !*tree) {
		printf("error input arguments\n");
		return;
	}

	if(!node) {
		printf("linked list is empty\n");
		return;
	}

	(*tree)->root = createTreeNode(node->data);
	enqueue(q,(DATA)&((*tree)->root));
	printf("Root %d is pushed\n",node->data);
	node = node->next;

	tempNode = (struct tree_root **)dequeue(q);
	while(tempNode != (struct tree_root **)INT_MIN) {

		if(node) {
			printf("Creating a left child :%d\n",node->data);
			(*tempNode)->left = createTreeNode(node->data);
			//printf("Here\n");
			node = node->next;
		}
		else {
			printf("No more nodes left in Linked list\n");
			return;
		}

		if(node) {
			printf("creating a right child :%d\n",node->data);
			(*tempNode)->right  = createTreeNode(node->data);
			node = node->next;
		}
		else {
			printf("no more nodes left in linked list\n");
			return;
		}
		
		enqueue(q,(DATA)&((*tempNode)->left));
		enqueue(q,(DATA)&((*tempNode)->right));

		//node = node->next;
		tempNode =(struct tree_root **) dequeue(q);

	}

}


void printTree(struct tree_node *root) {


	if(root) {
		printTree(root->left);
		printf("%d ",root->data);
		printTree(root->right);
	}

}

int main() {

	struct queue_head *ll = createQ();
	struct tree_root *tree = createTree();
	enqueue(ll,1);	
	enqueue(ll,2);
	enqueue(ll,3);
	enqueue(ll,4);
	enqueue(ll,5);
	enqueue(ll,6);
	enqueue(ll,7);
	enqueue(ll,8);

	convertLinkedListToCompleteBinaryTree(ll,&tree);
	printTree((tree)->root);
	printf("\n");

	return 0;

}
