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
	
	int lHeight = 0;
	int rHeight = 0;
	if(!root)
		return 0;

	lHeight = getHeight(root->left);
	rHeight = getHeight(root->right);

	if(lHeight > rHeight) 
		return lHeight+1;
	else
		return rHeight+1;

	
}


void printLevel(struct tree_node *root, int level) {

	if(!root) return ;
	if(level == 0 && root) {
		printf("%d ",root->data);
		return;
	}
	
	printLevel(root->left, level-1);
	printLevel(root->right, level-1);


}


void printLevelOrder(struct tree_node *root) {

	int i =0;
	int height = getHeight(root);
	for(i=0;i<height;i++) {
		printLevel(root,i);
		printf("\n");
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
	tree->root->left->right = createTreeNode(50);
	tree->root->right->left = createTreeNode(60);
	tree->root->right->right = createTreeNode(70);
	tree->root->left->left->left = createTreeNode(80);

	printTree(tree);

	printf("Height is %d\n",getHeight(tree->root));

	printLevelOrder(tree->root);
	return 0;
}
