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


int checkIfTwoTreesAreMirror(struct tree_node *root1, struct tree_node *root2) {

	int ret = 1;

	if((root1 && !root2) || (!root1 && root2))
		return 0;

	if((!root1 && !root2))
		return 1;
	
	ret = checkIfTwoTreesAreMirror(root1->right,root2->left);
	ret = checkIfTwoTreesAreMirror(root1->left,root2->right);


	return ret;
}


int main() {

	struct tree_root *tree1 = createTree();
	struct tree_root *tree2 = createTree();

	if(!tree1 && !tree2) {
		printf("ERROR : creating tree root\n");
		return -1;
	}

	tree1->root = createTreeNode(10);
	tree1->root->left = createTreeNode(20);
	tree1->root->right = createTreeNode(30);
	tree1->root->left->left = createTreeNode(40);
	tree1->root->left->right = createTreeNode(50);
	tree1->root->right->left = createTreeNode(60);
	tree1->root->right->right = createTreeNode(70);
	tree1->root->left->left->left = createTreeNode(80);

	tree2->root = createTreeNode(10);
	tree2->root->left = createTreeNode(20);
	tree2->root->right = createTreeNode(30);
	tree2->root->left->left = createTreeNode(40);
	tree2->root->left->right = createTreeNode(50);
	tree2->root->right->left = createTreeNode(60);
	tree2->root->right->right = createTreeNode(70);
	tree2->root->right->right->right = createTreeNode(80);


	printTree(tree1);
	printTree(tree2);

	if(checkIfTwoTreesAreMirror(tree1->root,tree2->root)) 
		printf("Two trees are mirror\n");
	else
		printf("Two trees are not mirror\n");

	deleteTree(tree1);
	deleteTree(tree2);


	return 0;
}
