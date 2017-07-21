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


int getMax(int a, int b, int c) {

	if(a>b && a>c) 
		return a;
	else if(b>a && b>c) 
		return b;
	else 
		return c;
}

int getMaxPathSum(struct tree_node *root, int *maxSum) {


	int lSum = 0;
	int rSum = 0;
	if(!root)
		return 0;


	lSum = getMaxPathSum(root->left,maxSum);
	rSum = getMaxPathSum(root->right,maxSum);

	if((lSum + rSum + root->data) > *maxSum) {
		*maxSum = lSum + rSum + root->data;
	}
	
	if((lSum + root->data) > *maxSum) {
		*maxSum = (lSum + root->data);
	}

	if((rSum + root->data) > *maxSum) {
		*maxSum = (rSum + root->data);
	}


	return getMax((rSum + root->data), root->data,(lSum+root->data));


}


int main() {

	struct tree_root *tree = createTree();
	int maxSum = 0;
	if(!tree) {
		printf("ERROR : creating tree root\n");
		return -1;
	}

	/*tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(20);
	tree->root->right = createTreeNode(30);
	tree->root->left->left = createTreeNode(40);
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);*/

	tree->root = createTreeNode(10);
	tree->root->left = createTreeNode(2);
	tree->root->right = createTreeNode(10);
	tree->root->left->left = createTreeNode(20);
	tree->root->left->right = createTreeNode(1);
	tree->root->right->right = createTreeNode(-25);
	tree->root->right->right->right = createTreeNode(4);
	tree->root->right->right->left = createTreeNode(3);

	printTree(tree);

	getMaxPathSum(tree->root,&maxSum);
	printf("Max sum is %d\n",maxSum);

	deleteTree(tree);
	return 0;
}
