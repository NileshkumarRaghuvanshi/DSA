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

	int ret =1;

	if(!root1 && !root2)
		return 1;

	if((!root1 && root2) || (root1 && !root2)) {
		printf("left and right are not matching\n");
		return 0;
	}


/*	ret = checkIfTwoTreesAreMirror(root1->right,root2->left);
	if(ret)
		ret = checkIfTwoTreesAreMirror(root1->left,root2->right);*/

	ret = checkIfTwoTreesAreMirror(root1->left,root2->right);
	if(ret)
		ret = checkIfTwoTreesAreMirror(root1->right,root2->left);


	return ret;

}


int foldableTree(struct tree_node *root) {


	if(!root)
		return 1;

	return checkIfTwoTreesAreMirror(root->left,root->right);

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
	//tree->root->left->right->right = createTreeNode(100);
	tree->root->right->right->right = createTreeNode(90);
	printTree(tree);


	if(foldableTree(tree->root))
		printf("Tree is foldable\n");
	else
		printf("Tree is not foldable\n");


	deleteTree(tree);

	return 0;
}
