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

int checkIdenticalTrees(struct tree_node *root1, struct tree_node *root2) {

	int ret1 = 0;
	//int ret2 = 0;

	if(root1 == NULL && root2 == NULL) 
		return 1;

	if(root1 == NULL || root2 == NULL)
		return 0;

	if(root1->data == root2->data) {
		
		ret1 = checkIdenticalTrees(root1->left,root2->left);
		if(ret1)
			ret1 = checkIdenticalTrees(root1->right,root2->right);
	}
	else 
		return 0;

	return (ret1);

}

int main() {

	struct tree_root *tree = createTree();
	struct tree_root *tree2 = createTree();
	if(!tree || !tree2) {
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

	tree2->root = createTreeNode(10);
	tree2->root->left = createTreeNode(20);
	tree2->root->right = createTreeNode(30);
	tree2->root->left->left = createTreeNode(40);
	tree2->root->left->right = createTreeNode(50);
	tree2->root->right->left = createTreeNode(60);
	tree2->root->right->right = createTreeNode(70);
	tree2->root->left->left->left = createTreeNode(80);

	printTree(tree2);

	if(checkIdenticalTrees(tree->root, tree2->root))
		printf("Trees are identical\n");
	else
		printf("Trees are not identical\n");


	return 0;
}
