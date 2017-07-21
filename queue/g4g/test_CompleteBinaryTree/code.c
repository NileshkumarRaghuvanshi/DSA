#include <stdio.h>
#include <malloc.h>
#include "../queueGeneric/linked_listQ.h"

//typedef long long int DATA;

struct tree_node {

	int data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_root {
	struct tree_node *root;
};


struct tree_root *createTree() {

	struct tree_root *temp = malloc(sizeof(struct tree_root));
	if(temp) {
		temp->root = NULL;
	}

	return temp;
}

struct tree_node *createNode(int data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));
	if(temp) {

		temp->left = temp->right = NULL;
		temp->data = data;
	}

	return temp;
}


int isCompleteBinaryTree(struct tree_node *root) {

	struct queue_head *q = createQ();
	struct tree_node *temp = NULL;
	int leftChildFlag = 0;
	if(root)
		enqueue(q,(DATA)root);


	while(!isEmpty(q)) {

		temp = (struct tree_node *)dequeue(q);
		
		if(temp->left) {
			if(leftChildFlag)
				return 0;
			enqueue(q,(DATA)temp->left);
		}
		else
			leftChildFlag = 1;

		if(temp->right) {
			if(leftChildFlag)
				return 0;
			enqueue(q,(DATA)temp->right);
		}
		else
			leftChildFlag =1;


	}

	return 1;
}

void inorderTree(struct tree_node *root) {

	if(root) {
		
		inorderTree(root->left);
		printf("%d ",root->data);
		inorderTree(root->right);
	}
}


int main() {


	struct tree_root *tree = createTree();

	tree->root = createNode(10);
	tree->root->left = createNode(20);
	tree->root->right = createNode(30);
	tree->root->left->left = createNode(40);
	tree->root->left->right = createNode(50);
	tree->root->right->left = createNode(60);
	tree->root->right->right = createNode(70);

	inorderTree(tree->root);
	printf("\n");

	if(isCompleteBinaryTree(tree->root))
		printf("Tree is complete Binary tree\n");
	else
		printf("Tree is not a complete Binary tree\n");

	return 0;
}
