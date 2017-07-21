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


int checkRootToLeafSum(struct tree_node *root, int sum) {


	int ret = 0;

	if(!root) 
		return 0;

	if((sum - root->data) == 0) {
		if(!root->left && !root->right) {
			printf("%d ",root->data);
			return 1;
		}
		else
			return 0;
	}
	
	//if(sum < 0)
	//	return 0;

	ret = checkRootToLeafSum(root->left,(sum - root->data));
	if(!ret)
		ret = checkRootToLeafSum(root->right,(sum - (root->data)));

	if(ret)
		printf("%d ",root->data);


	return ret;
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
	tree->root->left->right->right = createTreeNode(90);
	printTree(tree);

	if(checkRootToLeafSum(tree->root,150))
		printf("\nSum is present\n");
	else
		printf("\nSum is not present\n");
	
	deleteTree(tree);

	return 0;
}
