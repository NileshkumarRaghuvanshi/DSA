#include <stdio.h>
#include <malloc.h>
#include "../../queueLib/queuelib.h"



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

void printLevelOrder(struct tree_node *root) {

	struct myQueue *q = createQueue();
	if(!q){
		printf("ERROR :creating Q\n");
		return;
	}
	
	if(!root) {
		printf("ERROR : tree is empty\n");
		return;
	}

	enQueue(&q,(long)root);

	while(!isQueueEmpty(&q)) {

		struct tree_node *temp = deQueue(&q);

		printf("%d ",temp->data);
	
		if(temp->left)
			enQueue(&q,(long)temp->left);

		if(temp->right)
			enQueue(&q,(long)temp->right);


	}
	
	printf("\n");
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
	//tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);

	printTree(tree);

	printLevelOrder(tree->root);
	return 0;
}
