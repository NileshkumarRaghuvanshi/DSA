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

void swapNodes(struct tree_node **node1, struct tree_node **node2) {

	struct tree_node *temp = *node1;
	*node1 = *node2;
	*node2 = temp;

}

swapNodeChildren(struct tree_node **root) {

	struct tree_node *temp = (*root)->left;
	(*root)->left = (*root)->right;
	(*root)->right = temp;
}

void getMirrorTree(struct tree_node **root) {

	if(*root)
		return;

	//swapNodes(&(root->left), &(root->right));

	//swapNodeChildren(root);
	//struct tree_node *temp = (*root)->left;
	//(*root)->left = (*root)->right;
	//(*root)->right = (*root)->left;

	getMirrorTree(&((*root)->left));
	getMirrorTree(&((*root)->right));
	
	swapNodeChildren(root);

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

	getMirrorTree(&(tree->root));

	printTree(tree);
	return 0;
}
