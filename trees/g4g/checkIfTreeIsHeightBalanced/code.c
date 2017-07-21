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

int getHeight(struct tree_node *root) {

	int lHeight =0;
	int rHeight = 0;
	if(!root)
		return 0;

	
	lHeight = getHeight(root->left);
	rHeight = getHeight(root->right);

	if(lHeight>rHeight)
		return lHeight + 1;
	else
		return rHeight + 1;

}


int checkHeightBalance(struct tree_node *root) {


	int lHeight = 0;
	int rHeight = 0;
	int ret = 0;
	if(!root)
		return 1;


	lHeight = getHeight(root->left);
	rHeight = getHeight(root->right);


	ret = checkHeightBalance(root->left);
	if(ret) {
		ret = checkHeightBalance(root->right);
		if(ret) {
			if(abs(lHeight - rHeight) >= 2)
				ret = 0;
		}
		
	}


	return ret;
	

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
	//tree->root->left->left->left->left = createTreeNode(90);

	printTree(tree);

	if(checkHeightBalance(tree->root))
		printf("Tree is height balanced\n");
	else
		printf("Tree is not height balanced\n");

	deleteTree(tree);
	return 0;
}
