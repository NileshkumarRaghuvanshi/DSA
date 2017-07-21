#include <stdio.h>
#include <malloc.h>
#include "../../stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


struct tree_node {

	int data;
	struct tree_node *left;
	struct tree_node *right;
};


struct tree_root {
	struct tree_node *root;
};

struct tree_node *createNode(int data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));
	if(temp) {
		temp->data = data;
		temp->left = temp->right = NULL;

	}

	return temp;
}


struct tree_root* createTree () {

	struct tree_root *temp = malloc(sizeof(struct tree_root));
	if(temp) {
		temp->root = NULL;
	}

	return temp;
}

void printInorder(struct tree_node *root) {

	if(root) {
		printInorder(root->left);
		printf("%d ",root->data);
		printInorder(root->right);
	}
}



void printAncestorWORecursion(struct tree_node *root, int data) {
	
	struct myStack **st = createStack();
	
	if(!root) 
		return;
	
	while(1) {
			
		while(root && root->data != data) {
			push(st,(long int)root);
			root = root->left;
		}

		if(root && root->data == data) {
			break;
		}


		while(!((struct tree_node *)topOfStack(st))->right || root == (((struct tree_node *)topOfStack(st))->right)) {
			root = (struct tree_node *)pop(st);
			//printf("poping %d\n",root->data);
		}

		//printf("top of stack %d\n",((struct tree_node *)topOfStack(st))->data);
		root = ((struct tree_node *)topOfStack(st))->right;
		//printf("going right of %d\n",((struct tree_node *)topOfStack(st))->data);

	}

	while(!isStackEmpty(st))
		printf("%d ",((struct tree_node *)pop(st))->data);

}


int printAncestor(struct tree_node *root, int data) {

	int found = 0;
	if(!root)
		return 0;

	if(root->data == data)
		return 1;
	
	found = printAncestor(root->left,data);
	if(!found)
		found = printAncestor(root->right,data);
	
	if(found) {
		printf("%d ",root->data);
		return found;
	}

}


int main() {

	struct tree_root *tree = createTree();
	if(!tree) {
		printf("error : creating tree\n");
		return -1;
	}

	tree->root = createNode(10);
	tree->root->left = createNode(20);
	tree->root->right = createNode(30);
	tree->root->left->left = createNode(40);
	tree->root->left->right = createNode(50);		
	tree->root->right->left = createNode(60);		
	tree->root->right->right = createNode(70);
	tree->root->left->left->left = createNode(80);


	printInorder(tree->root);
	printf("\n");

	printAncestor(tree->root,60);
	printf("\n");
	printAncestorWORecursion(tree->root,60);
	printf("\n");
	return 0;
}
