#include <stdio.h>
#include <malloc.h>

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

void convertTree(struct tree_node *root) {


	int lval = 0;
	int rval = 0;
	if(!root)
		return;

	convertTree(root->left);
	convertTree(root->right);

	if(root->left == NULL && root->right == NULL)
		return;


	if(root->left)
		lval = root->left->data;

	if(root->right) 
		rval = root->right->data;


	if((root->data) < (lval+rval)) {

		root->data = lval + rval;
	}
	else if((root->data) > (lval+rval)) {

		struct tree_node *temp = NULL;
		printf("Calling from special case for %d\n",root->data);
		if(root->left) {
	
			temp = root->left;
			temp->data = root->data - rval;

		}
		else {

			temp = root->right;
			temp->data = root->data;

		}
		convertTree(temp);
	}

}
int main() {

	struct tree_root *tree = createTree();

	if(!tree) {
		printf("ERROR : creating tree root\n");
		return -1;
	}
/*
	tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(20);
	tree->root->right = createTreeNode(30);
	tree->root->left->left = createTreeNode(40);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);
*/

	tree->root = createTreeNode(500);
	tree->root->left = createTreeNode(10);
	tree->root->right = createTreeNode(40);
	tree->root->left->left = createTreeNode(3);
	//tree->root->left->right = createTreeNode(50);
	//tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(20);
	//tree->root->left->left->left = createTreeNode(80);

	printTree(tree);

	convertTree(tree->root);

	printTree(tree);


	return 0;
}
