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


struct tree_node* removeAllHalfNodes(struct tree_node *root) {


	if(!root) {
		return NULL;

	}

	root->left = removeAllHalfNodes(root->left);
	root->right = removeAllHalfNodes(root->right);

	if(root->left && root->right) 
		return root;
	if(!root->left && !root->right)
		return root;

	if(root->left == NULL) {

		struct tree_node *new_node = root->right;
		free(root);
		return new_node;
	}
	if(root->right == NULL) {
		struct tree_node *new_node = root->left;
		free(root);
		return new_node;
	}

}

/*

int _removeAllHalfNodes(struct tree_node *root, int *remove) {

	int lRemove;
	int rRemove;
	int lRet;
	int rRet;

	if(!root) {
		*remove = 1;
		return 0;
	}
	
	_removeAllHalfNodes(root,&lRemove):
	_removeAllHalfNodes(root,&rRemove);
	
	if(lRemove == 1 && rRemove == 1) {
		*remove = 1;
		return 0;
	}


}	
*/	
int removeAllHalfNodes(struct tree_node *root) {

	int remove = 0;
	_removeAllHalfNodes(root,&remove);

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
	
	removeAllHalfNodes(tree->root);

	printTree(tree);
	
	deleteTree(tree);
	return 0;
}
