#include <stdio.h>
#include <malloc.h>
#include "../../stackLib/stackLib.h"


typedef int DATA;

struct tree_node {
	
	DATA data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_root {
	struct tree_node *root;
};


struct tree_node* createTreeNode(DATA data) {

	struct tree_node *temp = malloc(sizeof(struct tree_node));
	if(temp) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}

	return temp;	

}


struct tree_root* createTree() {

	struct tree_root *temp = malloc(sizeof(struct tree_root));
	if(temp) {

		temp->root = NULL;
	}

	return temp;
}

void _printTree(struct tree_node *root) {

	if(root) {
		_printTree(root->left);
		printf("%d ",root->data);
		_printTree(root->right);
	}
}

void printTree(struct tree_root *tree) {

	_printTree(tree->root);
	printf("\n");
}

void _deleteTree(struct tree_node *root) {

	if(!root) 
		return;

	_deleteTree(root->left);
	_deleteTree(root->right);

	free(root);
}


void deleteTree(struct tree_root *tree) {


	_deleteTree(tree->root);
	free(tree);

}



struct tree_node *findNode(struct tree_node *root, int data, struct myStack **st) {

	struct tree_node *temp = NULL;
	if(root) {
		
		if(root->data == data){
			temp = root;
		}
		else {
			printf("pushing to stack %d\n",root->data);
			pushToStack(st,(long int)root);
			temp = findNode(root->left,data,st);
			if(!temp)
				temp = findNode(root->right,data,st);

			if(!temp)
				popFromStack(st);
		}
	}

	return temp;

}

void printDownNodes(struct tree_node *root, int k) {

	if(k<0)
		return;

	if(root) {
		printf("%d ",root->data);
		printDownNodes(root->left,k-1);
		printDownNodes(root->right,k-1);
	}

}


void printUpNodes(struct tree_node *root, struct myStack **st, int k) {


	while(!isStackEmpty(st) && k>=0) {


		struct tree_node *temp = (struct tree_node *)popFromStack(st);
		printf("%d ",temp->data);
		if(temp->left && temp->left->data != root->data) {	
			printDownNodes(temp->left,k-1);
		}
		else if(temp->right && temp->right->data != root->data) {

			printDownNodes(temp->right,k-1);
		}

		k--;

	}

}


void printKNearestNodes(struct tree_node *root, int data, int k) {

	//int n =findMaxDepth(root);
	
	struct myStack **st = createStack();

	struct tree_node *Node = findNode(root,data,st);

	printDownNodes(Node,k);
	printUpNodes(Node,st,k-1);

	deleteStack(st);
}


int main() {

	struct tree_root *tree = createTree();

	if(!tree) {
		printf("ERROR : creating tree root\n");
		return -1;
	}

	tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(20);
	tree->root->right = createTreeNode(30);
	tree->root->left->left = createTreeNode(40);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);

	printTree(tree);

	printKNearestNodes(tree->root,70,2);
	deleteTree(tree);
	return 0;
}
