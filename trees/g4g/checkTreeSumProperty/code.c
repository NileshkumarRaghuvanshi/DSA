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


int checkChildrenSumProperty(struct tree_node *root) {

	int lVal = 0;
	int rVal = 0;
	//int ret1 = 0;
	//int ret2 = 0;

	if(!root)
		return 1;

	if(root->left == NULL && root->right == NULL)
		return 1;

	if(root->left != NULL) 
		lVal = root->left->data;

	if(root->right != NULL) 
		rVal = root->right->data;


	if(root->data == (lVal + rVal)) 
		return checkChildrenSumProperty(root->left) && checkChildrenSumProperty(root->right);


	return 0;

}

int main() {

	struct tree_root *tree = createTree();

	if(!tree) {
		printf("ERROR : creating tree root\n");
		return -1;
	}

	tree->root = createTreeNode(270);
	tree->root->left = createTreeNode(140);
	tree->root->right = createTreeNode(130);
	tree->root->left->left = createTreeNode(90);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(90);

	printTree(tree);

	if(checkChildrenSumProperty(tree->root))
		printf("Tree complies to the childresn sum property\n");
	else
		printf("Tree does not comply to the children sum property\n");

	return 0;
}
