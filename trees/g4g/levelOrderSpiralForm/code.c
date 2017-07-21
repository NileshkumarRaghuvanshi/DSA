#include <stdio.h>
#include <malloc.h>

#include "../../../stack/stackLib/stackLib.h"


#define push(a,b) pushToStack(a,b)
#define pop(a) popFromStack(a)


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

void levelOrderInSpiralForm(struct tree_node *root) {


	struct myStack **st1 = createStack();
	struct myStack **st2 = createStack();

	if(!root)
		return ;

	
	push(st1,(long)root);

	while(!isStackEmpty(st1) || !isStackEmpty(st2)) {


		while(!isStackEmpty(st1)) {

			struct tree_node *temp = (struct tree_node *)pop(st1);

			printf("%d ",temp->data);
			if(temp->right)
				push(st2,(long)temp->right);
			if(temp->left)
				push(st2,(long)temp->left);


		}


		while(!isStackEmpty(st2)) {
			
			struct tree_node *temp = (struct tree_node *)pop(st2);

			printf("%d ",temp->data);
			if(temp->left)
				push(st1,(long)temp->left);
			if(temp->right)
				push(st1,(long)temp->right);

		}

	}

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

	levelOrderInSpiralForm(tree->root);
	return 0;
}
