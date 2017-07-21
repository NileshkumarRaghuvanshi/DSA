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


struct tree_node *createTreeFromArray(int *parent, int size) {

	struct tree_node *nodes[size];
	int i=0;
	struct tree_node *root = NULL;

	for(i=0; i<size; i++) {
		nodes[i] = NULL;
	}

	for(i=0; i<size; i++) {

		struct tree_node *temp =createTreeNode(i);
		nodes[i] = temp;
	}

	for(i=0; i<size; i++) {

		if(parent[i] != -1) {
			
			if(!(nodes[parent[i]]->left)) {
				nodes[parent[i]]->left = nodes[i];
			}
			else {
				nodes[parent[i]]->right = nodes[i];
			}

		}
		else
			root = nodes[i];
	}

	return root;
}


int main() {


	int parent[] = {-1,0,0,1,1,3,5};
	int n = sizeof(parent)/sizeof(parent[0]);
	struct tree_node *root = createTreeFromArray(parent,n);

	_printTree(root);
	_deleteTree(root);

/*
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

	deleteTree(tree);

*/
	return 0;
}
