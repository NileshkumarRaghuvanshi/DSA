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


int checkIfTwoTreesAreEqual(struct tree_node *root1, struct tree_node *root2) {


	int ret = 0;
	if(!root1 && !root2)
		return 1;

	if((root1 && !root2) || (!root1 && root2))
		return 0;

	if(root1 && root2) {
		if(root1->data == root2->data) {
			ret = checkIfTwoTreesAreEqual(root1->left,root2->left);
			if(ret)
				ret = checkIfTwoTreesAreEqual(root1->right,root2->right);
		}
	}
	
	return ret;

}

struct tree_node *findNode(struct tree_node *root, int data) {

	struct tree_node *ret = NULL;
	if(!root)
		return NULL;

	if(root->data == data)
		return root;

	ret = findNode(root->left,data);
	if(!ret)
		ret = findNode(root->right,data);


	return ret;

}

int checkForSubtree(struct tree_node *root1, struct tree_node *root2) {


	if(!root1 || !root2)
		return 0;
	struct tree_node *temp = findNode(root1,root2->data);

	if(!temp) 
		return 0;

	return checkIfTwoTreesAreEqual(temp,root2);	

}


int main() {

	struct tree_root *tree = createTree();
	struct tree_root *tree1 = createTree();
	if(!tree && !tree1) {
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

	tree1->root = createTreeNode(20);
	tree1->root->left = createTreeNode(40);
	tree1->root->right = createTreeNode(50);
	tree1->root->left->left = createTreeNode(890);

	printTree(tree1);

	if(!checkForSubtree(tree->root,tree1->root))
		printf("Tree is not a subtree of other\n");
	else
		printf("Tree is subtree of other\n");



	deleteTree(tree);
	deleteTree(tree1);

	return 0;
}
